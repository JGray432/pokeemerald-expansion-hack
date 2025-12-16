.set LOCALID_DIONYSUS, 3

Athens_Outskirts_MapScripts::
	.byte 0

Athens_Outskirts_EventScript_Dionysus::
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Athens_Outskirts_EventScript_DionysusPerformance
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, Athens_Outskirts_EventScript_DionysusFinished
	lockall
	msgbox Athens_Outskirts_Text_DionysusThreadRequestStart, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, Common_Movement_FaceRight
	waitmovement 0
	msgbox Athens_Outskirts_Text_DionysusShudders, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, Common_Movement_FaceDown
	waitmovement 0
	msgbox Athens_Outskirts_Text_DionysusThreadRequestEnd, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkDown
	waitmovement 0
	setflag FLAG_DELIVERED_DEVON_GOODS
	setvar VAR_ATHENS_CITY_STATE, 2
	releaseall
	end

Athens_Outskirts_EventScript_DionysusTrigger::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement LOCALID_DIONYSUS, Common_Movement_FaceRight
	waitmovement 0
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, Athens_Outskirts_EventScript_DionysusPerformance
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, Athens_Outskirts_EventScript_DionysusFinished	
	msgbox Athens_Outskirts_Text_DionysusThreadRequestStart, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, Common_Movement_FaceDown
	waitmovement 0
	msgbox Athens_Outskirts_Text_DionysusShudders, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, Common_Movement_FaceRight
	waitmovement 0
	msgbox Athens_Outskirts_Text_DionysusThreadRequestEnd, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkDown
	waitmovement 0
	setflag FLAG_DELIVERED_DEVON_GOODS
 	setvar VAR_ATHENS_CITY_STATE, 2
	releaseall
	end

Athens_Outskirts_EventScript_DionysusFinished::
	lockall
	applymovement LOCALID_DIONYSUS, Common_Movement_FacePlayer
	msgbox Athens_Outskirts_Text_DionysusThreadRequestEnd, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkDown
	waitmovement 0
	releaseall
	end

Athens_Outskirts_EventScript_DionysusPerformance::
 lockall
 msgbox Athens_Outskirts_Text_DionysusPerformance, MSGBOX_DEFAULT
 closemessage
 setflag FLAG_DELIVERED_THREAD
 setvar VAR_ATHENS_CITY_STATE, 5
 fadescreenspeed FADE_TO_BLACK, 24
 fadescreenspeed FADE_FROM_BLACK, 24
 releaseall
 end

Athens_Outskirts_Movement_DionysusTurnLeftFromPlayer::
	walk_in_place_faster_left
	step_end

Athens_Outskirts_Movement_DionysusTurnDownFromPlayer::
	walk_in_place_faster_down
	step_end

PlayerWalkDown::
	walk_down
	step_end

Athens_Outskirts_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE_1, Athens_Outskirts_Text_RoseIntro, Athens_Outskirts_Text_RoseDefeat
	msgbox Athens_Outskirts_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Athens_Outskirts_EventScript_Amani::
	trainerbattle_single TRAINER_AMANI, Athens_Outskirts_Text_RoseIntro, Athens_Outskirts_Text_RoseDefeat
	msgbox Athens_Outskirts_Text_RosePostBattle, MSGBOX_DEFAULT
	release
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
	.string "has ripped her costume...\p"
	.string "I would usually get a nymph to fix it\n"
	.string "but I lent the thread to Hephaestus.\p"
	.string "He needed it for some business in Crete, \n"
	.string "Lord knows what for I wasn't listening.$"

Athens_Outskirts_Text_DionysusShudders:
	.string "(That grimy little man...) \p"
	.string "...Dionysus visibly shudders...$"

Athens_Outskirts_Text_DionysusThreadRequestEnd:
	.string "Anyway my hands are full here so \n"
	.string "could you go to Crete and get the \l"
	.string "thread back for me?\p"
	.string "South of the city on Route 3 there's \n"
	.string "a sailor, tell him I'll pay him back \l"
	.string "later if he takes you now!$"

Athens_Outskirts_Text_DionysusPerformance:
 .string "Dionysus: You got the thread!\n"
 .string "You're a lifesaver babes, we were\l"
 .string "moments away from total meltdown here.\p"
 .string "To pay you back you can have front row \n"
 .string "seats to our fabulous production.\p"
 .string "Hm, oh sure we can battle afterwards too.$"

Route118_Text_CanCrossRiversWithSurf:
	.string "sup.$"


