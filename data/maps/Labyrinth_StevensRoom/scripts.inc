.set LOCALID_STEVEN, 1
.set LOCALID_MINOTAUR, 2
Labyrinth_StevensRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Labyrinth_FinalRoom_CheckPlayerJustEntered
	.byte 0

Labyrinth_FinalRoom_CheckPlayerJustEntered:
	map_script_2 VAR_ATHENS_CITY_STATE, 3, Labyrinth_FinalRoom_OnTransition
	.2byte 0

Labyrinth_FinalRoom_OnTransition::
	call_if_unset FLAG_TEMP_MINOTAUR_BATTLE_IN_PROGRESS, Labyrinth_StevensRoom_EventScript_Steven
	call_if_set FLAG_TEMP_MINOTAUR_BATTLE_IN_PROGRESS, Labyrinth_StevensRoom_EventScript_HephaestusAfterBattle
	end

Labyrinth_StevensRoom_EventScript_Steven::
	lock
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Labyrinth_FinalRoom_Movement_HephaestusMoveUp
	waitmovement 0
	msgbox Labyrinth_FinalRoom_Text_HephaestusIntro, MSGBOX_DEFAULT
	closemessage
	call Labyrinth_FinalRoom_MinotaurAppear
	return

Labyrinth_StevensRoom_EventScript_HephaestusAfterBattle::
	setvar VAR_ATHENS_CITY_STATE, 4
	clearflag FLAG_TEMP_MINOTAUR_BATTLE_IN_PROGRESS
	applymovement LOCALID_MINOTAUR, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MINOTAUR, Labyrinth_FinalRoom_Movement_MinotaurFlee
	waitmovement 0
	removeobject LOCALID_MINOTAUR
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_FaceDown
	applymovement LOCALID_STEVEN, Labyrinth_FinalRoom_Movement_HephaestusMoveRight
	waitmovement 0
	msgbox Labyrinth_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox Labyrinth_StevensRoom_Text_SeeYa, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_MONSTER01
	call Labyrinth_StevensRoom_EventScript_HephaestusExit
	playse SE_EXIT
	removeobject LOCALID_STEVEN
	setflag FLAG_HIDE_LABYRINTH_STEVEN
	release
	end

Labyrinth_FinalRoom_Movement_HephaestusMoveUp::
	walk_in_place_up
	step_end

Labyrinth_FinalRoom_MinotaurAppear::
	applymovement LOCALID_MINOTAUR, Labyrinth_FinalRoom_Movement_MinotaurAppear
	waitmovement 0
	applymovement LOCALID_STEVEN, Labyrinth_FinalRoom_Movement_HephaestusFlying
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Labyrinth_FinalRoom_Movement_ApproachMinotaur
	waitmovement 0
	setflag FLAG_TEMP_MINOTAUR_BATTLE_IN_PROGRESS
	goto Labyrinth_StevensRoom_EventScript_MinotaurBattle
	end

Labyrinth_FinalRoom_Movement_MinotaurAppear:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Labyrinth_FinalRoom_Movement_HephaestusFlying:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Labyrinth_FinalRoom_Movement_ApproachMinotaur::
	walk_down
	delay_16
	face_down
	step_end

Labyrinth_StevensRoom_EventScript_MinotaurBattle::
	trainerbattle_single  TRAINER_MINOTAUR_Labyrinth_FINALROOM, Labyrinth_Text_MinotaurIntro, Labyrinth_Minotaur_Defeated
	setvar VAR_ATHENS_CITY_STATE, 4
	clearflag FLAG_TEMP_MINOTAUR_BATTLE_IN_PROGRESS
	goto Labyrinth_StevensRoom_EventScript_HephaestusAfterBattle
	end

Labyrinth_FinalRoom_Movement_MinotaurFlee::
	walk_in_place_left
	delay_16
	walk_in_place_right
	delay_16
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end


Labyrinth_FinalRoom_Movement_HephaestusMoveRight::
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Labyrinth_StevensRoom_EventScript_HephaestusExit::
	applymovement OBJ_EVENT_ID_PLAYER, Labyrinth_StevensRoom_Movement_PlayerMoveLeft
	waitmovement 0
	applymovement LOCALID_STEVEN, Labyrinth_StevensRoom_Movement_HephaestusExit
	waitmovement 0
	return

Labyrinth_StevensRoom_Movement_PlayerMoveLeft::
	walk_left
	face_right
	delay_8
	step_end

Labyrinth_StevensRoom_Movement_HephaestusExit::
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

Labyrinth_StevensRoom_EventScript_StevenExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, Labyrinth_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, Labyrinth_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

Labyrinth_StevensRoom_EventScript_StevenExitSouth::
	applymovement OBJ_EVENT_ID_PLAYER, Labyrinth_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, Labyrinth_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

Labyrinth_StevensRoom_EventScript_BagFull::
	msgbox Labyrinth_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

Labyrinth_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

Labyrinth_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

Labyrinth_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

Labyrinth_FinalRoom_Text_HephaestusIntro:
	.string "Hm who are you?\p"
	.string "Ah nice to meet you {PLAYER}!\n"
	.string "I must say I'm impressed that you\l"
	.string "managed to traverse this labyrinth.\p"
	.string "I had to borrow some of Dio's thread \n"
	.string "and leave a trail so I could \l"
	.string "trace my steps, pretty clever eh?\p"
	.string "Anyway that reminds me, I'm here \n"
 	.string "because I heard reports that the\l"
 	.string "minotaur who lives in this labyrinth\l"
 	.string "has been going a little crazy.\p"
	.string "So keep your eyes peeled for any signs$"


Labyrinth_StevensRoom_Text_IveGotToHurryAlong:
	.string "Owww.. \p"
	.string "Thanks for covering my back there,\n"
	.string "you were really impressive! \p"
	.string "Still, I wonder what got minnie so\n"
	.string "worked up. I've got a bad feeling about\l"
	.string "this...\p"
	.string "I'll keep an eye out for any more \n"
	.string "disturbances, but we're done here so \l"
	.string "you can take this back to Dio.$"

Labyrinth_StevensRoom_Text_SeeYa:
	.string "See ya round, {PLAYER}!\n"
	.string "And thanks again for your help!$"

Labyrinth_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

Labyrinth_Text_MinotaurIntro:
	.string "MOOOOOOOO $"

Labyrinth_Minotaur_Defeated:
	.string "MINOTAUR: Hnrph!$"

