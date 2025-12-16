.set LOCALID_ATHENA, 1

LittlerootTown_AthenasHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_AthenasHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_AthenasHouse_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, LittlerootTown_AthenasHouse_OnResume
	.byte 0

LittlerootTown_AthenasHouse_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_AthenasHouse_EventScript_MoveMomToDoor
	end

LittlerootTown_AthenasHouse_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_ATHENA, 9, 8
	setobjectmovementtype LOCALID_ATHENA, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_AthenasHouse_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_AthenasHouse_EventScript_EnterHouseMovingIn
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, AthenasHouse_EventScript_ClearFlagAfterAthenaBattle
	.2byte 0

LittlerootTown_AthenasHouse_OnResume::
	end

LittlerootTown_AthenasHouse_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_ATHENA
	setvar VAR_0x8005, MALE
	goto AthenasHouse_EventScript_EnterHouseMovingIn
	end

AthenasHouse_EventScript_EnterHouseMovingIn::
	applymovement VAR_0x8004, AthenasHouse_Movement_AthenaGoToTable
	applymovement OBJ_EVENT_ID_PLAYER, AthenasHouse_Movement_PlayerGoToTable
	waitmovement 0
	msgbox AthenasHouse_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	msgbox AthenasHouse_Text_OfferStarters, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	releaseall
	end

AthenasHouse_Movement_AthenaGoToTable::
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_down
	step_end

AthenasHouse_Movement_PlayerGoToTable::
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end
	
AthenasHouse_EventScript_GoSeeBag::
	lockall
	setvar VAR_0x8004, LOCALID_ATHENA
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AthenasHouse_Text_ArentYouInterestedInBag, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	applymovement OBJ_EVENT_ID_PLAYER, AthenasHouse_Movement_MovePlayerAwayFromDoor
	waitmovement 0
	releaseall
	end

AthenasHouse_Movement_MovePlayerAwayFromDoor:
	walk_up
	step_end

LittlerootTown_AthenasHouse_EventScript_Bag::
	lock
	setvar VAR_0x8004, LOCALID_ATHENA
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	COMPARE VAR_LITTLEROOT_INTRO_STATE, 5
	call_if_eq LittlerootTown_AthenasHouse_EventScript_AlreadyChosenStarter
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	call SetStarterMetLocationToSpecial
	
	setflag FLAG_HIDE_ROUTE_1_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_1_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE1_STATE, 3
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	goto AthenasHouse_EventScript_AthenaFiredUp
	end

SetStarterMetLocationToSpecial::
	specialvar VAR_GIFT_PICHU_SLOT, CalculatePlayerPartyCount
	setmodernfatefulencounter VAR_GIFT_PICHU_SLOT
	setmonmetlocation VAR_GIFT_PICHU_SLOT, METLOC_FATEFUL_ENCOUNTER
	return

LittlerootTown_AthenasHouse_EventScript_AlreadyChosenStarter::
	msgbox AthenasHouse_Text_AlreadyChosenStarters, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	releaseall
	end

LittlerootTown_AthenasHouse_EventScript_AthenaWaiting::
	lock
	faceplayer
	msgbox AthenasHouse_Text_ArentYouInterestedInBag, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

AthenasHouse_EventScript_AthenaFiredUp::
	lockall
	setvar VAR_0x8004, LOCALID_ATHENA
	setvar VAR_0x8005, MALE
	waitmovement 0
	msgbox AthenasHouse_Text_AthenaFiredUp, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, Athenas_House_Movement_MoveAthenaToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox AthenasHouse_Text_AthenaTasteOfBattle, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TEMP_ATHENA_INTRO_BATTLE_IN_PROGRESS
	switch VAR_STARTER_MON
	case 0, AthenasHouse_EventScript_StartAthenaBattleAbra
	case 1, AthenasHouse_EventScript_StartAthenaBattleJangmoo
	case 2, AthenasHouse_EventScript_StartAthenaBattlePawniard
	end

Athenas_House_Movement_MoveAthenaToPlayer::
	walk_right
	walk_in_place_faster_down
	step_end

AthenasHouse_EventScript_StartAthenaBattleAbra::
	trainerbattle_no_intro TRAINER_ATHENA_ATHENAS_HOUSE_ABRA, Athenas_House_Text_ATHENADefeated
	goto AthenasHouse_EventScript_ClearFlagAfterAthenaBattle
	end

AthenasHouse_EventScript_StartAthenaBattleJangmoo::
	trainerbattle_no_intro TRAINER_ATHENA_ATHENAS_HOUSE_JANGMOO, Athenas_House_Text_ATHENADefeated
	goto AthenasHouse_EventScript_ClearFlagAfterAthenaBattle
	end

AthenasHouse_EventScript_StartAthenaBattlePawniard::
	trainerbattle_no_intro TRAINER_ATHENA_ATHENAS_HOUSE_PAWNIARD Athenas_House_Text_ATHENADefeated
	goto AthenasHouse_EventScript_ClearFlagAfterAthenaBattle
	end

AthenasHouse_EventScript_ClearFlagAfterAthenaBattle::
	clearflag FLAG_TEMP_ATHENA_INTRO_BATTLE_IN_PROGRESS
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	call AthenasHouse_EventScript_AfterAthenaBattle

AthenasHouse_EventScript_AfterAthenaBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	msgbox AthenasHouse_Text_AthenaSendOff MSGBOX_DEFAULT
	closemessage
	goto LittleRootTown_AthenasHouse_EventScript_GiveKeyItems
	end

LittleRootTown_AthenasHouse_EventScript_GiveKeyItems::
	msgbox LittlerootTown_AthenasHouse_Text_GiveKeyItems MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_POKE_BALL, 10
	waitfanfare
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_INF_CANDY
	waitfanfare
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_NECTAR_RESERVES
	waitfanfare
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_CAP_CANDY
	waitfanfare
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_THE_SACK
	waitfanfare
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	goto AthenasHouse_EventScript_AthenaExitHouse
	end

AthenasHouse_EventScript_AthenaExitHouse:: 
	setvar VAR_0x8004, LOCALID_ATHENA
	msgbox LittlerootTown_AthenasHouse_Text_AthenaLeaving MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, AthenasHouse_Movement_AthenaLeave
	waitmovement 0
	removeobject VAR_0x8004
	setflag FLAG_HIDE_LITTLEROOT_TOWN_ATHENAS_HOUSE_ATHENA
	releaseall
	end

AthenasHouse_Movement_AthenaLeave:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end


AthenasHouse_Text_IsntItNiceInHere:
	.string "Athena: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

AthenasHouse_Text_OfferStarters:
	.string "Now, that bag on the table contains\n"
	.string "some offerings I recently received.\l"
	.string "But frankly I receive more gifts\l"
	.string "than I know what to do with, so why\l"
	.string "don't you check it out instead?$"

AthenasHouse_Text_ArentYouInterestedInBag:
	.string "Athena: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing what's\n"
	.string "in the bag?$"

AthenasHouse_Text_AlreadyChosenStarters:
	.string "The leftover pokemon looks cosy\n"
	.string "as it is, best to leave it alone. $"

AthenasHouse_Text_AthenaFiredUp:
	.string "Athena: Great choice {PLAYER}!\n"
	.string "Seeing you two together has lit\l"
	.string "a fire in me, I think I'll start\l"
	.string "my own new adventure too!\p"
	.string "I'll take this little guy.$"
	

AthenasHouse_Text_AthenaTasteOfBattle:
	.string "Hey, why don't I give you a taste of \n"
	.string "what being a trainer is all about? $"
	
Athenas_House_Text_ATHENADefeated:
	.string "ATHENA: Oh, I lost…\n"
	.string "But that was fun!$"

AthenasHouse_Text_AthenaSendOff:
	.string "Athena: Wow, that was fun!$"

LittlerootTown_AthenasHouse_Text_GiveKeyItems:
	.string "Here are some useful\n"
	.string "items to help start your journey$"

LittlerootTown_AthenasHouse_Text_AthenaLeaving:
	.string "ATHENA: Ok, I'll be off now, I have \n"
	.string "business to attend to in Athens.\p"
	.string "You should head over there too {PLAYER}!\n"
	.string "It's a straight line from here, you\l"
	.string "can't miss it.$"
