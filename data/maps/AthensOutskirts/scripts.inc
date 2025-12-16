.set LOCALID_DIONYSUS, 3

ATHENSOUTSKIRTS_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ATHENSOUTSKIRTS_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ATHENSOUTSKIRTS_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ATHENSOUTSKIRTS_OnFrame
	.byte 0

ATHENSOUTSKIRTS_OnTransition:
	call GabbyAndTy_EventScript_UpdateLocation
	call_if_eq VAR_ATHENS_CITY_STATE, 1, ATHENSOUTSKIRTS_Dionysus_EventScript_SetLocation
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ATHENS_OUTSKIRTS_EAST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ATHENS_OUTSKIRTS_WEST, AbnormalWeather_StartGroudonWeather
	end

ATHENSOUTSKIRTS_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ATHENS_OUTSKIRTS_EAST, AbnormalWeather_EventScript_PlaceTilesATHENSOUTSKIRTSEast
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ATHENS_OUTSKIRTS_WEST, AbnormalWeather_EventScript_PlaceTilesATHENSOUTSKIRTSWest
	end

ATHENSOUTSKIRTS_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

ATHENSOUTSKIRTS_Dionysus_EventScript_SetLocation:
	setobjectxyperm LOCALID_DIONYSUS, 18, 10
	return

ATHENSOUTSKIRTS_EventScript_Dionysus::
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, ATHENSOUTSKIRTS_EventScript_DionysusFinished
	lockall
	msgbox ATHENSOUTSKIRTS_Text_DionysusThreadRequestStart, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, ATHENSOUTSKIRTS_Movement_DionysusTurnDownFromPlayer
	waitmovement 0
	msgbox ATHENSOUTSKIRTS_Text_DionysusShudders, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, ATHENSOUTSKIRTS_Movement_DionysusTurnLeftFromPlayer
	waitmovement 0
	msgbox ATHENSOUTSKIRTS_Text_DionysusThreadRequestEnd, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkLeft
	waitmovement 0
	setflag FLAG_DELIVERED_DEVON_GOODS
	releaseall
	end

ATHENSOUTSKIRTS_EventScript_DionysusTrigger::
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, ATHENSOUTSKIRTS_EventScript_DionysusFinished
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox ATHENSOUTSKIRTS_Text_DionysusThreadRequestStart, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, ATHENSOUTSKIRTS_Movement_DionysusTurnLeftFromPlayer
	waitmovement 0
	msgbox ATHENSOUTSKIRTS_Text_DionysusShudders, MSGBOX_DEFAULT
	applymovement LOCALID_DIONYSUS, ATHENSOUTSKIRTS_Movement_DionysusTurnDownFromPlayer
	waitmovement 0
	msgbox ATHENSOUTSKIRTS_Text_DionysusThreadRequestEnd, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkLeft
	waitmovement 0
	setflag FLAG_DELIVERED_DEVON_GOODS
	releaseall
	end

ATHENSOUTSKIRTS_EventScript_DionysusFinished::
	lockall
	msgbox ATHENSOUTSKIRTS_Text_DionysusThreadRequestEnd, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, PlayerWalkLeft
	waitmovement 0
	releaseall
	end


ATHENSOUTSKIRTS_Movement_DionysusTurnLeftFromPlayer::
	walk_in_place_faster_left
	step_end

ATHENSOUTSKIRTS_Movement_DionysusTurnDownFromPlayer::
	walk_in_place_faster_down
	step_end

PlayerWalkLeft::
	walk_left
	step_end

ATHENSOUTSKIRTS_EventScript_Rose::
	trainerbattle_single TRAINER_ROSE_1, ATHENSOUTSKIRTS_Text_RoseIntro, ATHENSOUTSKIRTS_Text_RoseDefeat
	msgbox ATHENSOUTSKIRTS_Text_RosePostBattle, MSGBOX_DEFAULT
	release
	end

Route118_EventScript_Girl::
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
	end

ATHENSOUTSKIRTS_Text_DionysusThreadRequestStart:
	.string "Dionysus: Heyy, so you must be the new \p"
	.string "god I've been hearing so much about.\n"
	.string "I'm Dionysus, god of wine and draama!\p"
	.string "I guess I'm the first temple leader\n"
	.string "you've encountered?\p"
	.string "Ordinarily we could have a battle now\n"
	.string "where you could fight to earn my blessing\p"
	.string "Butt I've got bigger concerns right now.\p"
	.string "We have a huge performance for the whole \n"
	.string "of Athens tonight and Janice has ripped \l"
	.string "her costume. I would get a nymph to \l"
	.string "fix it but I lent the thread to Hephaestus.\p"
	.string "He needed it for some business in Crete, \l"
	.string "I don't know what for I wasn't listening$"

ATHENSOUTSKIRTS_Text_DionysusShudders:
	.string "(That grimy little man...) \p"
	.string "Dionysus visibly shudders$"

ATHENSOUTSKIRTS_Text_DionysusThreadRequestEnd:
	.string "Anyway my hands are full here so could you \n"
	.string "go to Crete and get the thread back for me?\p"
	.string "South of the city on Route 3 there's a sailor,\n"
	.string "I'm sure he'd take you there if you ask nicely$"

Route118_Text_CanCrossRiversWithSurf:
	.string "sup.$"


