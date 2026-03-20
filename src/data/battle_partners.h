//
// DO NOT MODIFY THIS FILE! It is auto-generated from src/data/battle_partners.party
//
// If you want to modify this file set COMPETITIVE_PARTY_SYNTAX to FALSE
// in include/config/general.h and remove this notice.
// Use sed -i '/^#line/d' 'src/data/battle_partners.h' to remove #line markers.
//

#line 1 "src/data/battle_partners.party"

#line 1
    [PARTNER_NONE] =
    {
#line 3
        .trainerClass = TRAINER_CLASS_PKMN_TRAINER_1,
#line 4
        .trainerPic = TRAINER_BACK_PIC_BRENDAN,
        .encounterMusic_gender = 
#line 6
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 0,
        .party = (const struct TrainerMon[])
        {
        },
    },
#line 8
    [PARTNER_STEVEN] =
    {
#line 9
        .trainerName = _("STEVEN"),
#line 10
        .trainerClass = TRAINER_CLASS_RIVAL,
#line 11
        .trainerPic = TRAINER_BACK_PIC_STEVEN,
        .encounterMusic_gender = 
#line 13
            TRAINER_ENCOUNTER_MUSIC_MALE,
        .partySize = 3,
        .party = (const struct TrainerMon[])
        {
            {
#line 15
            .species = SPECIES_METAGROSS,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 19
            .ev = TRAINER_PARTY_EVS(85, 85, 85, 85, 85, 85),
#line 18
            .iv = TRAINER_PARTY_IVS(29, 29, 29, 29, 29, 29),
#line 17
            .lvl = 65,
#line 16
            .nature = NATURE_BRAVE,
#line 20
            .dynamaxLevel = 0,
            .shouldUseDynamax = TRUE,
            .moves = {
#line 21
                MOVE_IRON_DEFENSE,
                MOVE_ZEN_HEADBUTT,
                MOVE_BODY_PRESS,
                MOVE_METEOR_MASH,
            },
            },
            {
#line 26
            .species = SPECIES_SKARMORY,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 30
            .ev = TRAINER_PARTY_EVS(85, 85, 85, 85, 85, 85),
#line 29
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 28
            .lvl = 64,
#line 27
            .nature = NATURE_IMPISH,
#line 31
            .dynamaxLevel = 0,
            .shouldUseDynamax = TRUE,
            .moves = {
#line 32
                MOVE_ROOST,
                MOVE_BRAVE_BIRD,
                MOVE_BODY_PRESS,
                MOVE_STEEL_WING,
            },
            },
            {
#line 37
            .species = SPECIES_AGGRON,
            .gender = TRAINER_MON_RANDOM_GENDER,
#line 41
            .ev = TRAINER_PARTY_EVS(85, 85, 85, 85, 85, 85),
#line 40
            .iv = TRAINER_PARTY_IVS(25, 25, 25, 25, 25, 25),
#line 39
            .lvl = 64,
#line 38
            .nature = NATURE_ADAMANT,
#line 42
            .dynamaxLevel = 0,
            .shouldUseDynamax = TRUE,
            .moves = {
#line 43
                MOVE_IRON_DEFENSE,
                MOVE_BODY_PRESS,
                MOVE_IRON_HEAD,
                MOVE_HEAD_SMASH,
            },
            },
        },
    },
