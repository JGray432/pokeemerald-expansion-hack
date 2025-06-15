.set LOCALID_DIONYSUS, 3

Athens_Outskirts_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Athens_Outskirts_OnTransition
	.byte 0

Athens_Outskirts_OnTransition:
	call_if_eq VAR_ATHENS_CITY_STATE, 1, Athens_Outskirts_Dionysus_EventScript_SetLocation
	call_if_eq VAR_ATHENS_CITY_STATE, 2, Athens_Outskirts_Dionysus_EventScript_SetLocation
	removeobject LOCALID_DIONYSUS
	end


Athens_Outskirts_Dionysus_EventScript_SetLocation:
	setobjectxyperm LOCALID_DIONYSUS, 18, 10
	return

Athens_Outskirts_EventScript_Dionysus::
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, Athens_Outskirts_EventScript_DionysusFinished
	lockall
	msgbox Athens_Outskirts_Text_DionysusThreadRequestStart, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, Athens_Outskirts_Movement_DionysusTurnDownFromPlayer
	waitmovement 0
	msgbox Athens_Outskirts_Text_DionysusShudders, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, Athens_Outskirts_Movement_DionysusTurnLeftFromPlayer
	waitmovement 0
	msgbox Athens_Outskirts_Text_DionysusThreadRequestEnd, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkLeft
	waitmovement 0
	setflag FLAG_DELIVERED_DEVON_GOODS
	setvar VAR_ATHENS_CITY_STATE, 2
	releaseall
	end

Athens_Outskirts_EventScript_DionysusTrigger::
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, Athens_Outskirts_EventScript_DionysusFinished
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox Athens_Outskirts_Text_DionysusThreadRequestStart, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, Athens_Outskirts_Movement_DionysusTurnLeftFromPlayer
	waitmovement 0
	msgbox Athens_Outskirts_Text_DionysusShudders, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, Athens_Outskirts_Movement_DionysusTurnDownFromPlayer
	waitmovement 0
	msgbox Athens_Outskirts_Text_DionysusThreadRequestEnd, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkLeft
	waitmovement 0
	setflag FLAG_DELIVERED_DEVON_GOODS
 	setvar VAR_ATHENS_CITY_STATE, 2
	releaseall
	end

Athens_Outskirts_EventScript_DionysusFinished::
	lockall
	msgbox Athens_Outskirts_Text_DionysusThreadRequestEnd, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkLeft
	waitmovement 0
	releaseall
	end


Athens_Outskirts_Movement_DionysusTurnLeftFromPlayer::
	walk_in_place_faster_left
	step_end

Athens_Outskirts_Movement_DionysusTurnDownFromPlayer::
	walk_in_place_faster_down
	step_end

PlayerWalkLeft::
	walk_left
	step_end

Athens_Outskirts_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE_1, Athens_Outskirts_Text_RoseIntro, Athens_Outskirts_Text_RoseDefeat
	msgbox Athens_Outskirts_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

Athens_Outskirts_Text_DionysusThreadRequestStart:
	.string "Dionysus: Heyy, so you must be the new \n"
	.string "God I've been hearing so much about.\p"
	.string "I'm Dionysus, god of wine and draama!\p"
	.string "I guess I'm the first temple leader\n"
	.string "you've encountered?\p"
	.string "Ordinarily we could have a battle now\n"
	.string "where you could fight to earn my \l"
	.string "divine blessing.\p"
	.string "Butt I've got bigger concerns \n"
	.string "right now.\p"
	.string "We have a huge performance for the \n"
	.string "whole of Athens tonight and Janice\l"
	.string "has ripped her costume.\p"
	.string "I would usually get a nymph to fix it\n"
	.string "but I lent the thread to Hephaestus.\p"
	.string "He needed it for some business in Crete, \n"
	.string "Lord knows what for I wasn't listening$"

Athens_Outskirts_Text_DionysusShudders:
	.string "(That grimy little man...) \p"
	.string "...Dionysus visibly shudders...$"

Athens_Outskirts_Text_DionysusThreadRequestEnd:
	.string "Anyway my hands are full here so \n"
	.string "could you go to Crete and get the \l"
	.string "thread back for me?\p"
	.string "South of the city on Route 3 there's \n"
	.string "a sailor, I'm sure he'd take you there \l"
	.string "if you ask nicely!$"

Route118_Text_CanCrossRiversWithSurf:
	.string "sup.$"


