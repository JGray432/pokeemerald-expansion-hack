NewAthens_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewAthens_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NewAthens_Entrance_OnTransition
	.byte 0

NewAthens_Entrance_OnLoad:
	call_if_eq VAR_NEW_ATHENS_STATE, 0, NewAthens_Entrance_EventScript_CloseDoor
	end

NewAthens_Entrance_EventScript_CloseDoor::
	setmetatile 3, 0, METATILE_Facility_NewAthensDoor_Closed_Tile0, TRUE
	setmetatile 4, 0, METATILE_Facility_NewAthensDoor_Closed_Tile1, TRUE
	setmetatile 5, 0, METATILE_Facility_NewAthensDoor_Closed_Tile2, TRUE
	setmetatile 3, 1, METATILE_Facility_NewAthensDoor_Closed_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewAthensDoor_Closed_Tile4, TRUE
	setmetatile 5, 1, METATILE_Facility_NewAthensDoor_Closed_Tile5, TRUE
	return

NewAthens_Entrance_OnTransition:
	setflag FLAG_LANDMARK_NEW_ATHENS
	end

NewAthens_Entrance_EventScript_Door::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox NewAthens_Entrance_Text_DoorIsLocked, MSGBOX_DEFAULT
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, NewAthens_Entrance_EventScript_DontOpenDoor
	msgbox NewAthens_Entrance_Text_UseBasementKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewAthens_Entrance_EventScript_DontOpenDoor
	msgbox NewAthens_Entrance_Text_UsedBasementKey, MSGBOX_DEFAULT
	setmetatile 3, 0, METATILE_Facility_NewAthensDoor_Open_Tile0, FALSE
	setmetatile 4, 0, METATILE_Facility_NewAthensDoor_Open_Tile1, FALSE
	setmetatile 5, 0, METATILE_Facility_NewAthensDoor_Open_Tile2, FALSE
	setmetatile 3, 1, METATILE_Facility_NewAthensDoor_Open_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewAthensDoor_Open_Tile4, FALSE
	setmetatile 5, 1, METATILE_Facility_NewAthensDoor_Open_Tile5, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_NEW_ATHENS_STATE, 1
	releaseall
	end

NewAthens_Entrance_EventScript_DontOpenDoor::
	releaseall
	end

NewAthens_Entrance_Text_DoorIsLocked:
	.string "The door is locked.$"

NewAthens_Entrance_Text_UseBasementKey:
	.string "Use the BASEMENT KEY?$"

NewAthens_Entrance_Text_UsedBasementKey:
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

