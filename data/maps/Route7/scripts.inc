.set LOCALID_DAYCARE_MAN, 3
.set LOCALID_DAYCARE_MON_0, 25
.set LOCALID_DAYCARE_MON_1, 26

Route7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	.byte 0

Route7_OnTransition:
	call Route7_EventScript_TryMoveDayCareMan
	@ set flags for OW daycare mons
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	getdaycaregfx VAR_OBJ_GFX_ID_0, VAR_OBJ_GFX_ID_1, VAR_TEMP_0, VAR_TEMP_1
	switch VAR_RESULT
	case 2, Route7_EventScript_ShowDaycareMon1
	case 1, Route7_EventScript_ShowDaycareMon0
	end

Route7_EventScript_ShowDaycareMon1:
	@ set pokemon movement type based on compatibility
	special SetDaycareCompatibilityString
	call_if_eq VAR_RESULT, PARENTS_INCOMPATIBLE, Route7_EventScript_DaycareMonIncompatible
	@ Don't do anything if PARENTS_LOW_COMPATIBILITY
	call_if_eq VAR_RESULT, PARENTS_MED_COMPATIBILITY, Route7_EventScript_DaycareMonMedCompatibility
	call_if_eq VAR_RESULT, PARENTS_MAX_COMPATIBILITY, Route7_EventScript_DaycareMonMaxCompatibility
	clearflag FLAG_TEMP_2
Route7_EventScript_ShowDaycareMon0:
	clearflag FLAG_TEMP_1
	end

Route7_EventScript_DaycareMonIncompatible: @ mons never face each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT
	return

Route7_EventScript_DaycareMonMedCompatibility: @ down and towards each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT
	return

Route7_EventScript_DaycareMonMaxCompatibility: @ facing; walk in place
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	return

Route7_EventScript_TryMoveDayCareMan::
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route7_EventScript_StopMoveDayCareMan
	setobjectxyperm LOCALID_DAYCARE_MAN, 47, 6
Route7_EventScript_StopMoveDayCareMan::
	return

Route7_EventScript_Woman::
	msgbox Route7_Text_ArentTheseFlowersPretty, MSGBOX_NPC
	end

Route7_EventScript_LittleBoy::
	msgbox Route7_Text_AirIsTastyHere, MSGBOX_NPC
	end

Route7_EventScript_Girl::
	msgbox Route7_Text_DayCarePokemonHadNewMove, MSGBOX_NPC
	end

Route7_EventScript_RouteSignVerdanturf::
	msgbox Route7_Text_RouteSignVerdanturf, MSGBOX_SIGN
	end

Route7_EventScript_RouteSignAthens::
	msgbox Route7_Text_RouteSignAthens, MSGBOX_SIGN
	end

Route7_EventScript_DayCareSign::
	msgbox Route7_Text_DayCareSign, MSGBOX_SIGN
	end

Route7_EventScript_Isaac::
	trainerbattle_single TRAINER_ISAAC_1, Route7_Text_IsaacIntro, Route7_Text_IsaacDefeat, Route7_EventScript_RegisterIsaac
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route7_EventScript_RematchIsaac
	msgbox Route7_Text_IsaacPostBattle, MSGBOX_DEFAULT
	release
	end

Route7_EventScript_RegisterIsaac::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route7_Text_IsaacRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAAC_1
	release
	end

Route7_EventScript_RematchIsaac::
	trainerbattle_rematch TRAINER_ISAAC_1, Route7_Text_IsaacRematchIntro, Route7_Text_IsaacRematchDefeat
	msgbox Route7_Text_IsaacPostRematch, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Lydia::
	trainerbattle_single TRAINER_LYDIA_1, Route7_Text_LydiaIntro, Route7_Text_LydiaDefeat, Route7_EventScript_RegisterLydia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route7_EventScript_RematchLydia
	msgbox Route7_Text_LydiaPostBattle, MSGBOX_DEFAULT
	release
	end

Route7_EventScript_RegisterLydia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route7_Text_LydiaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LYDIA_1
	release
	end

Route7_EventScript_RematchLydia::
	trainerbattle_rematch TRAINER_LYDIA_1, Route7_Text_LydiaRematchIntro, Route7_Text_LydiaRematchDefeat
	msgbox Route7_Text_LydiaPostRematch, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Dylan::
	trainerbattle_single TRAINER_DYLAN_1, Route7_Text_DylanIntro, Route7_Text_DylanDefeat
	msgbox Route7_Text_DylanPostBattle, MSGBOX_DEFAULT
	release
	end

Route7_EventScript_RegisterDylan::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route7_Text_DylanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DYLAN_1
	release
	end

Route7_EventScript_RematchDylan::
	trainerbattle_rematch TRAINER_DYLAN_1, Route7_Text_DylanRematchIntro, Route7_Text_DylanRematchDefeat
	msgbox Route7_Text_DylanPostRematch, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Maria::
	trainerbattle_single TRAINER_MARIA_1, Route7_Text_MariaIntro, Route7_Text_MariaDefeat
	msgbox Route7_Text_MariaPostBattle, MSGBOX_DEFAULT
	release
	end

Route7_EventScript_RegisterMaria::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route7_Text_MariaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MARIA_1
	release
	end

Route7_EventScript_RematchMaria::
	trainerbattle_rematch TRAINER_MARIA_1, Route7_Text_MariaRematchIntro, Route7_Text_MariaRematchDefeat
	msgbox Route7_Text_MariaPostRematch, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK, Route7_Text_DerekIntro, Route7_Text_DerekDefeat
	msgbox Route7_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Anna::
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route7_Text_AnnaIntro, Route7_Text_AnnaDefeat, Route7_Text_AnnaNotEnoughMons, Route7_EventScript_RegisterAnna
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route7_EventScript_RematchAnna
	msgbox Route7_Text_AnnaPostBattle, MSGBOX_DEFAULT
	release
	end

Route7_EventScript_RegisterAnna::
	msgbox Route7_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route7_EventScript_RematchAnna::
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route7_Text_AnnaRematchIntro, Route7_Text_AnnaRematchDefeat, Route7_Text_AnnaRematchNotEnoughMons
	msgbox Route7_Text_AnnaPostRematch, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Meg::
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route7_Text_MegIntro, Route7_Text_MegDefeat, Route7_Text_MegNotEnoughMons, Route7_EventScript_RegisterMeg
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route7_EventScript_RematchMeg
	msgbox Route7_Text_MegPostBattle, MSGBOX_DEFAULT
	release
	end

Route7_EventScript_RegisterMeg::
	msgbox Route7_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route7_EventScript_RematchMeg::
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route7_Text_MegRematchIntro, Route7_Text_MegRematchDefeat, Route7_Text_MegRematchNotEnoughMons
	msgbox Route7_Text_MegPostRematch, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Melina::
	trainerbattle_single TRAINER_MELINA, Route7_Text_MelinaIntro, Route7_Text_MelinaDefeat
	msgbox Route7_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Brandi::
	trainerbattle_single TRAINER_BRANDI, Route7_Text_BrandiIntro, Route7_Text_BrandiDefeat
	msgbox Route7_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_EventScript_Aisha::
	trainerbattle_single TRAINER_AISHA, Route7_Text_AishaIntro, Route7_Text_AishaDefeat
	msgbox Route7_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
	end

Route7_Text_DayCarePokemonHadNewMove:
	.string "I left my POKéMON at the DAY CARE.\p"
	.string "When I got it back, it had a new move\n"
	.string "that I didn't teach it.\l"
	.string "I was really, really surprised.$"

Route7_Text_ArentTheseFlowersPretty:
	.string "What do you think?\n"
	.string "Aren't these flowers pretty?\p"
	.string "I planted them all!$"

Route7_Text_AirIsTastyHere:
	.string "The air is tasty here!$"

Route7_Text_RouteSignVerdanturf:
	.string "ROUTE 7\n"
	.string "{LEFT_ARROW} VERDANTURF TOWN$"

Route7_Text_RouteSignAthens:
	.string "ROUTE 7\n"
	.string "{RIGHT_ARROW} ATHENS$"

Route7_Text_DayCareSign:
	.string "POKéMON DAY CARE\n"
	.string "“Let us raise your POKéMON.”$"
