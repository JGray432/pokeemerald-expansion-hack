.set LOCALID_KYLA, 5
Route6_MapScripts::
	.byte 0

Route6_EventScript_TrainerTipsSign::
	msgbox Route6_Text_TrainerTips, MSGBOX_SIGN
	end

Route6_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route6_Text_DouglasIntro, Route6_Text_DouglasDefeated
	msgbox Route6_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Kyla_BackToBack::
	goto_if_set FLAG_ROUTE_6_BACKTOBACK, Route6_EventScript_KylaDefeated
	applymovement LOCALID_KYLA, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_KYLA, Route6_Movement_KylaApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
 	waitmovement 0
	goto Route6_EventScript_Kyla
	end

Route6_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route6_Text_KylaIntro, Route6_Text_KylaDefeated, Route6_EventScript_KylaDefeated
	

Route6_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route6_Text_ElliotIntro, Route6_Text_ElliotDefeated, Route6_EventScript_Kyla_BackToBack
	release
	end

Route6_EventScript_KylaDefeated::
	setflag FLAG_ROUTE_6_BACKTOBACK
	msgbox Route6_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route6_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route6_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route6_Text_ElliotRematchIntro, Route6_Text_ElliotRematchDefeated
	msgbox Route6_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route6_Text_NedIntro, Route6_Text_NedDefeated
	msgbox Route6_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route6_Text_TrainerTips:
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

Route6_Movement_KylaApproachPlayer::
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
