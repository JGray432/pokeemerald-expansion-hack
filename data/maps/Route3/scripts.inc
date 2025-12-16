@ NOTE: Route 109's sail to Dewford script references local IDs from Dewford's map.
@  These are labeled in DewfordTown/scripts.inc

.set LOCALID_ATHENA, 3

Route3_MapScripts::
	.byte 0

Route3_EventScript_AthenaAppear_Left::
	lock
	setobjectxyperm LOCALID_ATHENA, 15, 0
	addobject LOCALID_ATHENA
	applymovement LOCALID_ATHENA, Route3_Movement_AthenaBattle
	waitmovement 0
	goto Route3_EventScript_AthenaBattle	
	end

Route3_EventScript_AthenaAppear_Middle::
	lock
	setobjectxyperm LOCALID_ATHENA, 16, 0
	addobject LOCALID_ATHENA
	applymovement LOCALID_ATHENA, Route3_Movement_AthenaBattle
	waitmovement 0
	goto Route3_EventScript_AthenaBattle	
	end

Route3_EventScript_AthenaAppear_Right::
	lock
	setobjectxyperm LOCALID_ATHENA, 17, 0
	addobject LOCALID_ATHENA
	applymovement LOCALID_ATHENA, Route3_Movement_AthenaBattle
	waitmovement 0
	goto Route3_EventScript_AthenaBattle	
	end

Route3_Movement_AthenaBattle::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route3_EventScript_AthenaBattle::
	msgbox Route3_Text_AthenaBattleIntro, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, Route3_EventScript_StartAthenaBattleAbra
	case 1, Route3_EventScript_StartAthenaBattleJangmoo
	case 2, Route3_EventScript_StartAthenaBattlePawniard
	end

Route3_EventScript_StartAthenaBattleAbra::
	trainerbattle_no_intro TRAINER_ATHENA_ROUTE_3_ABRA, Route3_Text_AthenaDefeated
	goto Route3_EventScript_AfterAthenaBattle
	end

Route3_EventScript_StartAthenaBattleJangmoo::
	trainerbattle_no_intro TRAINER_ATHENA_ROUTE_3_JANGMOO, Route3_Text_AthenaDefeated
	goto Route3_EventScript_AfterAthenaBattle
	end

Route3_EventScript_StartAthenaBattlePawniard::
	trainerbattle_no_intro TRAINER_ATHENA_ROUTE_3_PAWNIARD, Route3_Text_AthenaDefeated
	goto Route3_EventScript_AfterAthenaBattle
	end

Route3_EventScript_AfterAthenaBattle:
	msgbox Route3_Text_AthenaSendOff, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATHENA, Route3_Movement_AthenaExit
	waitmovement 0
	removeobject LOCALID_ATHENA
	setvar VAR_ATHENS_CITY_STATE, 3
	clearflag FLAG_RIVAL01
	releaseall
	end

Route3_Movement_AthenaExit::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route3_EventScript_StartDepartForDewford::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE3, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE3, 0
	applymovement LOCALID_BRINEY_R109, Route3_Movement_BrineyEnterBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_R109
	switch VAR_FACING
	case DIR_SOUTH, Route3_EventScript_EnterBoatSouth
	case DIR_WEST, Route3_EventScript_EnterBoatWest
	case DIR_EAST, Route3_EventScript_EnterBoatEast
	end

Route3_EventScript_EnterBoatSouth::
	applymovement OBJ_EVENT_ID_PLAYER, Route3_Movement_PlayerEnterBoatSouth
	waitmovement 0
	goto Route3_EventScript_DoSailToDewford
	end

Route3_EventScript_EnterBoatEast::
	applymovement OBJ_EVENT_ID_PLAYER, Route3_Movement_PlayerEnterBoatEast
	waitmovement 0
	goto Route3_EventScript_DoSailToDewford
	end

Route3_EventScript_EnterBoatWest::
	applymovement OBJ_EVENT_ID_PLAYER, Route3_Movement_PlayerEnterBoatWest
	waitmovement 0
	goto Route3_EventScript_DoSailToDewford
	end

Route3_EventScript_DoSailToDewford::
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE3
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_R109, Route3_Movement_SailToDewford
	applymovement OBJ_EVENT_ID_PLAYER, Route3_Movement_SailToDewford
	waitmovement 0
	delay 50
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_DEWFORD_TOWN
	applymovement OBJ_EVENT_ID_PLAYER, Route3_Movement_PlayerExitBoat
	waitmovement 0
	addobject LOCALID_BOAT_DEWFORD
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setobjectxyperm LOCALID_BRINEY_DEWFORD, 12, 8
	addobject LOCALID_BRINEY_DEWFORD
	setobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN, 0
	applymovement LOCALID_BRINEY_DEWFORD, Route3_Movement_BrineyExitBoat
	waitmovement 0
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_3_MR_BRINEY_BOAT
	hideobjectat LOCALID_BOAT_R109, MAP_ROUTE3
	msgbox DewfordTown_Text_BrineyLandedInDewford, MSGBOX_DEFAULT
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_ROUTE3
	resetobjectsubpriority LOCALID_BRINEY_DEWFORD, MAP_DEWFORD_TOWN
	copyobjectxytoperm LOCALID_BRINEY_DEWFORD
	release
	end

Route3_Movement_SailToDewford:
	walk_in_place_faster_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

Route3_Movement_PlayerEnterBoatSouth:
	walk_down
	walk_down
	step_end

Route3_Movement_PlayerExitBoat:
	walk_down
	walk_down
	walk_left
	walk_in_place_faster_right
	step_end

Route3_Movement_PlayerEnterBoatEast:
	walk_right
	walk_down
	step_end

Route3_Movement_PlayerEnterBoatWest:
	walk_left
	walk_down
	step_end

Route3_Movement_BrineyEnterBoat:
	walk_down
	step_end

Route3_Movement_BrineyExitBoat:
	walk_down
	walk_in_place_faster_left
	step_end

Route3_EventScript_MrBriney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, Route3_EventScript_HaveNotDeliveredDevonGood
	goto Route3_EventScript_DeliveredDevonGoods 
	end

Route3_EventScript_HaveNotDeliveredDevonGood::
	msgbox Route3_Text_BrineyNoSailYet, MSGBOX_NPC
	closemessage
	release
	end

Route3_EventScript_DeliveredDevonGoods::
	msgbox Route3_Text_BrineyHappyToSail, MSGBOX_NPC
	waitmessage
	msgbox Route3_Text_BrineySailToCreteQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route3_EventScript_StayHere
	goto Route3_EventScript_SailToDewford
	end

Route3_EventScript_SailToDewford::
	msgbox Route3_Text_BrineyDewfordItIs, MSGBOX_DEFAULT
	closemessage
	goto Route3_EventScript_StartDepartForDewford
	end

Route3_EventScript_StayHere::
	msgbox Route3_Text_BrineyDeliverDevonGoods, MSGBOX_DEFAULT
	release
	end

Route3_EventScript_ChoseNotToSail::
	msgbox Route3_Text_BrineyTellMeWhenYouNeedToSail, MSGBOX_DEFAULT
	release
	end

Route3_EventScript_SeashoreHouseGirl::
	msgbox Route3_Text_ChillAtMyPapasSpot, MSGBOX_NPC
	end

Route3_EventScript_SandCastleBoy::
	lock
	faceplayer
	msgbox Route3_Text_SandCastleTakingLongTime, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route3_EventScript_SoftSandGirl::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	goto_if_set FLAG_RECEIVED_SOFT_SAND, Route3_EventScript_AlreadyReceivedSoftSand
	msgbox Route3_Text_YouCanHaveThis, MSGBOX_DEFAULT
	giveitem ITEM_SOFT_SAND
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_RECEIVED_SOFT_SAND
	release
	end

Route3_EventScript_AlreadyReceivedSoftSand::
	msgbox Route3_Text_WereGoingToMakeBigCastle, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route3_EventScript_Woman::
	msgbox Route3_Text_LittleKidsDartAround, MSGBOX_NPC
	end

Route3_EventScript_OldMan::
	msgbox Route3_Text_ZigzagoonPicksUpLitter, MSGBOX_NPC
	end

Route3_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox Route3_Text_ZigzagoonCry, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route3_EventScript_SeashoreHouseSign::
	msgbox Route3_Text_SeashoreHouseSign, MSGBOX_SIGN
	end

Route3_EventScript_TrainerTipsSign::
	msgbox Route3_Text_TrainerTipsSign, MSGBOX_SIGN
	end

Route3_EventScript_David::
	trainerbattle_single TRAINER_DAVID, Route3_Text_DavidIntro, Route3_Text_DavidDefeated
	msgbox Route3_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Alice::
	trainerbattle_single TRAINER_ALICE, Route3_Text_AliceIntro, Route3_Text_AliceDefeated
	msgbox Route3_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, Route3_Text_HueyIntro, Route3_Text_HueyDefeated
	msgbox Route3_Text_HueyPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Edmond::
	trainerbattle_single TRAINER_EDMOND, Route3_Text_EdmondIntro, Route3_Text_EdmondDefeated
	msgbox Route3_Text_EdmondPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY_1, Route3_Text_RickyIntro, Route3_Text_RickyDefeated, Route3_EventScript_RickyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_RickyRematch
	msgbox Route3_Text_RickyPostBattle, MSGBOX_DEFAULT
	release
	end

Route3_EventScript_RickyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_RickyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICKY_1
	release
	end

Route3_EventScript_RickyRematch::
	trainerbattle_rematch TRAINER_RICKY_1, Route3_Text_RickyRematchIntro, Route3_Text_RickyRematchDefeated
	msgbox Route3_Text_RickyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA_1, Route3_Text_LolaIntro, Route3_Text_LolaDefeated, Route3_EventScript_LolaRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route3_EventScript_LolaRematch
	msgbox Route3_Text_LolaPostBattle, MSGBOX_DEFAULT
	release
	end

Route3_EventScript_LolaRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route3_Text_LolaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LOLA_1
	release
	end

Route3_EventScript_LolaRematch::
	trainerbattle_rematch TRAINER_LOLA_1, Route3_Text_LolaRematchIntro, Route3_Text_LolaRematchDefeated
	msgbox Route3_Text_LolaRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Austina::
	trainerbattle_single TRAINER_AUSTINA, Route3_Text_AustinaIntro, Route3_Text_AustinaDefeated
	msgbox Route3_Text_AustinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Gwen::
	trainerbattle_single TRAINER_GWEN, Route3_Text_GwenIntro, Route3_Text_GwenDefeated
	msgbox Route3_Text_GwenPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Carter::
	trainerbattle_single TRAINER_CARTER, Route3_Text_CarterIntro, Route3_Text_CarterDefeated
	msgbox Route3_Text_CarterPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Paul::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route3_Text_PaulIntro, Route3_Text_PaulDefeated, Route3_Text_PaulNotEnoughPokemon
	msgbox Route3_Text_PaulPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Mel::
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route3_Text_MelIntro, Route3_Text_MelDefeated, Route3_Text_MelNotEnoughPokemon
	msgbox Route3_Text_MelPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Chandler::
	trainerbattle_single TRAINER_CHANDLER, Route3_Text_ChandlerIntro, Route3_Text_ChandlerDefeated
	msgbox Route3_Text_ChandlerPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Hailey::
	trainerbattle_single TRAINER_HAILEY, Route3_Text_HaileyIntro, Route3_Text_HaileyDefeated
	msgbox Route3_Text_HaileyPostBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Elijah::
	trainerbattle_single TRAINER_ELIJAH, Route3_Text_ElijahIntro, Route3_Text_ElijahDefeated
	msgbox Route3_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Text_BrineyLandedInSlateportDeliverGoods:
	.string "MR. BRINEY: Ahoy!\n"
	.string "We've made land in SLATEPORT!\p"
	.string "I suppose you're going to visit CAPT.\n"
	.string "STERN and deliver the DEVON GOODS?$"

Route3_Text_BrineyNoSailYet:
	.string "MR. BRINEY: Hrmph. This boat takes\n"
	.string "you to Crete. But I ain't makin'\p"
	.string "the effort of a trip unless I got\n"
	.string "good reason to, ya hear?$"

Route3_Text_BrineyDewfordItIs:
	.string "MR. BRINEY: Crete it is, then!\n"
	.string "Anchors aweigh!$"

Route3_Text_AthenaBattleIntro:
	.string "ATHENA: Hey, {PLAYER}!\n"
	.string "Leaving Athens so soon?\p"
	.string "Let's see if you've gotten \n"
	.string "any stonger!$"

Route3_Text_AthenaDefeated:
	.string "ATHENA: Oh, no! I lost!\n"
	.string "I guess I have to go back to the\n"
	.string "drawing board.$"

Route3_Text_AthenaSendOff:
	.string "ATHENA: Cya$"

Route3_Text_BrineyDeliverDevonGoods:
	.string "MR. BRINEY: Then you go on and deliver\n"
	.string "the DEVON GOODS. I'll be waiting.$"

DewfordTown_Text_BrineyLandedInSlateport:
	.string "MR. BRINEY: Ahoy! We've made land in\n"
	.string "SLATEPORT!\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail again!$"

Route3_Text_BrineyHappyToSail:
	.string "MR. BRINEY: What's that?\n"
	.string "Dionysus needs you to go to Crete?\p"
	.string "Why that changes everything! He \n"
	.string "provides me with the best rum this\l"
	.string "side of the Pacific!$"

Route3_Text_BrineySailToCreteQuestion:
	.string "You ready to set sail?$"

Route3_Text_BrineyTellMeWhenYouNeedToSail:
	.string "MR. BRINEY: You just tell me whenever\n"
	.string "you need to set sail again!$"

Route3_Text_ChillAtMyPapasSpot:
	.string "Yo, TRAINERS!\n"
	.string "Whether you're hot to trot,\l"
	.string "or cool cat not,\l"
	.string "chill at my papa's spot!$"

Route3_Text_LittleKidsDartAround:
	.string "Little kids can dart around so quickly…\p"
	.string "You don't dare take your eyes off them\n"
	.string "for an instant. It's very taxing.\p"
	.string "Mine are with my POKéMON, so they\n"
	.string "should be okay, but…$"

Route3_Text_SandCastleTakingLongTime:
	.string "Our sand castle's taking a long time\n"
	.string "to make.$"

Route3_Text_YouCanHaveThis:
	.string "You can have this!$"

Route3_Text_WereGoingToMakeBigCastle:
	.string "We're going to get all the sand from\n"
	.string "the beach and make a big castle!\p"
	.string "And then we're going to be a king and\n"
	.string "queen.\p"
	.string "We'll let you be a servant.$"

Route3_Text_ZigzagoonPicksUpLitter:
	.string "The water around these parts is clean.\p"
	.string "But, I get my ZIGZAGOON to pick up\n"
	.string "litter from the shoreline at times.\p"
	.string "Dirty water becomes rain and joins our\n"
	.string "rivers, which we drink from…\p"
	.string "If we pollute the sea, it all comes\n"
	.string "back to haunt us eventually.$"

Route3_Text_ZigzagoonCry:
	.string "ZIGZAGOON: Guguu?$"

Route3_Text_SeashoreHouseSign:
	.string "SEASHORE HOUSE\p"
	.string "“May hot battles rage on hot sands!\n"
	.string "The place for hot TRAINERS!”$"

Route3_Text_TrainerTipsSign:
	.string "TRAINER TIPS\p"
	.string "POKéMON at the same level may not\n"
	.string "always have identical stats.\p"
	.string "POKéMON raised by TRAINERS are said\n"
	.string "to grow stronger than wild POKéMON.$"
