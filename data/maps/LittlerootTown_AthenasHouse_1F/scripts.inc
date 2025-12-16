.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_AthenasHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	.2byte 0

LittlerootTown_AthenasHouse_1F_EventScript_Bag::
	lock
	faceplayer
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
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	release
	end

LittleRootTown_AthenasHouse_1F_EventScript_GiveKeyItems::
	msgbox LittlerootTown_AthenasHouse_Text_GiveKeyItems MSGBOX_DEFAULT
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
	goto AthenasHouse_1F_EventScript_AthenaExitHouse
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto AthenasHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_AthenasHouse_1F_EventScript_GoSeeBag::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto AthenasHouse_1F_EventScript_AthenaGoSeeBag
	end

LittlerootTown_AthenasHouse_1F_EventScript_AthenaFiredUp::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto AthenasHouse_1F_EventScript_AthenaFiredUp
	end


AthenasHouse_1F_Text_IsntItNiceInHere:
	.string "MOM: See, {PLAYER}?\n"
	.string "Isn't it nice in here, too?$"

AthenasHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Now, that bag on the table contains\n"
	.string "some offerings I recently received.\l"
	.string "But frankly I receive more gifts\p"
	.string "than I know what to do with, so why\n"
	.string "don't you check it ou instead?\p"

AthenasHouse_1F_Text_ArentYouInterestedInBag:
	.string "MOM: Well, {PLAYER}?\p"
	.string "Aren't you interested in seeing what's\n"
	.string "in the bag?$"

AthenasHouse_1F_Text_AthenaFiredUp:
	.string "Athena: Great choice {PLAYER}!\n"
	.string "Seeing you two together has lit\l"
	.string "a fire in me, I think I'll start\l"
	.string "my own new adventure too!\p"
	.string "I'll take this little guy.\n"
	.string "Hey, why don't I give you a taste of \n$"
	.string "what being a trainer is all about? \l$"

Athenas_House_Text_ATHENADefeated:
	.string "ATHENA: Oh, I lost…\n"
	.string "But that was fun!$"

AthenasHouse_1F_Text_AthenaSendOff:
	.string "Athena: Wow, that was fun!\n"

LittlerootTown_AthenasHouse_Text_GiveKeyItems:
	.string "Here are some useful\n"
	.string "items to help start your journey\l"

LittlerootTown_AthenasHouse_Text_ReceivedInfCandy:
	.string "{PLAYER} received the Inf Candy!$"

LittlerootTown_AthenasHouse_Text_ReceivedInfRepel:
	.string "{PLAYER} received the Inf Repel!$"

LittlerootTown_AthenasHouse_Text_ReceivedNectarReserves:
	.string "{PLAYER} received the Nectar Reserves!$"

LittlerootTown_AthenasHouse_Text_ReceivedCapCandy:
	.string "{PLAYER} received the Level Cap Candy!$"

LittlerootTown_AthenasHouse_Text_AthenaLeaving:
	.string "ATHENA: Ok, I'll be off now, I have \n"
	.string "business to attend to in Athens.\p"
	.string "You should head over there too {PLAYER}!\n"
	.string "It's a straight line from here, you\p"
	.string "can't miss it.\p"

AthenasHouse_1F_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

AthenasHouse_1F_Text_TakeCareHoney:
	.string "MOM: Take care, honey!$"

AthenasHouse_1F_Text_ReportFromPetalburgGym:
	.string "INTERVIEWER: …We brought you this\n"
	.string "report from in front of PETALBURG GYM.$"

AthenasHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

AthenasHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

AthenasHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

AthenasHouse_1F_Text_PortsInSlateportLilycove:
	.string "DAD: Hm, a TICKET for a ferry?\p"
	.string "If I recall, there are ferry ports in\n"
	.string "SLATEPORT and LILYCOVE.$"

AthenasHouse_1F_Text_BetterGetBackToGym:
	.string "I'd better get back to PETALBURG GYM.\p"
	.string "MOM, thanks for looking after the house\n"
	.string "while I'm away.$"

AthenasHouse_1F_Text_DadShouldStayLonger:
	.string "MOM: That DAD of yours…\p"
	.string "He comes home for the first time in a\n"
	.string "while, but all he talks about is POKéMON.\p"
	.string "He should relax and stay a little longer.$"

AthenasHouse_1F_Text_IsThatABreakingStory:
	.string "MOM: Is that a breaking news story?$"

AthenasHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "We bring you this emergency\n"
	.string "news flash!\p"
	.string "In various HOENN locales, there have\n"
	.string "been reports of a BZZT…colored\l"
	.string "POKéMON in flight.\p"
	.string "The identity of this POKéMON is\n"
	.string "currently unknown.\p"
	.string "We now return you to the regular\n"
	.string "movie program.$"

AthenasHouse_1F_Text_WhatColorDidTheySay:
	.string "MOM: {PLAYER}, did you catch that?\p"
	.string "What color did the announcer say\n"
	.string "that POKéMON was?$"

AthenasHouse_1F_Text_StillUnknownPokemon:
	.string "MOM: Well, isn't that something!\n"
	.string "There are still unknown POKéMON.$"
