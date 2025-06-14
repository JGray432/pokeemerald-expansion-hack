.set LOCALID_STEVEN, 1
.set LOCALID_MINOTAUR, 2
GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_FinalRoom_EventScript_MinotaurTrigger::
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, GraniteCave_StevensRoom_EventScript_Steven
	end

GraniteCave_StevensRoom_EventScript_Steven::
	lock
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, GraniteCave_FinalRoom_Movement_HephaestusMoveUp
	waitmovement 0
	msgbox GraniteCave_FinalRoom_Text_HephaestusIntro, MSGBOX_DEFAULT
	closemessage
	goto GraniteCave_FinalRoom_MinotaurAppear
	delay 30
	goto GraniteCave_StevensRoom_EventScript_MinotaurBattle
	end

GraniteCave_StevensRoom_EventScript_HephaestusAfterBattle::
	applymovement LOCALID_MINOTAUR, GraniteCave_FinalRoom_Movement_MinotaurFlee
	waitmovement 0
	removeobject LOCALID_MINOTAUR
	applymovement LOCALID_STEVEN, GraniteCave_FinalRoom_Movement_HephaestusMoveRight
	waitmovement 0
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_BADGE01_GET
	setvar VAR_ATHENS_CITY_STATE, 4
	call GraniteCave_StevensRoom_EventScript_HephaestusExit
	playse SE_EXIT
	removeobject LOCALID_STEVEN
	release
	end

GraniteCave_FinalRoom_Movement_HephaestusMoveUp::
	walk_up
	step_end

GraniteCave_FinalRoom_MinotaurAppear::
	applymovement LOCALID_MINOTAUR, GraniteCave_FinalRoom_Movement_MinotaurAppear
	waitmovement 0
	applymovement LOCALID_STEVEN, GraniteCave_FinalRoom_Movement_HephaestusFlying
	waitmovement 0
	return

GraniteCave_FinalRoom_Movement_MinotaurAppear:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

GraniteCave_FinalRoom_Movement_HephaestusFlying:
	walk_fast_left
	step_end

GraniteCave_StevensRoom_EventScript_MinotaurBattle::
	trainerbattle_no_intro TRAINER_MINOTAUR_GRANITECAVE_FINALROOM, GraniteCave_Minotaur_Defeated
	goto GraniteCave_StevensRoom_EventScript_HephaestusAfterBattle
	end

GraniteCave_FinalRoom_Movement_MinotaurFlee::
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


GraniteCave_FinalRoom_Movement_HephaestusMoveRight::
	walk_right
	face_up
	step_end

GraniteCave_StevensRoom_EventScript_HephaestusExit::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerMoveLeft
	waitmovement 0
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_HephaestusExit
	waitmovement 0
	return

GraniteCave_StevensRoom_Movement_PlayerMoveLeft::
	walk_left
	face_right
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_HephaestusExit::
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_EventScript_StevenExitWestEast::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_StevenExitSouth::
	applymovement OBJ_EVENT_ID_PLAYER, GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Movement_PlayerTurnTowardExit:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_FinalRoom_Text_HephaestusIntro:
	.string "My name is STEVEN.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "STEVEN: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "STEEL WING.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "STEVEN: Your POKéMON appear quite\n"
	.string "capable.\p"
	.string "If you keep training, you could even\n"
	.string "become the CHAMPION of the POKéMON\l"
	.string "LEAGUE one day. That's what I think.\p"
	.string "I know, since we've gotten to know each\n"
	.string "other, let's register one another in\l"
	.string "our POKéNAVS.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Registered STEVEN\n"
	.string "in the POKéNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "Now, I've got to hurry along.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

GraniteCave_Minotaur_Defeated:
	.string "MINOTAUR: Hnrph!$"

