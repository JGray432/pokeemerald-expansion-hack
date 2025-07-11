Common_EventScript_UtilitiesScientist::
	lock
	faceplayer
	msgbox gText_UtilitiesScientistIntro
    multichoice 0, 0, MULTI_UTILITIES_LIST, 0
    switch VAR_RESULT
    case 0, UtilitiesScientist_ChangeNickname
    case 1, UtilitiesScientist_ApplyStatus
    case 2, UtilitiesScientist_MaximizeIV
    release
    end

UtilitiesScientist_ChangeNickname::
    special ChoosePartyMon 
    special ChangePokemonNickname
    goto Common_EventScript_UtilitiesScientist

UtilitiesScientist_ApplyStatus::
    msgbox gText_ChooseStatus MSGBOX_DEFAULT
    call ChooseStatusToApply
    special ChooseMonForStatus
    waitstate
    special ApplyStatusConditionToPartyMon
    goto Common_EventScript_UtilitiesScientist

UtilitiesScientist_MaximizeIV::
    checkitem ITEM_HEART_SCALE, 1
    compare VAR_RESULT, TRUE
    goto_if_eq VAR_RESULT, TrainerGuy_MaximizeIV_Yes
    msgbox gText_NoHeartScales MSGBOX_DEFAULT
    release end

UtilitiesScientist_MaximizeIV_Yes::
    msgbox gText_ChooseStatToMax MSGBOX_DEFAULT
    call ChooseMonForIVMax
    waitstate
    call EventScript_ChooseStatToMax
    call MaximizeIVOfChosenMon
    removeitem ITEM_HEART_SCALE, 1
    goto Common_EventScript_UtilitiesScientist

ChooseStatusToApply::
    multichoice 0, 0, MULTI_STATUSES, 0
    setvar VAR_RESULT, VAR_RESULT
    return
    
EventScript_ChooseStatToMax::
    multichoice 0, 0, MULTI_STATS, 0
    setvar VAR_RESULT, VAR_RESULT
    return

