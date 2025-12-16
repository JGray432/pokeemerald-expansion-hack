.set LOCALID_ATHENA, 1

LittlerootTown_AthenasHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_AthenasHouse_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_AthenasHouse_OnFrame
	.byte 0

LittlerootTown_AthenasHouse_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_AthenasHouse_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_AthenasHouse_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_AthenasHouse_EventScript_MoveMomToTV
	end

LittlerootTown_AthenasHouse_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_ATHENA, 8, 4
	setobjectmovementtype LOCALID_ATHENA, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_AthenasHouse_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_ATHENA, 4, 5
	setobjectmovementtype LOCALID_ATHENA, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_AthenasHouse_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_ATHENA, 9, 8
	setobjectmovementtype LOCALID_ATHENA, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_AthenasHouse_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_AthenasHouse_EventScript_EnterHouseMovingIn
	.2byte 0

LittlerootTown_AthenasHouse_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_ATHENA
	setvar VAR_0x8005, MALE
	goto AthenasHouse_EventScript_EnterHouseMovingIn
	end

AthenasHouse_EventScript_EnterHouseMovingIn::
	msgbox AthenasHouse_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	call AthenasHouse_EventScript_MomFacePlayerMovingIn
	msgbox AthenasHouse_Text_OfferStarters, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, AthenasHouse_Movement_MovePlayerAwayFromDoor
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	releaseall
	end

AthenasHouse_EventScript_MomFacePlayerMovingIn::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

AthenasHouse_EventScript_GoSeeBag::
	lockall
	setvar VAR_0x8004, LOCALID_ATHENA
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox AthenasHouse_Text_ArentYouInterestedInBag, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, AthenasHouse_Movement_MovePlayerAwayFromDoor
	waitmovement 0
	releaseall
	end

AthenasHouse_Movement_MovePlayerAwayFromDoor:
	walk_up
	step_end

LittlerootTown_AthenasHouse_EventScript_Bag::
	lock
	faceplayer
	COMPARE VAR_LITTLEROOT_INTRO_STATE, 7
	call_if_eq LittlerootTown_AthenasHouse_EventScript_AlreadyChosenStarter
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	special ChooseStarter
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	goto AthenasHouse_EventScript_AthenaFiredUp
	release
	end

LittlerootTown_AthenasHouse_EventScript_AlreadyChosenStarter::
	msgbox AthenasHouse_Text_AlreadyChosenStarters, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	releaseall
	end

AthenasHouse_EventScript_AthenaFiredUp::
	lockall
	setvar VAR_0x8004, LOCALID_ATHENA
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement VAR_0x8004, Athenas_House_Movement_MoveAthenaToPlayer
	msgbox AthenasHouse_Text_AthenaFiredUp, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, AthenasHouse_EventScript_StartAthenaBattleAbra
	case 1, AthenasHouse_EventScript_StartAthenaBattleJangmoo
	case 2, AthenasHouse_EventScript_StartAthenaBattlePawniard
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

Athenas_House_Movement_MoveAthenaToPlayer::
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_left
	walk_left
	step_end

AthenasHouse_EventScript_StartAthenaBattleAbra::
	trainerbattle_no_intro TRAINER_ATHENA_ATHENAS_HOUSE_ABRA, Athenas_House_Text_ATHENADefeated
	goto AthenasHouse_EventScript_AfterAthenaBattle
	end

AthenasHouse_EventScript_StartAthenaBattleJangmoo::
	trainerbattle_no_intro TRAINER_ATHENA_ATHENAS_HOUSE_JANGMOO, Athenas_House_Text_ATHENADefeated
	goto AthenasHouse_EventScript_AfterAthenaBattle
	end

AthenasHouse_EventScript_StartAthenaBattlePawniard::
	trainerbattle_no_intro TRAINER_ATHENA_ATHENAS_HOUSE_PAWNIARD Athenas_House_Text_ATHENADefeated
	goto AthenasHouse_EventScript_AfterAthenaBattle
	end

AthenasHouse_EventScript_AfterAthenaBattle::
	msgbox AthenasHouse_Text_AthenaSendOff MSGBOX_DEFAULT
	goto LittleRootTown_AthenasHouse_EventScript_GiveKeyItems
	end

LittleRootTown_AthenasHouse_EventScript_GiveKeyItems::
	msgbox LittlerootTown_AthenasHouse_Text_GiveKeyItems MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_INF_CANDY
	waitfanfare
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_INF_REPEL
	waitfanfare
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_NECTAR_RESERVES
	waitfanfare
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_CAP_CANDY
	waitfanfare
	goto AthenasHouse_EventScript_AthenaExitHouse
	end

AthenasHouse_EventScript_AthenaExitHouse:: 
	setvar VAR_0x8004, LOCALID_ATHENA
	msgbox LittlerootTown_AthenasHouse_Text_AthenaLeaving MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, AthenasHouse_Movement_AthenaLeave
	setflag FLAG_HIDE_LITTLEROOT_TOWN_ATHENAS_HOUSE_ATHENA
	releaseall
	end

AthenasHouse_Movement_AthenaLeave:
	walk_in_place_fast_right
	walk_right
	walk_right
	walk_right
	walk_in_place_down
	walk_down
	walk_down
	walk_down
	step_end


EventScript_RunningShoesManual::
	msgbox AthenasHouse_Text_RunningShoesManual, MSGBOX_SIGN
	end

AthenasHouse_Text_IsntItNiceInHere:
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

AthenasHouse_Text_OfferStarters:
	.string "Now, that bag on the table contains\n"
	.string "some offerings I recently received.\l"
	.string "But frankly I receive more gifts\p"
	.string "than I know what to do with, so why\n"
	.string "don't you check it out instead?\p"

AthenasHouse_Text_ArentYouInterestedInBag:
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing what's\n"
	.string "in the bag?$"

AthenasHouse_Text_AlreadyChosenStarters:
	.string "The leftover pokemon looks cosy\n"
	.string "as it is, best to leave it alone\p"

AthenasHouse_Text_AthenaFiredUp:
	.string "Athena: Great choice {PLAYER}!\n"
	.string "Seeing you two together has lit\l"
	.string "a fire in me, I think I'll start\l"
	.string "my own new adventure too!\p"
	.string "I'll take this little guy.\n"
	.string "Hey, why don't I give you a taste of \l$"
	.string "what being a trainer is all about? \p$"

Athenas_House_Text_ATHENADefeated:
	.string "ATHENA: Oh, I lost…\n"
	.string "But that was fun!$"

AthenasHouse_Text_AthenaSendOff:
	.string "Athena: Wow, that was fun!\p"

LittlerootTown_AthenasHouse_Text_GiveKeyItems:
	.string "Here are some useful\n"
	.string "items to help start your journey\p"

LittlerootTown_AthenasHouse_Text_ReceivedInfCandy:
	.string "{PLAYER} received the Inf Candy!\p$"

LittlerootTown_AthenasHouse_Text_ReceivedInfRepel:
	.string "{PLAYER} received the Inf Repel!\p$"

LittlerootTown_AthenasHouse_Text_ReceivedNectarReserves:
	.string "{PLAYER} received the Nectar Reserves!\p$"

LittlerootTown_AthenasHouse_Text_ReceivedCapCandy:
	.string "{PLAYER} received the Level Cap Candy!\p$"

LittlerootTown_AthenasHouse_Text_AthenaLeaving:
	.string "ATHENA: Ok, I'll be off now, I have \n"
	.string "business to attend to in Athens.\p"
	.string "You should head over there too {PLAYER}!\n"
	.string "It's a straight line from here, you\p"
	.string "can't miss it.\p"

AthenasHouse_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

AthenasHouse_Text_TakeCareHoney:
	.string "MOM: Take care, honey!$"

AthenasHouse_Text_ReportFromPetalburgGym:
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"

AthenasHouse_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

AthenasHouse_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

AthenasHouse_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

AthenasHouse_Text_PortsInSlateportLilycove:
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"

AthenasHouse_Text_BetterGetBackToGym:
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"

AthenasHouse_Text_DadShouldStayLonger:
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"

AthenasHouse_Text_IsThatABreakingStory:
	.string "MOM: Is that a breaking news story?$"

AthenasHouse_Text_LatiEmergencyNewsFlash:
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

AthenasHouse_Text_WhatColorDidTheySay:
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

AthenasHouse_Text_StillUnknownPokemon:
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"
