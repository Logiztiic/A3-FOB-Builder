fob_removeMagazines = {
    params ["_crate", "_magType", "_count"];

    private _cargo = magazineCargo _crate;
    private _remaining = _count;
    private _filtered = [];

    {
        if (_x == _magType && _remaining > 0) then {
            _remaining = _remaining - 1;
        } else {
            _filtered pushBack _x;
        };
    } forEach _cargo;

    private _unique = [];
    private _counts = [];

    {
        private _index = _unique find _x;
        if (_index == -1) then {
            _unique pushBack _x;
            _counts pushBack 1;
        } else {
            _counts set [_index, (_counts select _index) + 1];
        };
    } forEach _filtered;

    clearMagazineCargoGlobal _crate;

    for "_i" from 0 to (count _unique - 1) do {
        _crate addMagazineCargoGlobal [_unique select _i, _counts select _i];
    };
};

fob_finalizeBuild = {
    params ["_class", "_cost", "_finalPos", "_ghostAngle", "_playerID", "_source"];

    private _obj = createVehicle [_class, _finalPos, [], 0, "CAN_COLLIDE"];
    if (isNull _obj) exitWith {
        [format ["Object creation failed."]] remoteExec ["hint", _playerID];
    };

    _obj setPosATL _finalPos;
    _obj setDir _ghostAngle;
    _obj setVectorUp [0, 0, 1];
    _obj setOwner 2;

    [format ["Built %1 using %2 supplies (%3)", _class, _cost, _source]] remoteExec ["hint", _playerID];
};

fob_continueBuildFromInventory = {
    params ["_success", "_playerID", "_class", "_cost", "_finalPos", "_ghostAngle"];

    if (!_success) exitWith {
        ["No sandbags in crate or inventory."] remoteExec ["hint", _playerID];
    };

    [_class, _cost, _finalPos, _ghostAngle, _playerID, "inventory"] call fob_finalizeBuild;
};

missionNamespace setVariable ["fob_continueBuildFromInventory", fob_continueBuildFromInventory];

fob_serverBuildHandler = {
    params ["_playerPos", "_class", "_cost", "_itemType", "_finalPos", "_ghostAngle", "_playerID"];

    [_playerPos, _class, _cost, _itemType, _finalPos, _ghostAngle, _playerID] spawn {
        params ["_playerPos", "_class", "_cost", "_itemType", "_finalPos", "_ghostAngle", "_playerID"];

        private _crateTypes = [
            "vn_b_ammobox_supply_10",
            "vn_b_ammobox_06"
        ];

        private _crateArray = nearestObjects [_playerPos, _crateTypes, 40];
        private _crate = objNull;
        private _usedCrate = false;

        {
            private _magCount = { _x == _itemType } count magazineCargo _x;
            if (_magCount >= _cost) exitWith {
                _crate = _x;
                [_crate, _itemType, _cost] remoteExec ["fob_removeMagazines", 2];
                _usedCrate = true;
            };
        } forEach _crateArray;

        if (_usedCrate) then {
            [_class, _cost, _finalPos, _ghostAngle, _playerID, "crate"] call fob_finalizeBuild;
        } else {
            [_itemType, _cost, _playerID, _class, _finalPos, _ghostAngle] remoteExec ["fob_tryRemoveFromInventory", _playerID];
        };
    };
};

missionNamespace setVariable ["fob_serverBuildHandler", fob_serverBuildHandler];
