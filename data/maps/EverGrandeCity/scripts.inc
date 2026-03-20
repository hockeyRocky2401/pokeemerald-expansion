.set LOCALID_MAY_ENTRANCE, 2

EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_EventScript_MayBattleTrigger1::
	lockall
	setvar VAR_TEMP_1, 1
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_MAY
	playbgm MUS_ENCOUNTER_MAY, TRUE
	addobject LOCALID_MAY_ENTRANCE
	applymovement LOCALID_MAY_ENTRANCE, EverGrandeCity_Movement_MayApproachPlayer1
	waitmovement 0
	goto EverGrandeCity_EventScript_MayEntranceBattle
	end

EverGrandeCity_EventScript_MayBattleTrigger2::
	lockall
	setvar VAR_TEMP_1, 2
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_MAY
	playbgm MUS_ENCOUNTER_MAY, TRUE
	addobject LOCALID_MAY_ENTRANCE
	applymovement LOCALID_MAY_ENTRANCE, EverGrandeCity_Movement_MayApproachPlayer2
	waitmovement 0
	goto EverGrandeCity_EventScript_MayEntranceBattle
	end

EverGrandeCity_EventScript_MayEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_Text_MayIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAY_VR, EverGrandeCity_Text_MayEntranceDefeat
	msgbox EverGrandeCity_Text_MayPostEntranceBattle, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DEFEATED_MAY_VICTORY_ROAD
	applymovement LOCALID_MAY_ENTRANCE, EverGrandeCity_Movement_MayLeaves
	waitmovement 0
	savebgm MUS_DUMMY
	fadedefaultbgm
	removeobject LOCALID_MAY_ENTRANCE
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_MAY
	setvar VAR_EVER_GRANDE_CITY_STATE, 1	
	releaseall
	end

EverGrandeCity_Movement_MayApproachPlayer1:
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

EverGrandeCity_Movement_MayApproachPlayer2:
    walk_left
    walk_up
    walk_up
    walk_up
    walk_up
    walk_up
    step_end

EverGrandeCity_Movement_MayLeaves:
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    walk_down
    step_end

EverGrandeCity_EventScript_GiveTeam::
    lock
    faceplayer
	msgbox EverGrandeCity_Text_GiveTeam, MSGBOX_DEFAULT
    givemon SPECIES_SKARMORY, 57, ITEM_ROCKY_HELMET, , , , , , , , , , , , , , , , , MOVE_BRAVE_BIRD, MOVE_ROOST, MOVE_SPIKES, MOVE_STEEL_WING
    givemon SPECIES_AGGRON, 57, ITEM_SMOOTH_ROCK, , , , , , , , , , , , , , , , , MOVE_SANDSTORM, MOVE_HEAD_SMASH, MOVE_BODY_PRESS, MOVE_IRON_HEAD
    givemon SPECIES_CRADILY, 57, ITEM_LEFTOVERS, , , , , , , , , , , , , , , , , MOVE_GIGA_DRAIN, MOVE_POWER_GEM, MOVE_STEALTH_ROCK, MOVE_RECOVER
    givemon SPECIES_ARMALDO, 57, ITEM_ASSAULT_VEST, , , , , , , , , , , , , , , , , MOVE_PIN_MISSILE, MOVE_ROCK_BLAST, MOVE_LIQUIDATION, MOVE_RAPID_SPIN
    givemon SPECIES_METAGROSS, 57, ITEM_WEAKNESS_POLICY, , , , , , , , , , , , , , , , , MOVE_EARTHQUAKE, MOVE_THUNDER_PUNCH, MOVE_METEOR_MASH, MOVE_BULLET_PUNCH
    givemon SPECIES_TERRAKION, 58, ITEM_SITRUS_BERRY, , , , , , , , , , , , , , , , , MOVE_MIGHTY_CLEAVE, MOVE_SACRED_SWORD, MOVE_EARTHQUAKE, MOVE_ZEN_HEADBUTT
	
	giveitem ITEM_ABILITY_CAPSULE, 6
    giveitem ITEM_ABILITY_PATCH, 6
    giveitem ITEM_RARE_CANDY, 100
    giveitem ITEM_HM01, 1
    giveitem ITEM_HM02, 1
    giveitem ITEM_HM03, 1
    giveitem ITEM_HM04, 1
    giveitem ITEM_HM05, 1
    giveitem ITEM_HM06, 1
    giveitem ITEM_HM07, 1
    giveitem ITEM_HM08, 1
	msgbox EverGrandeCity_Text_GiveTeamReceived, MSGBOX_DEFAULT
	release 
	end
	

/*
	EverGrandeCity_EventScript_GiveTeam::
    lock
    faceplayer
    msgbox EverGrandeCity_Text_GiveTeam, MSGBOX_DEFAULT

    givemon SPECIES_CYCLIZAR, 57, ITEM_HEAVY_DUTY_BOOTS, , , , , , , , , , , , , , , , , MOVE_SHED_TAIL, MOVE_DRAGON_CLAW, MOVE_RAPID_SPIN, MOVE_KNOCK_OFF
    givemon SPECIES_FLYGON, 57, ITEM_CHOICE_SCARF, , , , , , , , , , , , , , , , , MOVE_U_TURN, MOVE_SUPERPOWER, MOVE_DRAGON_CLAW, MOVE_EARTHQUAKE
    givemon SPECIES_DRAGALGE, 57, ITEM_BLACK_SLUDGE, , , , , , , , , , , , , , , , , MOVE_TOXIC_SPIKES, MOVE_SLUDGE_BOMB, MOVE_DRACO_METEOR, MOVE_FLIP_TURN
    givemon SPECIES_ALTARIA, 57, ITEM_LEFTOVERS, , , , , , , , , , , , , , , , , MOVE_MOONBLAST, MOVE_DRACO_METEOR, MOVE_CALM_MIND, MOVE_FLAMETHROWER
    givemon SPECIES_KINGDRA, 57, ITEM_CHOICE_SPECS, , , , , , , , , , , , , , , , , MOVE_ICE_BEAM, MOVE_DRACO_METEOR, MOVE_HYDRO_PUMP, MOVE_FLIP_TURN
    givemon SPECIES_SALAMENCE, 58, ITEM_SITRUS_BERRY, , , , , , , , , , , , , , , , , MOVE_EARTHQUAKE, MOVE_DRAGON_CLAW, MOVE_DRAGON_DANCE, MOVE_DUAL_WINGBEAT

    giveitem ITEM_ABILITY_CAPSULE, 6
    giveitem ITEM_ABILITY_PATCH, 6
    giveitem ITEM_RARE_CANDY, 100

    msgbox EverGrandeCity_Text_GiveTeamReceived, MSGBOX_DEFAULT
    release
    end
    

    EverGrandeCity_EventScript_GiveTeam::
    lock
    faceplayer
    msgbox EverGrandeCity_Text_GiveTeam, MSGBOX_DEFAULT

    givemon SPECIES_FROSLASS, 57, ITEM_ICY_ROCK, , , , , , , , , , , , , , , , , MOVE_WILL_O_WISP, MOVE_HEX, MOVE_SPIKES, MOVE_BLIZZARD
    givemon SPECIES_GLALIE, 57, ITEM_HEAVY_DUTY_BOOTS, , , , , , , , , , , , , , , , , MOVE_ICE_SHARD, MOVE_ICICLE_CRASH, MOVE_PROTECT, MOVE_CRUNCH
    givemon SPECIES_SANDSLASH_ALOLAN, 57, ITEM_WIDE_LENS, , , , , , , , , , , , , , , , , MOVE_RAPID_SPIN, MOVE_TRIPLE_AXEL, MOVE_DRILL_RUN, MOVE_IRON_HEAD
    givemon SPECIES_LAPRAS, 57, ITEM_LEFTOVERS, , , , , , , , , , , , , , , , , MOVE_FREEZE_DRY, MOVE_HYDRO_PUMP, MOVE_FLIP_TURN, MOVE_AQUA_RING
    givemon SPECIES_MR_RIME, 57, ITEM_CHOICE_SPECS, , , , , , , , , , , , , , , , , MOVE_DAZZLING_GLEAM, MOVE_PSYCHIC, MOVE_BLIZZARD, MOVE_SHADOW_BALL
    givemon SPECIES_WALREIN, 58, ITEM_LIFE_ORB, , , , , , , , , , , , , , , , , MOVE_BLIZZARD, MOVE_ICICLE_CRASH, MOVE_LIQUIDATION, MOVE_CRUNCH

    giveitem ITEM_ABILITY_CAPSULE, 6
    giveitem ITEM_ABILITY_PATCH, 6
    giveitem ITEM_RARE_CANDY, 100

    msgbox EverGrandeCity_Text_GiveTeamReceived, MSGBOX_DEFAULT
    release
    end
	

	EverGrandeCity_EventScript_GiveTeam::
    lock
    faceplayer
    msgbox EverGrandeCity_Text_GiveTeam, MSGBOX_DEFAULT

    givemon SPECIES_SABLEYE, 57, ITEM_HEAVY_DUTY_BOOTS, , , , , , , , , , , , , , , , , MOVE_PARTING_SHOT, MOVE_KNOCK_OFF, MOVE_WILL_O_WISP, MOVE_TAUNT
    givemon SPECIES_DUSCLOPS, 57, ITEM_ROCKY_HELMET, , , , , , , , , , , , , , , , , MOVE_SHADOW_PUNCH, MOVE_KNOCK_OFF, MOVE_PROTECT, MOVE_CURSE
    givemon SPECIES_CHANDELURE, 57, ITEM_CHOICE_SPECS, , , , , , , , , , , , , , , , , MOVE_SHADOW_BALL, MOVE_FLAMETHROWER, MOVE_ENERGY_BALL, MOVE_NONE
    givemon SPECIES_SINISTCHA, 57, ITEM_LEFTOVERS, , , , , , , , , , , , , , , , , MOVE_SHADOW_BALL, MOVE_CALM_MIND, MOVE_MATCHA_GOTCHA, MOVE_STRENGTH_SAP
    givemon SPECIES_BANETTE, 57, ITEM_LIFE_ORB, , , , , , , , , , , , , , , , , MOVE_SHADOW_CLAW, MOVE_SWORDS_DANCE, MOVE_SHADOW_SNEAK, MOVE_PLAY_ROUGH
    givemon SPECIES_DUSKNOIR, 58, ITEM_SITRUS_BERRY, , , , , , , , , , , , , , , , , MOVE_SHADOW_PUNCH, MOVE_THUNDER_PUNCH, MOVE_CLOSE_COMBAT, MOVE_ICE_PUNCH

    giveitem ITEM_ABILITY_CAPSULE, 6
    giveitem ITEM_ABILITY_PATCH, 6
    giveitem ITEM_RARE_CANDY, 100

    msgbox EverGrandeCity_Text_GiveTeamReceived, MSGBOX_DEFAULT
    release
    end
	*/

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "ENTERING VICTORY ROAD$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "ENTERING POKéMON LEAGUE\n"
	.string "CENTER GATE$"

EverGrandeCity_Text_CitySign:
	.string "EVER GRANDE CITY\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and POKéMON.”$"

EverGrandeCity_Text_GiveTeam:
    .string "Here's your team, sir.$"

EverGrandeCity_Text_GiveTeamReceived:
    .string "You received a full team of POKéMON!$"

EverGrandeCity_Text_MayIntro:
    .string "{PLAYER}! I knew I'd find you here.\p"
    .string "You’re heading for Victory Road…\n"
    .string "which means you’re almost at the\p"
    .string "Pokémon League. But before you go, I\n"
	.string "want one last battle!\p"
    .string "Show me just how strong you and your\n"
    .string "Pokémon have become!$"

EverGrandeCity_Text_MayEntranceDefeat:
    .string "You really are ready…$"

EverGrandeCity_Text_MayPostEntranceBattle:
    .string "That was amazing, {PLAYER}.\p"
    .string "You and your Pokémon are completely in\n"
    .string "sync. I know you can make it through\p"
    .string "Victory Road and take on the League.\n"
    .string "I’ll be cheering for you the whole way!$"
