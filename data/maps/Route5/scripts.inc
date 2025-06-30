Route5_MapScripts::
	.byte 0

Route5_EventScript_Darrin::
	trainerbattle_single TRAINER_DARRIN, Route5_Text_DarrinIntro, Route5_Text_DarrinDefeated
	msgbox Route5_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Tony::
	trainerbattle_single TRAINER_TONY_1, Route5_Text_TonyIntro, Route5_Text_TonyDefeated, Route5_EventScript_TonyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route5_EventScript_TonyRematch
	msgbox Route5_Text_TonyPostBattle, MSGBOX_DEFAULT
	release
	end

Route5_EventScript_TonyRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route5_Text_TonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TONY_1
	release
	end

Route5_EventScript_TonyRematch::
	trainerbattle_rematch TRAINER_TONY_1, Route5_Text_TonyRematchIntro, Route5_Text_TonyRematchDefeated
	msgbox Route5_Text_TonyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE, Route5_Text_DeniseIntro, Route5_Text_DeniseDefeated
	msgbox Route5_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Beth::
	trainerbattle_single TRAINER_BETH, Route5_Text_BethIntro, Route5_Text_BethDefeated
	msgbox Route5_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Lisa::
	trainerbattle_double TRAINER_LISA_AND_RAY, Route5_Text_LisaIntro, Route5_Text_LisaDefeated, Route5_Text_LisaNotEnoughPokemon
	msgbox Route5_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Ray::
	trainerbattle_double TRAINER_LISA_AND_RAY, Route5_Text_RayIntro, Route5_Text_RayDefeated, Route5_Text_RayNotEnoughPokemon
	msgbox Route5_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

Route5_EventScript_Camron::
	trainerbattle_single TRAINER_CAMRON, Route5_Text_CamronIntro, Route5_Text_CamronDefeated
	msgbox Route5_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

