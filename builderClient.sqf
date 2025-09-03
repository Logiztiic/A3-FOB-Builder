if (!hasInterface) exitWith {};

fob_rotationStep = 0.50;
fob_elevationStep = 0.025;

fob_ghostObj = objNull;
fob_ghostAngle = 0;
fob_ghostHeightOffset = 0;
fob_buildConfirmed = false;
fob_buildCancelled = false;


fob_getAimPos = {
    private _screenCenter = [0.5, 0.5];
    private _aimPos = screenToWorld _screenCenter;

    if (!(_aimPos isEqualType [] && {count _aimPos == 3})) exitWith { [] };

    private _distance = player distance _aimPos;
    if (_distance > 20) exitWith { [] };

    _aimPos
};

fob_isEngineer = {
    (player getUnitTrait "engineer") || { typeOf player in ["B_engineer_F", "O_engineer_F", "I_engineer_F"] }
};

fob_cleanupGhost = {
    if (!isNull fob_ghostObj) then {
        deleteVehicle fob_ghostObj;
        fob_ghostObj = objNull;
    };
};

fob_createGhost = {
    params ["_class"];

    fob_ghostAngle = 0;
    fob_ghostHeightOffset = 0;

    if (!isNil "fob_ghostObj" && {!isNull fob_ghostObj}) then {
        deleteVehicle fob_ghostObj;
    };

    private _aimPos = [] call fob_getAimPos;
    if (count _aimPos == 0) exitWith {
	[format ["Too far to build — aim closer!", _cost]] remoteExec ["hint", player];
	
    };

    _aimPos set [2, (_aimPos select 2) + fob_ghostHeightOffset];

    fob_ghostObj = createVehicleLocal [_class, _aimPos, [], 0, "NONE"];
    fob_ghostObj setVectorUp surfaceNormal _aimPos;
    fob_ghostObj setDir fob_ghostAngle;
    fob_ghostObj allowDamage false;

    {
        fob_ghostObj setObjectTextureGlobal [_forEachIndex, "#(argb,8,8,3)color(0,1,1,0.3)"];
        fob_ghostObj setObjectMaterialGlobal [_forEachIndex, ""];
    } forEach getObjectTextures fob_ghostObj;

    fob_ghostObj enableSimulation false;
    fob_ghostObj setFeatureType 2;
    fob_ghostObj setCollisionLight false;
    fob_ghostObj disableCollisionWith player;
    fob_ghostObj disableCollisionWith vehicle player;
};

fob_confirmBuild = {
    params ["_class", "_cost"];

    private _itemType = "vn_prop_fort_mag";

    private _basePos = [] call fob_getAimPos;
    if (count _basePos == 0) exitWith {
	[format ["Too far to build — aim closer!", _cost]] remoteExec ["hint", player];
        [] call fob_cleanupGhost;
        false
    };

    private _finalPos = +_basePos;
    _finalPos set [2, (_finalPos select 2) + fob_ghostHeightOffset];

    [getPosASL player, _class, _cost, _itemType, _finalPos, fob_ghostAngle, surfaceNormal _finalPos, player] remoteExec ["fob_serverBuildHandler", 2];



    [] call fob_cleanupGhost;
    true
};

fob_startBuildFlow = {
    params ["_class", "_cost", "_otherclass"];

    fob_buildConfirmed = false;
    fob_buildCancelled = false;

    [_otherclass] call fob_createGhost;
    [] call fob_bindBuildControls;

    [format ["Use Q/E to rotate, R/F to raise/lower, SPACE to confirm, ESC to cancel.", _cost]] remoteExec ["hint", player];

    [_class, _cost] spawn {
        params ["_class", "_cost"];

        while { !isNull fob_ghostObj && !fob_buildConfirmed && !fob_buildCancelled } do {
            private _aimPos = [] call fob_getAimPos;
            if (count _aimPos == 0) then {
                fob_ghostObj hideObject true;
            } else {
                fob_ghostObj hideObject false;
                fob_ghostObj setPosATL [
                    (_aimPos select 0),
                    (_aimPos select 1),
                    (_aimPos select 2) + fob_ghostHeightOffset
                ];
                fob_ghostObj setDir fob_ghostAngle;
            };

            sleep 0.05;
        };

        if (fob_buildConfirmed) then {
            private _success = [_class, _cost] call fob_confirmBuild;
            if (!_success) then {
		[format ["Build failed.", _cost]] remoteExec ["hint", player];
            };
        } else {
            [] call fob_cleanupGhost;
	    [format ["Build cancelled.", _cost]] remoteExec ["hint", player];
        };
    };
};

fob_bindBuildControls = {
    waitUntil { !isNull findDisplay 46 };

    (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["_display", "_keyCode"];

        if (isNull fob_ghostObj) exitWith { false };

        switch (_keyCode) do {
            case 16: { fob_ghostAngle = fob_ghostAngle - fob_rotationStep }; // Q
            case 18: { fob_ghostAngle = fob_ghostAngle + fob_rotationStep }; // E
            case 19: { fob_ghostHeightOffset = fob_ghostHeightOffset + fob_elevationStep }; // R
            case 33: { fob_ghostHeightOffset = fob_ghostHeightOffset - fob_elevationStep }; // F
            case 57: { fob_buildConfirmed = true }; // SPACE
            case 1:  { fob_buildCancelled = true }; // ESC
        };

        false
    }];
};

fob_openBuildMenu = {
    if (!isNull findDisplay 9000) exitWith {};

    if (!call fob_isEngineer) exitWith {
        [format ["Only engineers can build FOB structures."]] remoteExec ["hint", player];
    };

    createDialog "FobMenuDialog";
};

fob_bindKeys = {
    waitUntil { !isNull findDisplay 46 };
    (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["_display", "_keyCode"];
        if (_keyCode isEqualTo 49) then {
            [] call fob_openBuildMenu;
        };
        false
    }];
};

missionNamespace setVariable ["fob_bindKeys", fob_bindKeys];

fob_tryRemoveFromInventory = {
    params ["_itemType", "_cost", "_playerID", "_class", "_finalPos", "_ghostAngle"];

    private _player = player;
    private _count = { _x == _itemType } count magazines _player;
    private _success = false;

    if (_count >= _cost) then {
        for "_i" from 1 to _cost do {
            _player removeMagazine _itemType;
        };
        _success = true;
    };

    [_success, _playerID, _class, _cost, _finalPos, _ghostAngle] remoteExec ["fob_continueBuildFromInventory", 2];
};

missionNamespace setVariable ["fob_tryRemoveFromInventory", fob_tryRemoveFromInventory];