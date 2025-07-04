Athens_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Athens_Gym_OnLoad
	.byte 0

Athens_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_ATHENS_GYM, Athens_Gym_EventScript_DeactivatePuzzle
	switch VAR_ATHENS_GYM_STATE
	case 0, Athens_Gym_EventScript_UpdateBarriers
	case 1, Athens_Gym_EventScript_Switch1Pressed
	case 2, Athens_Gym_EventScript_Switch2Pressed
	case 3, Athens_Gym_EventScript_Switch3Pressed
	case 4, Athens_Gym_EventScript_Switch4Pressed
	end

Athens_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_ATHENS_GYM_BARRIERS_STATE, Athens_Gym_EventScript_SetAltBarriers
	end

Athens_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_AthensGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_AthensGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_AthensGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_AthensGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_AthensGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_AthensGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_AthensGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_AthensGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_AthensGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_AthensGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_AthensGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_AthensGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_AthensGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_AthensGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_AthensGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_AthensGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_AthensGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_AthensGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_AthensGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_AthensGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_AthensGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_AthensGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_AthensGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_AthensGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_AthensGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_AthensGym_GreenBeamH4_Off, FALSE
	end

Athens_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special AthensGymPressSwitch
	goto Athens_Gym_EventScript_UpdateBarriers
	end

Athens_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special AthensGymPressSwitch
	goto Athens_Gym_EventScript_UpdateBarriers
	end

Athens_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special AthensGymPressSwitch
	goto Athens_Gym_EventScript_UpdateBarriers
	end

Athens_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special AthensGymPressSwitch
	goto Athens_Gym_EventScript_UpdateBarriers
	end

Athens_Gym_EventScript_DeactivatePuzzle::
	special AthensGymDeactivatePuzzle
	end

Athens_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, Athens_Gym_Text_WattsonIntro, Athens_Gym_Text_WattsonDefeat, Athens_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Athens_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, Athens_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_ATHENS_STATE, 2, Athens_Gym_EventScript_CompletedNewAthens
	msgbox Athens_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

Athens_Gym_EventScript_WattsonDefeated::
	message Athens_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox Athens_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_ATHENS_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special AthensGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call Athens_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Athens_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

Athens_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Athens_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

Athens_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Athens_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

Athens_Gym_EventScript_CompletedNewAthens::
	msgbox Athens_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

Athens_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, Athens_Gym_Text_WattsonPreRematch, Athens_Gym_Text_WattsonRematchDefeat, Athens_Gym_Text_WattsonRematchNeedTwoMons
	msgbox Athens_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

Athens_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_ATHENS_GYM, Athens_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_ATHENS_GYM_STATE, 1, Athens_Gym_EventScript_SwitchDoNothing
	setvar VAR_ATHENS_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto Athens_Gym_EventScript_PressFloorSwitch
	end

Athens_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_ATHENS_GYM, Athens_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_ATHENS_GYM_STATE, 2, Athens_Gym_EventScript_SwitchDoNothing
	setvar VAR_ATHENS_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto Athens_Gym_EventScript_PressFloorSwitch
	end

Athens_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_ATHENS_GYM, Athens_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_ATHENS_GYM_STATE, 3, Athens_Gym_EventScript_SwitchDoNothing
	setvar VAR_ATHENS_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto Athens_Gym_EventScript_PressFloorSwitch
	end

Athens_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_ATHENS_GYM, Athens_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_ATHENS_GYM_STATE, 4, Athens_Gym_EventScript_SwitchDoNothing
	setvar VAR_ATHENS_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto Athens_Gym_EventScript_PressFloorSwitch
	end

Athens_Gym_EventScript_PressFloorSwitch::
	special AthensGymSetDefaultBarriers
	special AthensGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_ATHENS_GYM_BARRIERS_STATE, Athens_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_ATHENS_GYM_BARRIERS_STATE, Athens_Gym_EventScript_SetBarriersAltState
	releaseall
	end

Athens_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

Athens_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_ATHENS_GYM_BARRIERS_STATE
	releaseall
	end

Athens_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_ATHENS_GYM_BARRIERS_STATE
	releaseall
	end

Athens_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, Athens_Gym_Text_KirkIntro, Athens_Gym_Text_KirkDefeat
	msgbox Athens_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

Athens_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, Athens_Gym_Text_ShawnIntro, Athens_Gym_Text_ShawnDefeat
	msgbox Athens_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

Athens_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, Athens_Gym_Text_BenIntro, Athens_Gym_Text_BenDefeat
	msgbox Athens_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

Athens_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, Athens_Gym_Text_VivianIntro, Athens_Gym_Text_VivianDefeat
	msgbox Athens_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

Athens_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, Athens_Gym_Text_AngeloIntro, Athens_Gym_Text_AngeloDefeat
	msgbox Athens_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

Athens_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ATHENS_GYM, Athens_Gym_EventScript_GymGuidePostVictory
	msgbox Athens_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

Athens_Gym_EventScript_GymGuidePostVictory::
	msgbox Athens_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

Athens_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, Athens_Gym_EventScript_GymStatueCertified
	goto Athens_Gym_EventScript_GymStatue
	end

Athens_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, Athens_Gym_EventScript_GymStatueCertified
	goto Athens_Gym_EventScript_GymStatue
	end

Athens_Gym_EventScript_GymStatueCertified::
	msgbox Athens_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

Athens_Gym_EventScript_GymStatue::
	msgbox Athens_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

Athens_Gym_Text_GymGuideAdvice:
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "WATTSON, the LEADER of ATHENS\n"
	.string "GYM, uses ELECTRIC-type POKéMON.\p"
	.string "If you challenge him with WATER-type\n"
	.string "POKéMON, he'll zap them! Bzzt!\p"
	.string "And, he's put in switch-controlled\n"
	.string "doors all over his GYM! Eccentric!\p"
	.string "Hey, go for it!$"

Athens_Gym_Text_GymGuidePostVictory:
	.string "Whoa, you're electrifying!\n"
	.string "You've powered the door open!$"

Athens_Gym_Text_KirkIntro:
	.string "My electric soul, it'll shatter your\n"
	.string "dreams whole, whoa-yeahah!$"

Athens_Gym_Text_KirkDefeat:
	.string "That was plugged in, amped up,\n"
	.string "over-driven electric, man!$"

Athens_Gym_Text_KirkPostBattle:
	.string "POKéMON and rock, it's all about heart,\n"
	.string "whoa-yeah!$"

Athens_Gym_Text_ShawnIntro:
	.string "I trained under WATTSON!\n"
	.string "There ain't no way I'll lose easily!$"

Athens_Gym_Text_ShawnDefeat:
	.string "Unplugged and turned off…$"

Athens_Gym_Text_ShawnPostBattle:
	.string "WATTSON, our GYM LEADER, has been\n"
	.string "around for a long, long time.\p"
	.string "He was battling even before your\n"
	.string "daddy was born, that tough coot.$"

Athens_Gym_Text_BenIntro:
	.string "This GYM's got puzzles!\n"
	.string "Isn't it fun?$"

Athens_Gym_Text_BenDefeat:
	.string "It's no fun to lose…$"

Athens_Gym_Text_BenPostBattle:
	.string "WATTSON says he likes setting up\n"
	.string "little traps with switches.$"

Athens_Gym_Text_VivianIntro:
	.string "With my charm and my POKéMON's moves,\n"
	.string "you'll be shocked!$"

Athens_Gym_Text_VivianDefeat:
	.string "I'm shocked by your power!$"

Athens_Gym_Text_VivianPostBattle:
	.string "I've heard that ATHENS was founded\n"
	.string "by WATTSON.\p"
	.string "He was a TRAINER long before we\n"
	.string "became TRAINERS.\l"
	.string "He must know all sorts of things!$"

Athens_Gym_Text_AngeloIntro:
	.string "I love shiny things!$"

Athens_Gym_Text_AngeloDefeat:
	.string "Oh…\n"
	.string "My eyes are frazzled…$"

Athens_Gym_Text_AngeloPostBattle:
	.string "ATHENS GYM's WATTSON has a shiny\n"
	.string "forehead. It makes me happy!$"

Athens_Gym_Text_WattsonIntro:
	.string "I've given up on my plans to convert\n"
	.string "the city, I have.\p"
	.string "And so, I put my time into making\n"
	.string "door traps in my GYM.\p"
	.string "Oh? Now, what are you doing here?\p"
	.string "What's that? You say you've gotten\n"
	.string "past all my rigged doors?\p"
	.string "Wahahahah!\n"
	.string "Now, that is amusing!\p"
	.string "Then, I, WATTSON, the LEADER of\n"
	.string "ATHENS GYM, shall electrify you!$"

Athens_Gym_Text_WattsonDefeat:
	.string "Wahahahah!\n"
	.string "Fine, I lost!\p"
	.string "You ended up giving me a thrill!\n"
	.string "Take this BADGE!$"

Athens_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} received the DYNAMO BADGE\n"
	.string "from WATTSON.$"

Athens_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "With the DYNAMO BADGE, POKéMON can\n"
	.string "use ROCK SMASH out of battle.\p"
	.string "And, it will make your POKéMON a little\n"
	.string "bit faster, too.\p"
	.string "Hmm…\n"
	.string "You should take this, too!$"

Athens_Gym_Text_ExplainShockWave:
	.string "That TM34 there contains SHOCK WAVE.\p"
	.string "It's a trustworthy move that never\n"
	.string "misses! You can count on it!\p"
	.string "… … … … … …$"

Athens_Gym_Text_RegisteredWattson:
	.string "Registered GYM LEADER WATTSON\n"
	.string "in the POKéNAV.$"

Athens_Gym_Text_WattsonPostBattle:
	.string "I swell with optimism, seeing a promising\n"
	.string "young TRAINER like you!$"

Athens_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah!\n"
	.string "Go forth and endeavor, youngster!$"

Athens_Gym_Text_GymStatue:
	.string "ATHENS POKéMON GYM$"

Athens_Gym_Text_GymStatueCertified:
	.string "ATHENS POKéMON GYM\p"
	.string "WATTSON'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

Athens_Gym_Text_WattsonPreRematch:
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "I'll make sparks fly from you!\n"
	.string "Don't say I didn't warn you!$"

Athens_Gym_Text_WattsonRematchDefeat:
	.string "Oof…\n"
	.string "Our batteries ran dry…$"

Athens_Gym_Text_WattsonPostRematch:
	.string "WATTSON: We'll have to recharge our\n"
	.string "batteries again.\p"
	.string "When we're fully charged up, we'll\n"
	.string "gladly accept your challenge.\p"
	.string "So, come back again sometime,\n"
	.string "won't you?$"

Athens_Gym_Text_WattsonRematchNeedTwoMons:
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Oops! Wait!\n"
	.string "You've only one POKéMON with you!\p"
	.string "Come see me with two or more\n"
	.string "POKéMON, all right?$"

