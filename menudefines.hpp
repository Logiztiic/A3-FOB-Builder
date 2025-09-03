class RscText {
    type = 0;
    idc = -1;
    colorBackground[] = { 0, 0, 0, 0 };
    colorText[] = { 1, 1, 1, 1 };
    text = "";
    fixedWidth = 0;
    x = 0;
    y = 0;
    w = 0.3;
    h = 0.05;
    style = 0;
    shadow = 1;
    font = "PuristaMedium";
    sizeEx = 0.04;
};

class RscButton {
    type = 1;
    text = "";
    colorText[] = { 1, 1, 1, 1 };
    colorDisabled[] = { 0.4, 0.4, 0.4, 1 };
    colorBackground[] = { 0.2, 0.2, 0.2, 1 };
    colorBackgroundDisabled[] = { 0.2, 0.2, 0.2, 0.5 };
    colorBackgroundActive[] = { 0.3, 0.3, 0.3, 1 };
    colorFocused[] = { 0.3, 0.3, 0.3, 1 };
    colorShadow[] = { 0, 0, 0, 1 };
    colorBorder[] = { 0, 0, 0, 1 };
    soundEnter[] = { "", 0.09, 1 };
    soundPush[] = { "", 0.09, 1 };
    soundClick[] = { "", 0.09, 1 };
    soundEscape[] = { "", 0.09, 1 };
    style = 2;
    x = 0;
    y = 0;
    w = 0.3;
    h = 0.05;
    shadow = 2;
    font = "PuristaMedium";
    sizeEx = 0.035;
    offsetX = 0.003;
    offsetY = 0.003;
    offsetPressedX = 0.002;
    offsetPressedY = 0.002;
    borderSize = 0;
};

class FobMenuDialog {
    idd = 9000;
    movingEnable = false;
    enableSimulation = true;

    class controlsBackground {
        class Background : RscText {
            idc = -1;
            x = -0.3;
            y = -0.3;
            w = 1.4;
            h = 1.4;
            colorBackground[] = { 0,0,0,0.7 };
        };
    };

    class controls {
        class Title : RscText {
            idc = -1;
            text = "Select a Structure to Build";
            x = -0.3; y = -0.3;
            w = 0.6; h = 0.05;
        };

        #define BUTTON_WIDTH 0.30
        #define BUTTON_HEIGHT 0.07
        #define BUTTON_SPACING_X 0.02
        #define BUTTON_SPACING_Y 0.015
        #define START_X -0.25
        #define START_Y -0.18


        class Option1 : RscButton {
            idc = 9001;
            text = "Trench Stairs Sandbags (5)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (0 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_stair_01', 5, 'vn_b_trench_stair_01_part0'] call fob_startBuildFlow;";
        };

        class Option2 : RscButton {
            idc = 9002;
            text = "5m 1/2 Trench Reinforced (5)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (1 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_05_02', 5, 'vn_b_trench_05_02_part0'] call fob_startBuildFlow;";
        };

        class Option3 : RscButton {
            idc = 9003;
            text = "20m Trench Reinforced (12)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (2 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_20_01', 12, 'vn_b_trench_20_01_part0'] call fob_startBuildFlow;";
        };

        class Option4 : RscButton {
            idc = 9004;
            text = "Mortar Pit Small (6)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (3 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_mortarpit_01', 6, 'vn_b_mortarpit_01_part0'] call fob_startBuildFlow;";
        };

        class Option5 : RscButton {
            idc = 9005;
            text = "Big Bunker Empty (25)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (4 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_bunker_03_01', 25, 'vn_b_trench_bunker_03_01_part0'] call fob_startBuildFlow;";
        };

        class Option6 : RscButton {
            idc = 9006;
            text = "Med Bunker Troops (16)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (5 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_bunker_01_03', 16, 'vn_b_trench_bunker_01_03_part0'] call fob_startBuildFlow;";
        };

        class Option7 : RscButton {
            idc = 9007;
            text = "5m Trench Covered (6)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (6 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_05_03', 6, 'vn_b_trench_05_03_part0'] call fob_startBuildFlow;";
        };

        class Option8 : RscButton {
            idc = 9008;
            text = "Big GunPit (30)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (7 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_gunpit_01', 30, 'vn_b_gunpit_01_part0'] call fob_startBuildFlow;";
        };

        class Option9 : RscButton {
            idc = 9009;
            text = "Big Trench Bunker (45)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (8 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_bunker_04_01', 45, 'vn_b_trench_bunker_04_01_part0'] call fob_startBuildFlow;";
        };

        class Option10 : RscButton {
            idc = 9010;
            text = "10m Trench 45° (10)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (9 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_45_01', 10, 'vn_b_trench_45_01_part0'] call fob_startBuildFlow;";
        };

        class Option11 : RscButton {
            idc = 9011;
            text = "10m 1/2 Trench 45° (5)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (0 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_45_02', 5, 'vn_b_trench_45_02_part0'] call fob_startBuildFlow;";
        };

        class Option12 : RscButton {
            idc = 9012;
            text = "Trench End MG (12)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (1 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_firing_05', 12, 'vn_b_trench_firing_05_part0'] call fob_startBuildFlow;";
        };

        class Option13 : RscButton {
            idc = 9013;
            text = "5m Trench Reinforced (10)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (2 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_05_01', 10, 'vn_b_trench_05_01_part0'] call fob_startBuildFlow;";
        };

        class Option14 : RscButton {
            idc = 9014;
            text = "10m Trench 90° (16)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (3 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_90_01', 16, 'vn_b_trench_90_01_part0'] call fob_startBuildFlow;";
        };

        class Option15 : RscButton {
            idc = 9015;
            text = "10m 1/2 Trench 90° (8)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (4 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_90_02', 8, 'vn_b_trench_90_02_part0'] call fob_startBuildFlow;";
        };

        class Option16 : RscButton {
            idc = 9016;
            text = "Trench Cross Section (25)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (5 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_cross_01', 25, 'vn_b_trench_cross_01_part0'] call fob_startBuildFlow;";
        };

        class Option17 : RscButton {
            idc = 9017;
            text = "Trench 1/2 Cross Section (13)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (6 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_cross_02', 13, 'vn_b_trench_cross_02_part0'] call fob_startBuildFlow;";
        };

        class Option18 : RscButton {
            idc = 9018;
            text = "Trench OP (25)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (7 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_firing_01', 25, 'vn_b_trench_firing_01_part0'] call fob_startBuildFlow;";
        };

        class Option19 : RscButton {
            idc = 9019;
            text = "Trench Open End (5)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (8 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_end_01', 5, 'vn_b_trench_end_01_part0'] call fob_startBuildFlow;";
        };

        class Option20 : RscButton {
            idc = 9020;
            text = "Wooden Tower Sandbags (35)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (9 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_tower_01', 35, 'vn_b_tower_01_part0'] call fob_startBuildFlow;";
        };

        class Option21 : RscButton {
            idc = 9021;
            text = "Trench Stairs Earth (5)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (0 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_stair_02', 5, '	vn_b_trench_stair_02_part0'] call fob_startBuildFlow;";
        };

        class Option22 : RscButton {
            idc = 9022;
            text = "Trench T Shape (20)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (1 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_tee_01', 20, 'vn_b_trench_tee_01_part0'] call fob_startBuildFlow;";
        };

        class Option23 : RscButton {
            idc = 9023;
            text = "Trench End LP (16)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (2 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_firing_04', 16, 'vn_b_trench_firing_04_part0'] call fob_startBuildFlow;";
        };

        class Option24 : RscButton {
            idc = 9024;
            text = "5m Reinforced Wall (6)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (3 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_revetment_05_01', 6, 'vn_b_trench_revetment_05_01_part0'] call fob_startBuildFlow;";
        };

        class Option25 : RscButton {
            idc = 9025;
            text = "9m Barrel Wall (18)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (4 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_revetment_tall_09', 18, 'vn_b_trench_revetment_tall_09_part0'] call fob_startBuildFlow;";
        };

        class Option26 : RscButton {
            idc = 9026;
            text = "PSP HeliPad (25)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (5 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_helipad_01', 25, 'vn_b_helipad_01_part0'] call fob_startBuildFlow;";
        };

        class Option27 : RscButton {
            idc = 9027;
            text = "10m Block PSP (15)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (6 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_wall_10_03', 15, 'vn_b_trench_wall_10_03_part0'] call fob_startBuildFlow;";
        };

        class Option28 : RscButton {
            idc = 9028;
            text = "10m Block Sandbags (15)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (7 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_wall_10_02', 15, 'vn_b_trench_wall_10_02_part0'] call fob_startBuildFlow;";
        };

        class Option29 : RscButton {
            idc = 9029;
            text = "10m Block Crates (15)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (8 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_wall_10_01', 15, 'vn_b_trench_wall_10_01_part0'] call fob_startBuildFlow;";
        };

        class Option30 : RscButton {
            idc = 9030;
            text = "5m Block Sandbags (10)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (9 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_wall_05_02', 10, 'vn_b_trench_wall_05_02_part0'] call fob_startBuildFlow;";
        };

        class Option31 : RscButton {
            idc = 9031;
            text = "5m Block PSP (10)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (0 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_wall_05_03', 10, 'vn_b_trench_wall_05_03_part0'] call fob_startBuildFlow;";
        };

        class Option32 : RscButton {
            idc = 9032;
            text = "5m Block Crates (10)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (1 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_wall_03_01', 10, 'vn_b_trench_wall_03_01_part0'] call fob_startBuildFlow;";
        };

        class Option33 : RscButton {
            idc = 9033;
            text = "1m Block PSP (5)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (2 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_wall_01_03', 5, 'vn_b_trench_wall_01_03_part0'] call fob_startBuildFlow;";
        };

        class Option34 : RscButton {
            idc = 9034;
            text = "1m Block Crates (5)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (3 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_wall_01_01', 5, 'vn_b_trench_wall_01_01_part0'] call fob_startBuildFlow;";
        };

        class Option35 : RscButton {
            idc = 9035;
            text = "1m Block Sandbags (5)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (4 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_wall_01_02', 5, 'vn_b_trench_wall_01_02_part0'] call fob_startBuildFlow;";
        };

        class Option36 : RscButton {
            idc = 9036;
            text = "Big Bunker Stores (35)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (5 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_bunker_02_02', 35, 'vn_b_trench_bunker_02_02_part0'] call fob_startBuildFlow;";
        };

        class Option37 : RscButton {
            idc = 9037;
            text = "Big Bunker Troops 2 (40)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (6 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_bunker_03_04', 40, 'vn_b_trench_bunker_03_04_part0'] call fob_startBuildFlow;";
        };

        class Option38 : RscButton {
            idc = 9038;
            text = "Sandbag Bunker Nest (25)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (7 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_bunker_small_01', 25, 'vn_bunker_small_01_part0'] call fob_startBuildFlow;";
        };

        class Option39 : RscButton {
            idc = 9039;
            text = "5m Sentry Trench (15)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (8 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_firing_03', 15, 'vn_b_trench_firing_03_part0'] call fob_startBuildFlow;";
        };

        class Option40 : RscButton {
            idc = 9040;
            text = "HedgeHog Fortification (25)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (9 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_czechhedgehog_01_f', 25, 'vn_czechhedgehog_01_f_part0'] call fob_startBuildFlow;";
        };

        class Option41 : RscButton {
            idc = 9041;
            text = "20m Bailey Bridge (75)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (10 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_bridge_bailey_02', 75, 'vn_bridge_bailey_02_part0'] call fob_startBuildFlow;";
        };

        class Option42 : RscButton {
            idc = 9042;
            text = "1 Man Bunker (15)";
            x = START_X + (0 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (11 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_bunker_05_01', 15, 'vn_b_trench_bunker_05_01_part0'] call fob_startBuildFlow;";
        };

        class Option43 : RscButton {
            idc = 9043;
            text = "2 Man Tent (12)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (10 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_bunker_06_01', 12, 'vn_b_trench_bunker_06_01_part0'] call fob_startBuildFlow;";
        };

        class Option44 : RscButton {
            idc = 9044;
            text = "3m Barrel Wall (8)";
            x = START_X + (1 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (11 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_b_trench_revetment_tall_03', 8, 'vn_b_trench_revetment_tall_03_part0'] call fob_startBuildFlow;";
        };

        class Option45 : RscButton {
            idc = 9045;
            text = "Mine Warning Sign (3)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (10 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_sign_mines_f', 3, 'Land_vn_sign_mines_f'] call fob_startBuildFlow;";
        };

        class Option46 : RscButton {
            idc = 9046;
            text = "Canvas Medical Tent (25)";
            x = START_X + (2 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (11 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['Land_vn_tent_mash_01_03', 25, 'vn_tent_mash_01_part0'] call fob_startBuildFlow;";
        };

        class Option47 : RscButton {
            idc = 9047;
            text = "US Flagpole (8)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (10 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['vn_flag_usa_dmg', 8, 'vn_mast_01_part0'] call fob_startBuildFlow;";
        };

        class Option48 : RscButton {
            idc = 9048;
            text = "NVA Skull Trophy (4)";
            x = START_X + (3 * (BUTTON_WIDTH + BUTTON_SPACING_X));
            y = START_Y + (11 * (BUTTON_HEIGHT + BUTTON_SPACING_Y));
            w = BUTTON_WIDTH; h = BUTTON_HEIGHT;
            action = "closeDialog 0; ['vn_sign_skull_02_f', 4, 'vn_sign_skull_02_f'] call fob_startBuildFlow;";
        };
    };
};