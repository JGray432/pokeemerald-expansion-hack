.set LOCALID_BIRCH, 2
.set LOCALID_ZIGZAGOON, 4

Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route1_OnFrame
	.byte 0

Route1_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route1_OnFrame:
	map_script_2 VAR_ROUTE1_STATE, 0, Route1_EventScript_HideMapNamePopup
	.2byte 0

Route1_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE1_STATE, 1
	end

Route1_EventScript_Youngster::
	trainerbattle_single TRAINER_CALVIN_1, ROUTE2_Text_CalvinIntro, ROUTE2_Text_CalvinDefeated, ROUTE2_EventScript_CalvinRegisterMatchCallAfterBattle
	msgbox ROUTE2_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end


Route1_EventScript_RouteSign::
	msgbox Route1_Text_RouteSign, MSGBOX_SIGN
	end


Route1_Text_RouteSign:
	.string "ROUTE 1\n"
	.string "{RIGHT_ARROW} WOODS$"

