.set LOCALID_BEAUTY, 5
.set LOCALID_MOM, 3

LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Met Rival
	@ 2: Saving Birch
	@ 3: Received Pokedex
	@ 4: Received Running Shoes

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: In truck
	@ 2: Entered house
	@ 3: Told to choose starter
	@ 4: Starter chosen

	@ State descriptions for VAR_LITTLEROOT_HOUSES_STATE_MAY
	@                    and VAR_LITTLEROOT_HOUSES_STATE_BRENDAN
	@ 1: On Truck (and is corresponding gender)
	@ 2: Met Rival's Mom (and is corresponding gender)
	@ 3: Entered Hall of Fame
	@ 4: Completed Lati TV / SS Ticket event
	@ 5: Exited house after above event

	@ State descriptions for VAR_LITTLEROOT_RIVAL_STATE
	@ 1: Never occurs
	@ 2: Entered Rival's bedroom
	@ 3: Met Rival
	@ 4: Received Pokedex


LittlerootTown_OnTransition:
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	call Common_EventScript_SetupRivalGfxId
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_SetMomInFrontOfDoor
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1, LittlerootTown_EventScript_HideMapNamePopup
	end

LittlerootTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_StepOffTruck
	.2byte 0

LittlerootTown_EventScript_StepOffTruck::
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_GoInsideWithMom
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	warpsilent MAP_LITTLEROOT_TOWN_ATHENAS_HOUSE, 8, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_SetMomInFrontOfDoor::
	setobjectxyperm LOCALID_MOM, 5, 8
	return

LittlerootTown_EventScript_GoInsideWithMom::
	delay 15
	playse SE_LEDGE
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerStepOffTruck
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	addobject LOCALID_MOM
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomExitHouse
	waitmovement 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	delay 10
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachPlayerAtTruck
	waitmovement 0
	msgbox LittlerootTown_Text_OurNewHomeLetsGoInside, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomApproachDoor
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerApproachDoor
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LOCALID_MOM, LittlerootTown_Movement_MomEnterHouse
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerEnterHouse
	waitmovement 0
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	// new test
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	return

LittlerootTown_Movement_MomExitHouse:
	walk_down
	step_end

LittlerootTown_Movement_MomApproachPlayerAtTruck:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_Movement_MomApproachDoor:
	delay_16
	delay_8
	walk_up
	step_end

LittlerootTown_Movement_MomEnterHouse:
	walk_up
	set_invisible
	step_end

LittlerootTown_Movement_PlayerApproachDoor:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_Movement_PlayerEnterHouse:
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_PlayerStepOffTruck:
	jump_right
	delay_16
	delay_16
	delay_16
	step_end

LittlerootTown_EventScript_FisherMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, LittlerootTown_EventScript_Sucker
	showmoneybox 0, 0
	msgbox LittlerootTown_Text_GiveSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_EventScript_DeclineSuperRod
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, LittlerootTown_EventScript_NotEnoughMoney
	call_if_eq VAR_RESULT, TRUE, LittlerootTown_EventScript_RemoveMoney
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_SUPER_ROD
	waitfanfare
	msgbox LittlerootTown_Text_Sucker, MSGBOX_NPC
	closemessage
	hidemoneybox
	setflag FLAG_RECEIVED_SUPER_ROD
	release
	end

LittlerootTown_EventScript_Sucker::
	msgbox LittlerootTown_Text_Sucker, MSGBOX_NPC
	closemessage
	end

LittlerootTown_EventScript_DeclineSuperRod::
	msgbox LittlerootTown_Text_DeclineSuperRod, MSGBOX_NPC
	closemessage
	hidemoneybox
	release
	end

LittlerootTown_EventScript_NotEnoughMoney::
	msgbox LittlerootTown_Text_NotEnoughMoney, MSGBOX_NPC
	closemessage
	hidemoneybox
	release
	end

LittlerootTown_EventScript_RemoveMoney::
	removemoney 500
	updatemoneybox
	return

LittlerootTown_EventScript_Beauty::
	goto_if_set FLAG_RECEIVED_INF_REPEL, LittlerootTown_EventScript_BeautyAlreadyGaveRepel
	msgbox LittlerootTown_Text_GiveInfRepelStart, MSGBOX_NPC
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_EventScript_BeautyFaceAwayNorth
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_EventScript_BeautyFaceAwaySouth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_EventScript_BeautyFaceAwayEast
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_EventScript_BeautyFaceAwayWest
	msgbox LittlerootTown_Text_TakeThatBusinessSchool, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_EventScript_BeautyFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_EventScript_BeautyFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_EventScript_BeautyFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_EventScript_BeautyFaceAwayEast
	msgbox LittlerootTown_Text_GiveInfRepelEnd, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	giveitem ITEM_INF_REPEL
	waitfanfare
	setflag FLAG_RECEIVED_INF_REPEL
	closemessage
	release
	end

LittlerootTown_EventScript_BeautyFaceAwaySouth::
	applymovement LOCALID_BEAUTY, LittlerootTown_Movement_BeautyFaceAwaySouth
	waitmovement 0
	return

LittlerootTown_Movement_BeautyFaceAwaySouth:
	walk_in_place_up
	step_end

LittlerootTown_EventScript_BeautyFaceAwayNorth::
	applymovement LOCALID_BEAUTY, LittlerootTown_Movement_BeautyFaceAwayNorth
	waitmovement 0
	return
	
LittlerootTown_Movement_BeautyFaceAwayNorth:
	walk_in_place_down
	step_end

LittlerootTown_EventScript_BeautyFaceAwayWest::
	applymovement LOCALID_BEAUTY, LittlerootTown_Movement_BeautyFaceAwayWest
	waitmovement 0
	return
	
LittlerootTown_Movement_BeautyFaceAwayWest:
	walk_in_place_right
	step_end

LittlerootTown_EventScript_BeautyFaceAwayEast::
	applymovement LOCALID_BEAUTY, LittlerootTown_Movement_BeautyFaceAwayEast
	waitmovement 0
	return
	
LittlerootTown_Movement_BeautyFaceAwayEast:
	walk_in_place_left
	step_end

LittlerootTown_EventScript_BeautyAlreadyGaveRepel::
	msgbox LittlerootTown_Text_AlreadyGaveInfRepel, MSGBOX_NPC
	closemessage
	end

LittlerootTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LittlerootTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LittlerootTown_Mart_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	pokemartlistend

LittlerootTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BirchsLabSign::
	msgbox LittlerootTown_Text_ProfBirchsLab, MSGBOX_SIGN
	end

LittlerootTown_EventScript_PlayersHouseSignMale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_BirchsHouseSignMale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_PlayersHouseSignFemale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_Text_OurNewHomeLetsGoInside:
	.string "ATHENA: Hi!$"

LittlerootTown_Text_GiveSuperRod:
	.string "Boy, have I got a deal for you!\n"
	.string "Quite possibly the greatest deal \l"
	.string "in the history of the world \p"
	.string "I hold in my hands a one-of-a-kind\n"
	.string "magic stick, yours for the measly \l"
	.string "price of ¥500 $"

LittlerootTown_Text_Sucker:
	.string "Hehe sucker, it's just a stick!$"

LittlerootTown_Text_DeclineSuperRod:
	.string "Pff this deal is too good for \n"
	.string "the likes of you anyway$"

LittlerootTown_Text_NotEnoughMoney:
	.string "Sorry pal, you're broke.\n"
	.string "Hmm maybe I should have picked a richer\p"
	.string "neighbourhood to scam...$"

LittlerootTown_Text_GiveInfRepelStart:
	.string "HA! I knew I wasn't crazy for starting\n"
	.string "a perfume franchise in the middle \l"
	.string "of the woods \n"

LittlerootTown_Text_TakeThatBusinessSchool:
	.string "Take that, business college!$"

LittlerootTown_Text_GiveInfRepelEnd:
	.string "Ahem. In light of my great success \n"
	.string "you can take this firstsample for free \p"
	.string "Even if it's not your style I'm sure \n"
	.string "it'll be good for something.$"

LittlerootTown_Text_AlreadyGaveInfRepel:
	.string "What!? You say my perfume is so repulsive\n"
	.string "that it acts as a repel for wild pokemon?\p"
	.string "Paha! Good joke, you are a funny one!$"

LittlerootTown_Text_TownSign:
	.string "LITTLEROOT TOWN\n"
	.string "“A town that can't be shaded any hue.”$"

LittlerootTown_Text_ProfBirchsLab:
	.string "PROF. BIRCH'S POKéMON LAB$"

LittlerootTown_Text_PlayersHouse:
	.string "{PLAYER}'s HOUSE$"

LittlerootTown_Text_ProfBirchsHouse:
	.string "PROF. BIRCH'S HOUSE$"

