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
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, UtilitiesScientist_Decline
    special ChangePokemonNickname
    waitstate
    msgbox gText_SuccessfulExperiment
    release
    end

UtilitiesScientist_ApplyStatus::
    msgbox gText_ChooseStatus MSGBOX_DEFAULT
    call ChooseStatusToApply

UtilitiesScientist_MaximizeIV::
    checkitem ITEM_HEART_SCALE
    goto_if_eq VAR_RESULT, FALSE, UtilitiesScientist_MaximizeIV_NoHeartScales
    goto UtilitiesScientist_MaximizeIV_Yes
    release 
    end

UtilitiesScientist_MaximizeIV_NoHeartScales::
    msgbox gText_NoHeartScales MSGBOX_DEFAULT
    release 
    end

UtilitiesScientist_MaximizeIV_Yes::
    msgbox gText_ChooseStatToMax MSGBOX_DEFAULT
    special ChooseMonForIVMax
    waitstate
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, UtilitiesScientist_Decline
    call EventScript_ChooseStatToMax
    special MaximizeIVOfChosenMon
    waitstate
    removeitem ITEM_HEART_SCALE, 0
    msgbox gText_SuccessfulExperiment
    release
    end

ChooseStatusToApply::
    multichoice 0, 0, MULTI_STATUSES, FALSE
    switch VAR_RESULT
    case 0, UtilitiesScientist_ChooseMonToApplyPoison
    case 1, UtilitiesScientist_ChooseMonToApplyParalyze
    case 2, UtilitiesScientist_ChooseMonToApplyBurn
    case 3, UtilitiesScientist_ChooseMonToApplyFrostbite
    case 4, UtilitiesScientist_ChooseMonToApplySleep
    release
    end

UtilitiesScientist_ChooseMonToApplyPoison::
    special ChoosePartyMon
    waitstate
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, UtilitiesScientist_Decline
    special ApplyPoisonStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

UtilitiesScientist_ChooseMonToApplyBurn::
    special ChoosePartyMon
    waitstate
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, UtilitiesScientist_Decline
    special ApplyBurnStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

UtilitiesScientist_ChooseMonToApplyParalyze::
    special ChoosePartyMon
    waitstate
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, UtilitiesScientist_Decline
    special ApplyParalyzeStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

UtilitiesScientist_ChooseMonToApplyFrostbite::
    special ChoosePartyMon
    waitstate
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, UtilitiesScientist_Decline
    special ApplyFrostbiteStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

UtilitiesScientist_ChooseMonToApplySleep::
    special ChoosePartyMon
    waitstate
    goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, UtilitiesScientist_Decline
    special ApplySleepStatusConditionToPartyMon
    waitstate
    msgbox gText_SuccessfulExperiment
    release 
    end

EventScript_ChooseStatToMax::
    multichoice 0, 0, MULTI_STATS, FALSE
    copyvar  VAR_0x8004, VAR_0x8008
    return

UtilitiesScientist_Decline::
    msgbox gText_UtilitiesScientist_Decline
    release
    end

