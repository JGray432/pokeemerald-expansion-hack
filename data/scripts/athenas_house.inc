@ Local IDs are the same for both players houses
.set LOCALID_MOM, 1
.set LOCALID_DAD, 5
.set LOCALID_MOM_2F, 14

AthenasHouse_2F_EventScript_BlockStairsUntilClockIsSet::
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	return

AthenasHouse_1F_EventScript_EnterHouseMovingIn::
	msgbox AthenasHouse_1F_Text_IsntItNiceInHere, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	call_if_eq VAR_0x8005, MALE, AthenasHouse_1F_EventScript_MomFacePlayerMovingInMale
	call_if_eq VAR_0x8005, FEMALE, AthenasHouse_1F_EventScript_MomFacePlayerMovingInFemale
	msgbox AthenasHouse_1F_Text_MoversPokemonGoSetClock, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	applymovement OBJ_EVENT_ID_PLAYER, AthenasHouse_1F_Movement_PlayerWalkIn
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

AthenasHouse_1F_EventScript_MomFacePlayerMovingInMale::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

AthenasHouse_1F_EventScript_MomFacePlayerMovingInFemale::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

AthenasHouse_1F_Movement_PlayerWalkIn:
	walk_up
	step_end

AthenasHouse_1F_EventScript_AthenaGoSeeBag::
	msgbox AthenasHouse_1F_Text_ArentYouInterestedInBag, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, AthenasHouse_1F_Movement_MovePlayerAwayFromDoor
	waitmovement 0
	releaseall
	end

AthenasHouse_1F_EventScript_AthenaFiredUp::
	msgbox AthenasHouse_1F_Text_AthenaFiredUp, MSGBOX_DEFAULT
	closemessage
	switch VAR_STARTER_MON
	case 0, AthenasHouse_EventScript_StartAthenaBattleAbra
	case 1, AthenasHouse_EventScript_StartAthenaBattleJangmoo
	case 2, AthenasHouse_EventScript_StartAthenaBattlePawniard
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end

AthenasHouse_EventScript_StartAthenaBattleAbra::
	trainerbattle_no_intro TRAINER_ATHENA_ATHENAS_HOUSE_ABRA, Athenas_House_Text_ATHENADefeated
	goto AthenasHouse_EventScript_AfterAthenaBattle
	end

AthenasHouse_EventScript_StartAthenaBattleJangmoo::
	trainerbattle_no_intro TRAINER_ATHENA_ATHENAS_HOUSE_JANGMOO, Athenas_House_Text_ATHENADefeated
	goto AthenasHouse_EventScript_AfterAthenaBattle
	end

AthenasHouse_EventScript_StartAthenaBattlePawniard::
	trainerbattle_no_intro TRAINER_ATHENA_ATHENAS_HOUSE_PAWNIARD Athenas_House_Text_ATHENADefeated
	goto AthenasHouse_EventScript_AfterAthenaBattle
	end

AthenasHouse_EventScript_AfterAthenaBattle::
	msgbox AthenasHouse_1F_Text_AthenaSendOff
	goto LittleRootTown_AthenasHouse_1F_EventScript_GiveKeyItems
	end

AthenasHouse_1F_EventScript_AthenaExitHouse:: 
	msgbox LittlerootTown_AthenasHouse_Text_AthenaLeaving
	delay_16
	applymovement VAR_0x8004, AthenasHouse_1F_Movement_AthenaLeave

AthenasHouse_1F_Movement_AthenaLeave:
	walk_down
	step_end


AthenasHouse_1F_Movement_MovePlayerAwayFromDoor:
	walk_up
	step_end


AthenasHouse_1F_EventScript_SetUpObjectEventVarsMale::
	setvar VAR_0x8008, MALE
	setvar VAR_0x8009, LOCALID_DAD
	setvar VAR_0x800A, LOCALID_MOM
	return

AthenasHouse_1F_EventScript_SetUpObjectEventVarsFemale::
	setvar VAR_0x8008, FEMALE
	setvar VAR_0x8009, LOCALID_DAD
	setvar VAR_0x800A, LOCALID_MOM
	return

AthenasHouse_1F_Movement_PlayerEnterRoomMale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

AthenasHouse_1F_Movement_PlayerEnterRoomFemale:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

AthenasHouse_1F_Movement_PlayerApproachTVForLatiMale:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

AthenasHouse_1F_Movement_PlayerApproachTVForLatiFemale:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

EventScript_RunningShoesManual::
	msgbox AthenasHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end
