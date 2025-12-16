.set LOCALID_RIVAL, 2

DionysusVineyard_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DionysusVineyard_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, DionysusVineyard_OnLoad
	.byte 0

DionysusVineyard_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

DionysusVineyard_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, DionysusVineyard_EventScript_OpenAlteringCave
	end

DionysusVineyard_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return

DionysusVineyard_EventScript_Rival::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, DionysusVineyard_EventScript_RivalMay
	goto_if_eq VAR_RESULT, FEMALE, DionysusVineyard_EventScript_RivalBrendan
	end

DionysusVineyard_EventScript_RivalMay::
	msgbox DionysusVineyard_Text_MayDionysusVineyardPokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox DionysusVineyard_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, DionysusVineyard_EventScript_StartMayBattleTreecko
	case 1, DionysusVineyard_EventScript_StartMayBattleTorchic
	case 2, DionysusVineyard_EventScript_StartMayBattleMudkip
	end

DionysusVineyard_EventScript_RivalBrendan::
	msgbox DionysusVineyard_Text_BrendanDionysusVineyardPokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox DionysusVineyard_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, DionysusVineyard_EventScript_StartBrendanBattleTreecko
	case 1, DionysusVineyard_EventScript_StartBrendanBattleTorchic
	case 2, DionysusVineyard_EventScript_StartBrendanBattleMudkip
	end

DionysusVineyard_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_DIONYSUS_VINEYARD_TREECKO, DionysusVineyard_Text_MayDefeated
	goto DionysusVineyard_EventScript_AfterMayBattle
	end

DionysusVineyard_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_DIONYSUS_VINEYARD_TORCHIC, DionysusVineyard_Text_MayDefeated
	goto DionysusVineyard_EventScript_AfterMayBattle
	end

DionysusVineyard_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_DIONYSUS_VINEYARD_MUDKIP, DionysusVineyard_Text_MayDefeated
	goto DionysusVineyard_EventScript_AfterMayBattle
	end

DionysusVineyard_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_DIONYSUS_VINEYARD_TREECKO, DionysusVineyard_Text_BrendanDefeated
	goto DionysusVineyard_EventScript_AfterBrendanBattle
	end

DionysusVineyard_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_DIONYSUS_VINEYARD_TORCHIC, DionysusVineyard_Text_BrendanDefeated
	goto DionysusVineyard_EventScript_AfterBrendanBattle
	end

DionysusVineyard_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_DIONYSUS_VINEYARD_MUDKIP, DionysusVineyard_Text_BrendanDefeated
	goto DionysusVineyard_EventScript_AfterBrendanBattle
	end

DionysusVineyard_EventScript_AfterMayBattle::
	msgbox DionysusVineyard_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto DionysusVineyard_EventScript_RivalExit
	end

DionysusVineyard_EventScript_AfterBrendanBattle::
	msgbox DionysusVineyard_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto DionysusVineyard_EventScript_RivalExit
	end

DionysusVineyard_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, DionysusVineyard_EventScript_RivalExitFacingSouth
	case DIR_NORTH, DionysusVineyard_EventScript_RivalExitFacingNorth
	case DIR_WEST, DionysusVineyard_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, DionysusVineyard_EventScript_RivalExitFacingEastOrWest
	end

DionysusVineyard_EventScript_RivalExitFacingNorth:: 
	applymovement OBJ_EVENT_ID_PLAYER, DionysusVineyard_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_RIVAL, DionysusVineyard_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, DionysusVineyard_Movement_RivalExitFacingNorth2
	waitmovement 0
	goto DionysusVineyard_EventScript_RivalEnd
	end

DionysusVineyard_EventScript_RivalExitFacingEastOrWest::
	applymovement OBJ_EVENT_ID_PLAYER, DionysusVineyard_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_RIVAL, DionysusVineyard_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, DionysusVineyard_Movement_RivalExit2
	waitmovement 0
	goto DionysusVineyard_EventScript_RivalEnd
	end

DionysusVineyard_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_RIVAL, DionysusVineyard_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, DionysusVineyard_Movement_RivalExit2
	waitmovement 0
	goto DionysusVineyard_EventScript_RivalEnd
	end

DionysusVineyard_EventScript_RivalEnd::
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_DIONYSUS_VINEYARD
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

DionysusVineyard_Movement_RivalExitFacingNorth1:
	walk_left
	walk_down
	step_end

DionysusVineyard_Movement_RivalExitFacingNorth2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

DionysusVineyard_Movement_WatchRivalExitFacingNorth:
	delay_16
	delay_4
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

DionysusVineyard_Movement_RivalExit1:
	walk_down
	step_end

DionysusVineyard_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

DionysusVineyard_Movement_WatchRivalExitFacingEastOrWest:
	delay_16
	walk_in_place_faster_down
	step_end

DionysusVineyard_EventScript_Boy::
	msgbox DionysusVineyard_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

DionysusVineyard_EventScript_Man::
	msgbox DionysusVineyard_Text_ShortcutToOldale, MSGBOX_NPC
	end

DionysusVineyard_EventScript_RouteSign::
	msgbox DionysusVineyard_Text_RouteSign, MSGBOX_SIGN
	end

DionysusVineyard_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, DionysusVineyard_Text_DaisyIntro, DionysusVineyard_Text_DaisyDefeated
	msgbox DionysusVineyard_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

DionysusVineyard_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, DionysusVineyard_Text_AmyIntro, DionysusVineyard_Text_AmyDefeated, DionysusVineyard_Text_AmyNotEnoughPokemon, ROUTE2_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE2_EventScript_AmyRematch
	msgbox DionysusVineyard_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

ROUTE2_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox DionysusVineyard_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

ROUTE2_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, DionysusVineyard_Text_AmyRematchIntro, DionysusVineyard_Text_AmyRematchDefeated, DionysusVineyard_Text_AmyRematchNotEnoughPokemon
	msgbox DionysusVineyard_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

DionysusVineyard_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, DionysusVineyard_Text_LivIntro, DionysusVineyard_Text_LivDefeated, DionysusVineyard_Text_LivNotEnoughPokemon, ROUTE2_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE2_EventScript_LivRematch
	msgbox DionysusVineyard_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

ROUTE2_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox DionysusVineyard_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

ROUTE2_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, DionysusVineyard_Text_LivRematchIntro, DionysusVineyard_Text_LivRematchDefeated, DionysusVineyard_Text_LivRematchNotEnoughPokemon
	msgbox DionysusVineyard_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

DionysusVineyard_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, DionysusVineyard_Text_AndrewIntro, DionysusVineyard_Text_AndrewDefeated
	msgbox DionysusVineyard_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

DionysusVineyard_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, DionysusVineyard_Text_MiguelIntro, DionysusVineyard_Text_MiguelDefeated, ROUTE2_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DionysusVineyard_EventScript_MiguelRematch
	msgbox DionysusVineyard_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

ROUTE2_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox DionysusVineyard_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

DionysusVineyard_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, DionysusVineyard_Text_MiguelRematchIntro, DionysusVineyard_Text_MiguelRematchDefeated
	msgbox DionysusVineyard_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

DionysusVineyard_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, DionysusVineyard_Text_MarcosIntro, DionysusVineyard_Text_MarcosDefeated
	msgbox DionysusVineyard_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	setflag FLAG_BADGE01_GET
	end

DionysusVineyard_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, DionysusVineyard_Text_RhettIntro, DionysusVineyard_Text_RhettDefeated
	msgbox DionysusVineyard_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

DionysusVineyard_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, DionysusVineyard_Text_PeteIntro, DionysusVineyard_Text_PeteDefeated
	msgbox DionysusVineyard_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

DionysusVineyard_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, DionysusVineyard_Text_IsabelleIntro, DionysusVineyard_Text_IsabelleDefeated
	msgbox DionysusVineyard_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

DionysusVineyard_Text_MayDionysusVineyardPokemon:
	.string "MAY: Let's see… The POKéMON found\n"
	.string "on DIONYSUS VINEYARD include…$"

DionysusVineyard_Text_MayLetsBattle:
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a POKéMON as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

DionysusVineyard_Text_MayDefeated:
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

DionysusVineyard_Text_MayTimeToHeadBack:
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

DionysusVineyard_Text_BrendanDionysusVineyardPokemon:
	.string "BRENDAN: Okay, so it's this one and\n"
	.string "that one that live on DIONYSUS VINEYARD…$"

DionysusVineyard_Text_BrendanLetsBattle:
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a POKéMON.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

DionysusVineyard_Text_BrendanDefeated:
	.string "Huh, {PLAYER}, you're not too shabby.$"

DionysusVineyard_Text_BrendanTimeToHeadBack:
	.string "BRENDAN: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "We should head back to the LAB.$"

DionysusVineyard_Text_ShouldHaveBroughtPotion:
	.string "My POKéMON is staggeringly tired…\n"
	.string "I should have brought a POTION…$"

DionysusVineyard_Text_ShortcutToOldale:
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to OLDALE TOWN.\p"
	.string "Fufufu, that's useful, isn't it?$"

DionysusVineyard_Text_RouteSign:
	.string "DIONYSUS VINEYARD\n"
	.string "{DOWN_ARROW} OLDALE TOWN$"

