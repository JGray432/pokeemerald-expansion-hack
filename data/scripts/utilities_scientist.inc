Common_EventScript_UtilitiesScientist::
	lock
	faceplayer
	msgbox gText_UtilitiesScientistIntro
    multichoice 0, 0, MULTI_UTILITIES_LIST, FALSE
    switch VAR_RESULT
    case 0, UtilitiesScientist_ChangeNickname
    case 1, UtilitiesScientist_ApplyStatus
    case 2, UtilitiesScientist_MaximizeIV
    release
    end

UtilitiesScientist_ChangeNickname::
    special ChoosePartyMon 
    waitstate
    special ChangePokemonNickname
    waitstate
    msgbox gText_SuccessfulExperiment
    end

UtilitiesScientist_ApplyStatus::
    msgbox gText_ChooseStatus MSGBOX_DEFAULT
    call ChooseStatusToApply

UtilitiesScientist_MaximizeIV::
    checkitem ITEM_HEART_SCALE, 1
    compare VAR_RESULT, TRUE
    goto_if_eq VAR_RESULT, UtilitiesScientist_MaximizeIV_Yes
    goto UtilitiesScientist_MaximizeIV_Yes
    msgbox gText_NoHeartScales MSGBOX_DEFAULT
    release 
    end

UtilitiesScientist_MaximizeIV_Yes::
    msgbox gText_ChooseStatToMax MSGBOX_DEFAULT
    special ChooseMonForIVMax
    waitstate
    call EventScript_ChooseStatToMax
    special MaximizeIVOfChosenMon
    waitstate
    removeitem ITEM_HEART_SCALE, 0
    msgbox gText_SuccessfulExperiment
    end

ChooseStatusToApply::
    multichoice 0, 0, MULTI_STATUSES, FALSE
    switch VAR_RESULT
    case 0, UtilitiesScientist_ChooseMonToApplyPoison
    case 1, UtilitiesScientist_ChooseMonToApplyBurn
    case 2, UtilitiesScientist_ChooseMonToApplyParalyze
    case 3, UtilitiesScientist_ChooseMonToApplyFrostbite
    case 4, UtilitiesScientist_ChooseMonToApplySleep
    end

UtilitiesScientist_ChooseMonToApplyPoison::
    specialvar VAR_RESULT, ChooseMonForStatus
    waitstate
    copyvar  VAR_0x8004, VAR_0x8008
    special ApplyPoisonStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

UtilitiesScientist_ChooseMonToApplyBurn::
    specialvar VAR_RESULT, ChooseMonForStatus
    waitstate
    special ApplyBurnStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

UtilitiesScientist_ChooseMonToApplyParalyze::
    specialvar VAR_RESULT, ChooseMonForStatus
    waitstate
    special ApplyParalyzeStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

UtilitiesScientist_ChooseMonToApplyFrostbite::
    specialvar VAR_RESULT, ChooseMonForStatus
    waitstate
    special ApplyFrostbiteStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

UtilitiesScientist_ChooseMonToApplySleep::
    specialvar VAR_RESULT, ChooseMonForStatus
    waitstate
    special ApplySleepStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

EventScript_ChooseStatToMax::
    multichoice 0, 0, MULTI_STATS, FALSE
    copyvar  VAR_0x8004, VAR_0x8008
    return

