#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "level_caps.h"
#include "pokemon.h"


u32 GetCurrentLevelCap(void)
{
    static const u32 sLevelCapFlagMap[][2] =
    {
        {FLAG_DEFEATED_RIVAL_ROUTE103, 6},
        {FLAG_DEFEATED_PETALBURG_GRUNT, 10},
        {FLAG_BADGE01_GET, 15},
        {FLAG_DEFEATED_RIVAL_RUSTBORO, 17},
        {FLAG_BADGE02_GET, 19},
        {FLAG_DEFEATED_RIVAL_ROUTE110, 23},
        {FLAG_BADGE03_GET, 26},
        {FLAG_LANDMARK_FIERY_PATH, 28},
        {FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, 31},
        {FLAG_BADGE04_GET, 33},
        {FLAG_BADGE05_GET, 36},
        {FLAG_DEFEATED_RIVAL_ROUTE119, 40},
        {FLAG_BADGE06_GET, 42},
        {FLAG_DEFEATED_RIVAL_LILYCOVE, 46},
        {FLAG_BADGE07_GET, 49},
        {FLAG_DEFEATED_ARCHIE, 51},
        {FLAG_BADGE08_GET, 54},
        {FLAG_DEFEATED_WALLY_VICTORY_ROAD, 55},
        {FLAG_DEFEATED_ELITE_4_GLACIA, 58},
        {FLAG_IS_CHAMPION, 60},
    };

    u32 i;

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return MAX_LEVEL;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (level < currentLevelCap)
    {
        if (B_LEVEL_CAP_EXP_UP)
        {
            levelDifference = currentLevelCap - level;
            if (levelDifference > ARRAY_COUNT(sExpScalingUp))
                return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingUp) - 1]);
            else
                return expValue + (expValue / sExpScalingUp[levelDifference]);
        }
        else
        {
            return expValue;
        }
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_HARD)
    {
        return 0;
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown))
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
    {
       return expValue;
    }
}
