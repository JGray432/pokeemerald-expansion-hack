.set LOCALID_BEAUTY, 5
.set LOCALID_MOM, 3

ArchiTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ArchiTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ArchiTown_OnFrame
	.byte 0

	@ State descriptions for VAR_ARCHI_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_ARCHI_INTRO_STATE
	@ 1: In truck
	@ 2: Entered house
	@ 3: Told to choose starter
	@ 4: Starter chosen

	@ State descriptions for VAR_ARCHI_HOUSES_STATE_MAY
	@                    and VAR_ARCHI_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_ARCHI_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


ArchiTown_OnTransition:
	setflag FLAG_VISITED_ARCHI_TOWN
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_ARCHI_INTRO_STATE, 1, ArchiTown_EventScript_SetMomInFrontOfDoor
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, ArchiTown_EventScript_HideMapNamePopup
	end

ArchiTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

ArchiTown_OnFrame:
	map_script_2 VAR_ARCHI_INTRO_STATE, 1, ArchiTown_EventScript_StepOffTruck
	.2byte 0

ArchiTown_EventScript_StepOffTruck::
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	call ArchiTown_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_ARCHI_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	warpsilent MAP_ARCHI_TOWN_ATHENAS_HOUSE, 8, 8
	waitstate
	releaseall
	end

ArchiTown_EventScript_SetMomInFrontOfDoor::
	setobjectxyperm LOCALID_MOM, 5, 8
	return

ArchiTown_EventScript_GoInsideWithMom::
	delay 15
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, ArchiTown_Movement_PlayerStepOffTruck
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, ArchiTown_Movement_MomExitHouse
	waitmovement 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	delay 10
	applymovement LOCALID_MOM, ArchiTown_Movement_MomApproachPlayerAtTruck
	waitmovement 0
	msgbox ArchiTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, ArchiTown_Movement_MomApproachDoor
	applymovement OBJ_EVENT_ID_PLAYER, ArchiTown_Movement_PlayerApproachDoor
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_MOM, ArchiTown_Movement_MomEnterHouse
	applymovement OBJ_EVENT_ID_PLAYER, ArchiTown_Movement_PlayerEnterHouse
	waitmovement 0
	setflag FLAG_HIDE_ARCHI_TOWN_MOM_OUTSIDE
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_ARCHI_TOWN_FAT_MAN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	// new test
	setvar VAR_ARCHI_TOWN_STATE, 1
	setvar VAR_ARCHI_INTRO_STATE, 2
	setvar VAR_ARCHI_HOUSES_STATE_MAY, 2
	setvar VAR_ARCHI_HOUSES_STATE_BRENDAN, 2
	setvar VAR_ARCHI_RIVAL_STATE, 3
	return

ArchiTown_Movement_MomExitHouse:
	walk_down
	step_end

ArchiTown_Movement_MomApproachPlayerAtTruck:
	walk_down
	walk_in_place_faster_left
	step_end

ArchiTown_Movement_MomApproachDoor:
	delay_16
	delay_8
	walk_up
	step_end

ArchiTown_Movement_MomEnterHouse:
	walk_up
	set_invisible
	step_end

ArchiTown_Movement_PlayerApproachDoor:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_up
	step_end

ArchiTown_Movement_PlayerEnterHouse:
	walk_up
	walk_up
	step_end

ArchiTown_Movement_PlayerStepOffTruck:
	jump_right
	delay_16
	delay_16
	delay_16
	step_end

ArchiTown_EventScript_FisherMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, ArchiTown_EventScript_Sucker
	showmoneybox 0, 0
	msgbox ArchiTown_Text_GiveSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ArchiTown_EventScript_DeclineSuperRod
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, ArchiTown_EventScript_NotEnoughMoney
	call_if_eq VAR_RESULT, TRUE, ArchiTown_EventScript_RemoveMoney
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_SUPER_ROD
	waitfanfare
	hidemoneybox
	setflag FLAG_RECEIVED_SUPER_ROD
	release
	end

ArchiTown_EventScript_Sucker::
	msgbox ArchiTown_Text_Sucker, MSGBOX_NPC
	closemessage
	end

ArchiTown_EventScript_DeclineSuperRod::
	msgbox ArchiTown_Text_DeclineSuperRod, MSGBOX_NPC
	closemessage
	hidemoneybox
	release
	end

ArchiTown_EventScript_NotEnoughMoney::
	msgbox ArchiTown_Text_NotEnoughMoney, MSGBOX_NPC
	closemessage
	hidemoneybox
	release
	end

ArchiTown_EventScript_RemoveMoney::
	removemoney 500
	updatemoneybox
	return

ArchiTown_EventScript_Beauty::
	goto_if_set FLAG_RECEIVED_INF_REPEL, ArchiTown_EventScript_BeautyAlreadyGaveRepel
	msgbox ArchiTown_Text_GiveInfRepelStart, MSGBOX_NPC
	call_if_eq VAR_FACING, DIR_SOUTH, ArchiTown_EventScript_BeautyFaceAwayNorth
	call_if_eq VAR_FACING, DIR_NORTH, ArchiTown_EventScript_BeautyFaceAwaySouth
	call_if_eq VAR_FACING, DIR_WEST, ArchiTown_EventScript_BeautyFaceAwayEast
	call_if_eq VAR_FACING, DIR_EAST, ArchiTown_EventScript_BeautyFaceAwayWest
	msgbox ArchiTown_Text_TakeThatBusinessSchool, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_SOUTH, ArchiTown_EventScript_BeautyFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, ArchiTown_EventScript_BeautyFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, ArchiTown_EventScript_BeautyFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, ArchiTown_EventScript_BeautyFaceAwayEast
	msgbox ArchiTown_Text_GiveInfRepelEnd, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_INF_REPEL
	waitfanfare
	setflag FLAG_RECEIVED_INF_REPEL
	closemessage
	release
	end

ArchiTown_EventScript_BeautyFaceAwaySouth::
	applymovement LOCALID_BEAUTY, ArchiTown_Movement_BeautyFaceAwaySouth
	waitmovement 0
	return

ArchiTown_Movement_BeautyFaceAwaySouth:
	walk_in_place_up
	step_end

ArchiTown_EventScript_BeautyFaceAwayNorth::
	applymovement LOCALID_BEAUTY, ArchiTown_Movement_BeautyFaceAwayNorth
	waitmovement 0
	return
	
ArchiTown_Movement_BeautyFaceAwayNorth:
	walk_in_place_down
	step_end

ArchiTown_EventScript_BeautyFaceAwayWest::
	applymovement LOCALID_BEAUTY, ArchiTown_Movement_BeautyFaceAwayWest
	waitmovement 0
	return
	
ArchiTown_Movement_BeautyFaceAwayWest:
	walk_in_place_right
	step_end

ArchiTown_EventScript_BeautyFaceAwayEast::
	applymovement LOCALID_BEAUTY, ArchiTown_Movement_BeautyFaceAwayEast
	waitmovement 0
	return
	
ArchiTown_Movement_BeautyFaceAwayEast:
	walk_in_place_left
	step_end

ArchiTown_EventScript_BeautyAlreadyGaveRepel::
	msgbox ArchiTown_Text_AlreadyGaveInfRepel, MSGBOX_NPC
	closemessage
	end

ArchiTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart ArchiTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
ArchiTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	pokemartlistend

ArchiTown_EventScript_TownSign::
	msgbox ArchiTown_Text_TownSign, MSGBOX_SIGN
	end

ArchiTown_EventScript_BirchsLabSign::
	msgbox ArchiTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

ArchiTown_EventScript_PlayersHouseSignMale::
	msgbox ArchiTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

ArchiTown_EventScript_BirchsHouseSignMale::
	msgbox ArchiTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

ArchiTown_EventScript_PlayersHouseSignFemale::
	msgbox ArchiTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

ArchiTown_Text_OurNewHomeLetsGoInside:
	.string "ATHENA: Hi!$"

ArchiTown_Text_GiveSuperRod:
	.string "(ah great here comes a sucker...)\p"
	.string "Boy, have I got a deal for you!\n"
	.string "Quite possibly the greatest deal \l"
	.string "in the history of the world. \p"
	.string "I hold in my hands a one-of-a-kind\n"
	.string "magic rod, yours for the measly \l"
	.string "price of ¥500 $"

ArchiTown_Text_Sucker:
	.string "Fish-ing? What the heck is that?$"

ArchiTown_Text_DeclineSuperRod:
	.string "Pff this deal is too good for \n"
	.string "the likes of you anyway$"

ArchiTown_Text_NotEnoughMoney:
	.string "Sorry pal, you're broke.\n"
	.string "Hmm maybe I should have picked a richer\p"
	.string "neighbourhood to scam...$"

ArchiTown_Text_GiveInfRepelStart:
	.string "HA! I knew I wasn't crazy for starting\n"
	.string "a perfume franchise in the middle \l"
	.string "of the woods. \n"

ArchiTown_Text_TakeThatBusinessSchool:
	.string "Take that, business college!$"

ArchiTown_Text_GiveInfRepelEnd:
	.string "Ahem. In light of my great success \n"
	.string "you can take this first sample for free \p"
	.string "Even if it's not your style I'm sure \n"
	.string "it'll be good for something.$"

ArchiTown_Text_AlreadyGaveInfRepel:
	.string "What!? You say my perfume is so repulsive\n"
	.string "that it acts as a repel for wild pokemon?\p"
	.string "Paha! Good joke, you are a funny one!$"

ArchiTown_Text_TownSign:
	.string "ARCHI TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

ArchiTown_Text_ProfBirchsLab:
	.string "PROF. BIRCH'S POKéMON LAB$"

ArchiTown_Text_PlayersHouse:
	.string "{PLAYER}'s HOUSE$"

ArchiTown_Text_ProfBirchsHouse:
	.string "PROF. BIRCH'S HOUSE$"

