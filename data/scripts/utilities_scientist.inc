Common_EventScript_UtilitiesScientist::
	lock
	faceplayer
	msgbox gText_UtilitiesScientistIntro
    multichoice 0, MultichoiceList_UtilitiesList, 3, 0
    switch VAR_RESULT
    case 0, UtilitiesScientist_ChangeNickname
    case 1, UtilitiesScientist_ApplyStatus
    case 2, UtilitiesScientist_MaximizeIV
    release
    end

UtilitiesScientist_ChangeNickname::
    special ChangePokemonNickname
    goto Common_EventScript_UtilitiesScientist

UtilitiesScientist_ApplyStatus::
    msgbox gText_ChooseStatus MSGBOX_DEFAULT
    call ChooseStatusToApply
    call ChooseMonForStatus
    waitstate
    call ApplyStatusConditionToPartyMon
    goto Common_EventScript_UtilitiesScientist

UtilitiesScientist_MaximizeIV::
    checkitem ITEM_HEART_SCALE, 1
    compare VAR_RESULT, TRUE
    goto_if_eq VAR_RESULT, TrainerGuy_MaximizeIV_Yes
    msgbox gText_NoHeartScales MSGBOX_DEFAULT
    goto Common_EventScript_UtilitiesScientist

UtilitiesScientist_MaximizeIV_Yes::
    msgbox gText_ChooseStatToMax MSGBOX_DEFAULT
    call ChooseMonForIVMax
    waitstate
    call EventScript_ChooseStatToMax
    call MaximizeIVOfChosenMon
    removeitem ITEM_HEART_SCALE, 1
    goto Common_EventScript_UtilitiesScientist

ChooseStatusToApply::
    multichoice 0, MultichoiceList_Statuses, 6, 0 // Define this multichoice table
    setvar VAR_RESULT, VAR_RESULT
    return
    
void ApplyStatusConditionToPartyMon(void)
{
    u16 chosenStatus = VarGet(VAR_RESULT);
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u32 status = 0;
    switch (chosenStatus) {
        case 1: status = STATUS1_POISON; break;
        case 2: status = STATUS1_PARALYSIS; break;
        case 3: status = STATUS1_BURN; break;
        case 4: status = STATUS1_FREEZE; break;
        case 5: status = STATUS1_SLEEP; break;
    }
    SetMonData(mon, MON_DATA_STATUS, &status);
}

EventScript_ChooseStatToMax::
    multichoice 0, MultichoiceList_Stats, 6, 0
    setvar VAR_RESULT, VAR_RESULT
    return

MaximizeIVOfChosenMon(void)
{
    u8 statId = VarGet(VAR_RESULT); // 0 = HP, 1 = Atk, ...
    u8 monId = GetCursorSelectionMonId();
    struct Pokemon *mon = &gPlayerParty[monId];

    u8 maxIV = 31;
    SetMonData(mon, MON_DATA_HP_IV + statId, &maxIV);
}