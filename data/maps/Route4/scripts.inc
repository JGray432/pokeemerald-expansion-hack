Route4_MapScripts::
	.byte 0

Route4_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME, Route4_Text_JeromeIntro, Route4_Text_JeromeDefeated
	msgbox Route4_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Matthew::
	trainerbattle_single TRAINER_MATTHEW, Route4_Text_MatthewIntro, Route4_Text_MatthewDefeated
	msgbox Route4_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Tara::
	trainerbattle_single TRAINER_TARA, Route4_Text_TaraIntro, Route4_Text_TaraDefeated
	msgbox Route4_Text_TaraPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Missy::
	trainerbattle_single TRAINER_MISSY, Route4_Text_MissyIntro, Route4_Text_MissyDefeated
	msgbox Route4_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Carolina::
	trainerbattle_single TRAINER_CAROLINA, Route4_Text_CarolinaIntro, Route4_Text_CarolinaDefeated
	msgbox Route4_Text_CarolinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route4_EventScript_Cory::
	trainerbattle_single TRAINER_CORY_1, Route4_Text_CoryIntro, Route4_Text_CoryDefeated, Route4_EventScript_CoryRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route4_EventScript_CoryRematch
	msgbox Route4_Text_CoryPostBattle, MSGBOX_DEFAULT
	release
	end

Route4_EventScript_CoryRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route4_Text_CoryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CORY_1
	release
	end

Route4_EventScript_CoryRematch::
	trainerbattle_rematch TRAINER_CORY_1, Route4_Text_CoryRematchIntro, Route4_Text_CoryRematchDefeated
	msgbox Route4_Text_CoryRematchPostBattle, MSGBOX_AUTOCLOSE
	end

