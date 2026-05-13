#pragma once
#include "LevelConfig.h"

inline QList<SceneryObject> buildLevel1Scenery() {
    return {
        { SceneryType::SUNKEN_SHIP,  { 400,  900  }, 1, 0 },
        { SceneryType::SUNKEN_SHIP,  { 1600, 500  }, 1, 0 },
        { SceneryType::RUIN_PILLAR,  { 700,  800  }, 120, 0 },
        { SceneryType::RUIN_PILLAR,  { 760,  820  }, 80,  0 },
        { SceneryType::CORAL,        { 600,  950  }, 0,   0 },
        { SceneryType::CORAL,        { 650,  970  }, 0,   1 },
        { SceneryType::CORAL,        { 1000, 1100 }, 0,   2 },
        { SceneryType::ROCK,         { 300,  1000 }, 60,  0 },
        { SceneryType::ROCK,         { 1100, 700  }, 45,  0 },
        { SceneryType::SEAWEED,      { 450,  1050 }, 80,  0 },
        { SceneryType::SEAWEED,      { 480,  1040 }, 60,  0 },
    };
}

inline QList<SceneryObject> buildLevel2Scenery() {
    return {
        { SceneryType::SUNKEN_SHIP,  { 500,  700  }, 1, 0 },
        { SceneryType::SUNKEN_SHIP,  { 1800, 900  }, 1, 0 },
        { SceneryType::RUIN_PILLAR,  { 900,  600  }, 140, 0 },
        { SceneryType::RUIN_PILLAR,  { 960,  580  }, 100, 0 },
        { SceneryType::RUIN_PILLAR,  { 1400, 800  }, 160, 0 },
        { SceneryType::RUIN_PILLAR,  { 1460, 820  }, 90,  0 },
        { SceneryType::RUIN_PILLAR,  { 2000, 500  }, 130, 0 },
        { SceneryType::CORAL,        { 700,  800  }, 0,   3 },
        { SceneryType::CORAL,        { 1200, 1000 }, 0,   1 },
        { SceneryType::ROCK,         { 600,  1100 }, 70,  0 },
        { SceneryType::ROCK,         { 1600, 600  }, 50,  0 },
        { SceneryType::SEAWEED,      { 800,  900  }, 100, 0 },
        { SceneryType::SEAWEED,      { 1700, 1100 }, 80,  0 },
    };
}

inline QList<SceneryObject> buildLevel3Scenery() {
    return {
        { SceneryType::SUNKEN_SHIP,  { 600,  1100 }, 1,  0 },
        { SceneryType::SUNKEN_SHIP,  { 2000, 800  }, 1,  0 },
        { SceneryType::SUNKEN_SHIP,  { 1200, 1400 }, 1,  0 },
        { SceneryType::RUIN_PILLAR,  { 800,  900  }, 180, 0 },
        { SceneryType::RUIN_PILLAR,  { 860,  880  }, 140, 0 },
        { SceneryType::RUIN_PILLAR,  { 920,  920  }, 200, 0 },
        { SceneryType::RUIN_PILLAR,  { 1600, 700  }, 160, 0 },
        { SceneryType::RUIN_PILLAR,  { 2200, 1200 }, 180, 0 },
        { SceneryType::ROCK,         { 400,  1300 }, 80,  0 },
        { SceneryType::ROCK,         { 1400, 1000 }, 90,  0 },
        { SceneryType::ROCK,         { 2100, 900  }, 75,  0 },
        { SceneryType::CORAL,        { 500,  1200 }, 0,   4 },
        { SceneryType::CORAL,        { 1800, 1300 }, 0,   2 },
        { SceneryType::SEAWEED,      { 700,  1400 }, 120, 0 },
        { SceneryType::SEAWEED,      { 1500, 1100 }, 90,  0 },
    };
}




inline LevelConfig getLevel(int number) {

    if (number == 1) {
        LevelConfig l;
        l.levelNumber    = 1;
        l.levelName      = "The Sunken Reef";
        l.introText      = "A merchant vessel vanished here decades ago.\n"
                           "Local fishermen refuse to drop their nets.\n"
                           "You are the first to go down.\n\n"
                           "Oxygen: 100%    Torch: wide    Sharks: none";
        l.mapWidth       = 2000;
        l.mapHeight      = 1400;
        l.oxygenDrainRate = 1.5f;
        l.torchRadius    = 180;
        l.numSharks      = 0;
        l.playerStartPos = { 1000, 700 };

        l.hints = {
            { {300,  400},
              "A sailor's compass always points to what was lost.\n"
              "Start where the anchor chain ends." },

            { {800,  700},
              "The fish avoid one rock — not from fear, from habit.\n"
              "Look beneath the one covered in bite marks." },

            { {1400, 500},
              "Carved into coral, a single arrow.\n"
              "It was not made by any sea creature." },

            { {1700, 1100},
              "You found it. They hid it well.\n"
              "But not well enough.",
              true }   // treasure
        };

        l.scenery = buildLevel1Scenery();
        return l;
    }

    if (number == 2) {
        LevelConfig l;
        l.levelNumber    = 2;
        l.levelName      = "The Drowned City";
        l.introText      = "An entire city swallowed by the sea overnight.\n"
                           "No warning. No survivors.\n"
                           "The treasure was locked in the mayor's vault.\n\n"
                           "Oxygen: 100%    Torch: medium    Sharks: 1";
        l.mapWidth       = 2400;
        l.mapHeight      = 1600;
        l.oxygenDrainRate = 2.5f;
        l.torchRadius    = 140;
        l.numSharks      = 1;
        l.playerStartPos = { 1200, 800 };

        l.hints = {
            { {400,  500},
              "The clock tower stopped at 3:17.\n"
              "Every clock in the city shows the same time.\n"
              "The tower is north. Go there." },

            { {900,  400},
              "Every building has a door facing the street.\n"
              "One door faces the wrong way.\n"
              "That one was locked from the inside." },

            { {1500, 700},
              "The library. The books rotted.\n"
              "The map painted on the eastern wall did not.\n"
              "It still points somewhere." },

            { {2000, 1100},
              "The mayor's office. Third floor.\n"
              "He never made it out.\n"
              "Neither did his key." },

            { {2100, 1400},
              "The vault is open. Already looted.\n"
              "But they missed the floor.\n"
              "They always miss the floor.",
              true }   // treasure
        };

        l.scenery = buildLevel2Scenery();
        return l;
    }


    {
        LevelConfig l;
        l.levelNumber    = 2;
        l.levelName      = "The Deep Trench";
        l.introText      = "No expedition has returned from this depth.\n"
                           "The last team left one transmission:\n"
                           "\"It was already here when we arrived.\"\n\n"
                           "Oxygen: 100%    Torch: narrow    Sharks: 2";
        l.mapWidth       = 2800;
        l.mapHeight      = 2000;
        l.oxygenDrainRate = 3.5f;
        l.torchRadius    = 110;
        l.numSharks      = 2;
        l.playerStartPos = { 1400, 1000 };

        l.hints = {
            { {500,  600},
              "Nothing lives at this depth.\n"
              "Nothing natural, anyway.\n"
              "Follow the light that has no source." },

            { {1000, 900},
              "The pressure bends sound here.\n"
              "What you hear behind you is not behind you.\n"
              "It never was." },

            { {1600, 1200},
              "Three machines. Only one was ever turned off.\n"
              "Find the one that still hums.\n"
              "It hums because something is still inside." },

            { {2200, 800},
              "The captain's log ends mid-sentence.\n"
              "The last word is a coordinate.\n"
              "You are already standing on it." },

            { {1800, 1600},
              "The coordinate leads here.\n"
              "They built something at the bottom of the trench\n"
              "long before any of us arrived." },

            { {2400, 1800},
              "It was never treasure.\n"
              "It was a message left for whoever was brave enough.\n"
              "The gold that sealed the message is yours.",
              true }   // treasure
        };

        l.scenery = buildLevel3Scenery();
        return l;
    }
}
