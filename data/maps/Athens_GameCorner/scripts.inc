Athens_GameCorner_MapScripts::
	.byte 0

    @ Game Corner prices
	.set TM_DOUBLE_TEAM_COINS, 1000
	.set TM_PSYCHIC_COINS, 1000
	.set TM_FLAMETHROWER_COINS, 1000
	.set TM_THUNDERBOLT_COINS, 1000
	.set TM_ICE_BEAM_COINS, 1000
	.set DOLL_COINS, 1000

	.set COINS_PRICE_50,  500
	.set COINS_PRICE_500, 5000

Athens_GameCorner_EventScript_CoinsClerk::
	lock
	faceplayer
	msgbox Athens_GameCorner_Text_ThisIsMauvilleGameCorner, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NeedCoinCase
	message Athens_GameCorner_Text_WereYouLookingForCoins
	waitmessage
	showmoneybox 0, 0
	showcoinsbox 1, 6
	goto Athens_GameCorner_EventScript_ChooseCoinsDefault50

Athens_GameCorner_EventScript_ChooseCoinsDefault50::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 0, FALSE
	switch VAR_RESULT
	case 0, Athens_GameCorner_EventScript_Buy50Coins
	case 1, Athens_GameCorner_EventScript_Buy500Coins
	goto Athens_GameCorner_EventScript_CancelBuyCoins
	end

@ Unused
Athens_GameCorner_EventScript_ChooseCoinsDefault500::
	multichoicedefault 15, 0, MULTI_GAME_CORNER_COINS, 1, FALSE
	switch VAR_RESULT
	case 0, Athens_GameCorner_EventScript_Buy50Coins
	case 1, Athens_GameCorner_EventScript_Buy500Coins
	goto Athens_GameCorner_EventScript_CancelBuyCoins
	end

Athens_GameCorner_EventScript_Buy50Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), Athens_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_50
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NotEnoughMoney
	addcoins 50
	removemoney COINS_PRICE_50
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

Athens_GameCorner_EventScript_Buy500Coins::
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), Athens_GameCorner_EventScript_NoRoomForCoins
	checkmoney COINS_PRICE_500
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NotEnoughMoney
	addcoins 500
	removemoney COINS_PRICE_500
	updatemoneybox
	updatecoinsbox 1, 6
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_ThankYouHereAreYourCoins, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

Athens_GameCorner_EventScript_NeedCoinCase::
	msgbox Athens_GameCorner_Text_NeedCoinCaseForCoins, MSGBOX_DEFAULT
	release
	end

Athens_GameCorner_EventScript_NotEnoughMoney::
	msgbox Athens_GameCorner_Text_DontHaveEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

Athens_GameCorner_EventScript_CancelBuyCoins::
	msgbox Athens_GameCorner_Text_DontNeedCoinsThen, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

Athens_GameCorner_EventScript_NoRoomForCoins::
	msgbox Athens_GameCorner_Text_CoinCaseIsFull, MSGBOX_DEFAULT
	hidemoneybox
	hidecoinsbox 0, 5
	release
	end

Athens_GameCorner_EventScript_PrizeCornerDolls::
	lock
	faceplayer
	msgbox Athens_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, Athens_GameCorner_EventScript_ChooseDollPrizeMessage
	release
	end

Athens_GameCorner_EventScript_ChooseDollPrizeMessage::
	message Athens_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto Athens_GameCorner_EventScript_ChooseDollPrize

Athens_GameCorner_EventScript_ReturnToChooseDollPrize::
	message Athens_GameCorner_Text_WhichPrize
	waitmessage
	goto Athens_GameCorner_EventScript_ChooseDollPrize

Athens_GameCorner_EventScript_ChooseDollPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_DOLLS, FALSE
	switch VAR_RESULT
	case 0, Athens_GameCorner_EventScript_TreeckoDoll
	case 1, Athens_GameCorner_EventScript_TorchicDoll
	case 2, Athens_GameCorner_EventScript_MudkipDoll
	case 3, Athens_GameCorner_EventScript_CancelDollSelect
	goto Athens_GameCorner_EventScript_CancelDollSelect
	end

Athens_GameCorner_EventScript_TreeckoDoll::
	setvar VAR_TEMP_1, 1
	bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL
	goto Athens_GameCorner_EventScript_ConfirmDollPrize

Athens_GameCorner_EventScript_TorchicDoll::
	setvar VAR_TEMP_1, 2
	bufferdecorationname STR_VAR_1, DECOR_TORCHIC_DOLL
	goto Athens_GameCorner_EventScript_ConfirmDollPrize

Athens_GameCorner_EventScript_MudkipDoll::
	setvar VAR_TEMP_1, 3
	bufferdecorationname STR_VAR_1, DECOR_MUDKIP_DOLL
	goto Athens_GameCorner_EventScript_ConfirmDollPrize

Athens_GameCorner_EventScript_ConfirmDollPrize::
	msgbox Athens_GameCorner_Text_SoYourChoiceIsX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Athens_GameCorner_EventScript_CancelDollSelect
	switch VAR_TEMP_1
	case 1, Athens_GameCorner_EventScript_BuyTreeckoDoll
	case 2, Athens_GameCorner_EventScript_BuyTorchicDoll
	case 3, Athens_GameCorner_EventScript_BuyMudkipDoll
	end

Athens_GameCorner_EventScript_BuyTreeckoDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, Athens_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TREECKO_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseDollPrize
	end

Athens_GameCorner_EventScript_BuyTorchicDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, Athens_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_TORCHIC_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseDollPrize
	end

Athens_GameCorner_EventScript_BuyMudkipDoll::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, DOLL_COINS, Athens_GameCorner_EventScript_NotEnoughCoinsForDoll
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForDoll
	removecoins DOLL_COINS
	adddecoration DECOR_MUDKIP_DOLL
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_SendToYourHomePC, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseDollPrize
	end

Athens_GameCorner_EventScript_NotEnoughCoinsForDoll::
	msgbox Athens_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseDollPrize
	end

Athens_GameCorner_EventScript_NoRoomForDoll::
	call Common_EventScript_NoRoomForDecor
	goto Athens_GameCorner_EventScript_ReturnToChooseDollPrize
	end

Athens_GameCorner_EventScript_CancelDollSelect::
	msgbox Athens_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

Athens_GameCorner_EventScript_PrizeCornerTMs::
	lock
	faceplayer
	msgbox Athens_GameCorner_Text_ExchangeCoinsForPrizes, MSGBOX_DEFAULT
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, Athens_GameCorner_EventScript_ChooseTMPrizeMessage
	release
	end

Athens_GameCorner_EventScript_ChooseTMPrizeMessage::
	message Athens_GameCorner_Text_WhichPrize
	waitmessage
	setvar VAR_TEMP_1, 0
	showcoinsbox 1, 1
	goto Athens_GameCorner_EventScript_ChooseTMPrize

Athens_GameCorner_EventScript_ReturnToChooseTMPrize::
	message Athens_GameCorner_Text_WhichPrize
	waitmessage
	goto Athens_GameCorner_EventScript_ChooseTMPrize

Athens_GameCorner_EventScript_ChooseTMPrize::
	multichoice 12, 0, MULTI_GAME_CORNER_TMS, FALSE
	switch VAR_RESULT
	case 0, Athens_GameCorner_EventScript_TMWaterPulse
	case 1, Athens_GameCorner_EventScript_TMShockWave
	case 2, Athens_GameCorner_EventScript_TMAerialAce
	case 3, Athens_GameCorner_EventScript_TMThunderbolt
	case 4, Athens_GameCorner_EventScript_TMIceBeam
	case 5, Athens_GameCorner_EventScript_CancelTMSelect
	goto Athens_GameCorner_EventScript_CancelTMSelect
	end

Athens_GameCorner_EventScript_TMWaterPulse::
	setvar VAR_TEMP_1, 1
	bufferitemname STR_VAR_1, ITEM_TM_WATER_PULSE
	setvar VAR_0x8004, ITEM_TM_WATER_PULSE
	goto Athens_GameCorner_EventScript_ConfirmTMPrize

Athens_GameCorner_EventScript_TMShockWave::
	setvar VAR_TEMP_1, 2
	bufferitemname STR_VAR_1, ITEM_TM_SHOCK_WAVE
	setvar VAR_0x8004, ITEM_TM_SHOCK_WAVE
	goto Athens_GameCorner_EventScript_ConfirmTMPrize

Athens_GameCorner_EventScript_TMAerialAce::
	setvar VAR_TEMP_1, 3
	bufferitemname STR_VAR_1, ITEM_TM_AERIAL_ACE
	setvar VAR_0x8004, ITEM_TM_AERIAL_ACE
	goto Athens_GameCorner_EventScript_ConfirmTMPrize

Athens_GameCorner_EventScript_TMThunderbolt::
	setvar VAR_TEMP_1, 4
	bufferitemname STR_VAR_1, ITEM_TM_MAGNET_BOMB
	setvar VAR_0x8004, ITEM_TM_MAGNET_BOMB
	goto Athens_GameCorner_EventScript_ConfirmTMPrize

Athens_GameCorner_EventScript_TMIceBeam::
	setvar VAR_TEMP_1, 5
	bufferitemname STR_VAR_1, ITEM_TM_MAGICAL_LEAF
	setvar VAR_0x8004, ITEM_TM_MAGICAL_LEAF
	goto Athens_GameCorner_EventScript_ConfirmTMPrize

Athens_GameCorner_EventScript_ConfirmTMPrize::
	special BufferTMHMMoveName
	msgbox Athens_GameCorner_Text_SoYourChoiceIsTheTMX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Athens_GameCorner_EventScript_CancelTMSelect
	switch VAR_TEMP_1
	case 1, Athens_GameCorner_EventScript_BuyTMDoubleTeam
	case 2, Athens_GameCorner_EventScript_BuyTMPsychic
	case 3, Athens_GameCorner_EventScript_BuyTMFlamethrower
	case 4, Athens_GameCorner_EventScript_BuyTMThunderbolt
	case 5, Athens_GameCorner_EventScript_BuyTMIceBeam
	end

Athens_GameCorner_EventScript_BuyTMDoubleTeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_DOUBLE_TEAM_COINS, Athens_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForTM
	removecoins TM_DOUBLE_TEAM_COINS
	additem ITEM_TM_WATER_PULSE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseTMPrize
	end

Athens_GameCorner_EventScript_BuyTMPsychic::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_PSYCHIC_COINS, Athens_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForTM
	removecoins TM_PSYCHIC_COINS
	additem ITEM_TM_SHOCK_WAVE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseTMPrize
	end

Athens_GameCorner_EventScript_BuyTMFlamethrower::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_FLAMETHROWER_COINS, Athens_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForTM
	removecoins TM_FLAMETHROWER_COINS
	additem ITEM_TM_AERIAL_ACE
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseTMPrize
	end

Athens_GameCorner_EventScript_BuyTMThunderbolt::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_THUNDERBOLT_COINS, Athens_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_MAGNET_BOMB
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForTM
	removecoins TM_THUNDERBOLT_COINS
	additem ITEM_TM_MAGNET_BOMB
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseTMPrize
	end

Athens_GameCorner_EventScript_BuyTMIceBeam::
	checkcoins VAR_TEMP_2
	goto_if_lt VAR_TEMP_2, TM_ICE_BEAM_COINS, Athens_GameCorner_EventScript_NotEnoughCoinsForTM
	checkitemspace ITEM_TM_MAGICAL_LEAF
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForTM
	removecoins TM_ICE_BEAM_COINS
	additem ITEM_TM_MAGICAL_LEAF
	updatecoinsbox 1, 1
	playse SE_SHOP
	msgbox Athens_GameCorner_Text_HereYouGo, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseTMPrize
	end

Athens_GameCorner_EventScript_NotEnoughCoinsForTM::
	msgbox Athens_GameCorner_Text_NotEnoughCoins, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_ReturnToChooseTMPrize
	end

Athens_GameCorner_EventScript_NoRoomForTM::
	call Common_EventScript_BagIsFull
	goto Athens_GameCorner_EventScript_ReturnToChooseTMPrize
	end

Athens_GameCorner_EventScript_CancelTMSelect::
	msgbox Athens_GameCorner_Text_OhIsThatSo, MSGBOX_DEFAULT
	hidecoinsbox 0, 0
	release
	end

Athens_GameCorner_EventScript_Woman2::
	msgbox Athens_GameCorner_Text_CoinsAreNeededToPlay, MSGBOX_NPC
	end

Athens_GameCorner_EventScript_Gentleman::
	msgbox Athens_GameCorner_Text_RouletteOnlyLuck, MSGBOX_NPC
	end

Athens_GameCorner_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, Athens_GameCorner_EventScript_ReceivedStarterDoll
	msgbox Athens_GameCorner_Text_GotTwoOfSameDollWantOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Athens_GameCorner_EventScript_DeclineStarterDoll
	switch VAR_STARTER_MON
	case 0, Athens_GameCorner_EventScript_GiveTreeckoDoll
	case 1, Athens_GameCorner_EventScript_GiveTorchicDoll
	case 2, Athens_GameCorner_EventScript_GiveMudkipDoll
	end

Athens_GameCorner_EventScript_GiveTreeckoDoll::
	bufferdecorationname STR_VAR_2, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox Athens_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto Athens_GameCorner_EventScript_ReceivedStarterDoll
	end

Athens_GameCorner_EventScript_GiveTorchicDoll::
	bufferdecorationname STR_VAR_2, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox Athens_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto Athens_GameCorner_EventScript_ReceivedStarterDoll
	end

Athens_GameCorner_EventScript_GiveMudkipDoll::
	bufferdecorationname STR_VAR_2, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoRoomForStarterDoll
	msgbox Athens_GameCorner_Text_HereYouGo2, MSGBOX_DEFAULT
	givedecoration DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto Athens_GameCorner_EventScript_ReceivedStarterDoll
	end

Athens_GameCorner_EventScript_NoRoomForStarterDoll::
	call Common_EventScript_NoRoomForDecor
	msgbox Athens_GameCorner_Text_YouWantItButNotNow, MSGBOX_DEFAULT
	release
	end

Athens_GameCorner_EventScript_DeclineStarterDoll::
	msgbox Athens_GameCorner_Text_DontBeNegative, MSGBOX_DEFAULT
	release
	end

Athens_GameCorner_EventScript_ReceivedStarterDoll::
	msgbox Athens_GameCorner_Text_CantWinJackpot, MSGBOX_DEFAULT
	release
	end

Athens_GameCorner_EventScript_PokefanM::
	lock
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, TRUE, Athens_GameCorner_EventScript_TryGive20Coins
	msgbox Athens_GameCorner_Text_NeedCoinCaseGoNextDoor, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_NPCReturnToSlots
	end

Athens_GameCorner_EventScript_TryGive20Coins::
	goto_if_set FLAG_RECEIVED_20_COINS, Athens_GameCorner_EventScript_PokefanMNormal
	checkcoins VAR_TEMP_1
	goto_if_ge VAR_TEMP_1, 1, Athens_GameCorner_EventScript_PokefanMNormal @ Only give 20 coins if player has no coins
	setflag FLAG_RECEIVED_20_COINS
	addcoins 20
	msgbox Athens_GameCorner_Text_LuckOnlyLastSoLongTakeCoins, MSGBOX_DEFAULT
	playse SE_SHOP
	goto Athens_GameCorner_EventScript_PokefanMNormal
	end

Athens_GameCorner_EventScript_PokefanMNormal::
	msgbox Athens_GameCorner_Text_MauvilleSomethingForEveryone, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_NPCReturnToSlots
	end

Athens_GameCorner_EventScript_OldMan::
	lock
	faceplayer
	msgbox Athens_GameCorner_Text_RouletteTablesDifferentRates, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_NPCReturnToSlots
	end

Athens_GameCorner_EventScript_Cook::
	lock
	faceplayer
	msgbox Athens_GameCorner_Text_EasyToLoseTrackOfTime, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_NPCReturnToSlots
	end

Athens_GameCorner_EventScript_Man::
	lock
	faceplayer
	msgbox Athens_GameCorner_Text_UpTo3CoinsCanBeUsed, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_NPCReturnToSlots
	end

Athens_GameCorner_EventScript_NPCReturnToSlots::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Athens_GameCorner_EventScript_Maniac::
	lock
	faceplayer
	msgbox Athens_GameCorner_Text_DifficultToStopOn7, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_NPCReturnToSlots
	end

Athens_GameCorner_EventScript_Woman::
	lock
	faceplayer
	msgbox Athens_GameCorner_Text_HeresSomeSlotsInfo, MSGBOX_DEFAULT
	goto Athens_GameCorner_EventScript_NPCReturnToSlots
	end

Athens_GameCorner_EventScript_SlotMachine0::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine1::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine2::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine3::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 3
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine4::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 4
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine5::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 5
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine6::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 6
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine7::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 7
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine8::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 8
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine9::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 9
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine10::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 10
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_SlotMachine11::
	lockall
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Athens_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 11
	specialvar VAR_RESULT, GetSlotMachineId
	playslotmachine VAR_RESULT
	releaseall
	end

Athens_GameCorner_EventScript_NoCoinCase::
	msgbox Athens_GameCorner_Text_CantPlayWithNoCoinCase, MSGBOX_DEFAULT
	releaseall
	end

Athens_GameCorner_Text_ThisIsMauvilleGameCorner:
	.string "This is ATHENS GAME CORNER.$"

Athens_GameCorner_Text_NeedCoinCaseForCoins:
	.string "Okay, you wanted some COINS for\n"
	.string "the games?\p"
	.string "But you don't have a COIN CASE for\n"
	.string "stowing the COINS.$"

Athens_GameCorner_Text_WereYouLookingForCoins:
	.string "Were you looking for COINS?\p"
	.string "It's ¥1000 for 50 COINS.\n"
	.string "Would you like some?$"

Athens_GameCorner_Text_ThankYouHereAreYourCoins:
	.string "Thank you very much!\n"
	.string "Here are your COINS!$"

Athens_GameCorner_Text_DontHaveEnoughMoney:
	.string "Um… You don't appear to have\n"
	.string "enough money…$"

Athens_GameCorner_Text_CoinCaseIsFull:
	.string "Oh?\n"
	.string "Your COIN CASE is full.$"

Athens_GameCorner_Text_DontNeedCoinsThen:
	.string "Oh… You don't need COINS, then?\n"
	.string "Good luck on your adventure!$"

Athens_GameCorner_Text_ExchangeCoinsForPrizes:
	.string "Welcome.\p"
	.string "You can exchange your COINS for\n"
	.string "prizes here.$"

Athens_GameCorner_Text_WhichPrize:
	.string "Which prize would you like?$"

Athens_GameCorner_Text_SoYourChoiceIsTheTMX:
	.string "So your choice is\n"
	.string "the {STR_VAR_1} {STR_VAR_2}?$"

Athens_GameCorner_Text_SendToYourHomePC:
	.string "Thank you!\n"
	.string "We'll send it to your PC at home.$"

Athens_GameCorner_Text_NotEnoughCoins:
	.string "You don't have enough COINS.$"

@ Unused
Athens_GameCorner_Text_NoRoomForPlacingDecor:
	.string "There isn't any room available for\n"
	.string "placing {STR_VAR_1}.$"

Athens_GameCorner_Text_OhIsThatSo:
	.string "Oh, is that so? \n"
	.string "You need to save some COINS before\l"
	.string "coming back here.$"

Athens_GameCorner_Text_SoYourChoiceIsX:
	.string "So your choice is {STR_VAR_1}?$"

Athens_GameCorner_Text_HereYouGo:
	.string "Here you go!$"

@ Unused
Athens_GameCorner_Text_CantCarryAnyMore:
	.string "Oh, you can't carry any more than that.$"

Athens_GameCorner_Text_GotTwoOfSameDollWantOne:
	.string "I made a mistake and got two of\n"
	.string "the same DOLLS.\p"
	.string "Would you like one of them?$"

Athens_GameCorner_Text_HereYouGo2:
	.string "Here you go!$"

Athens_GameCorner_Text_YouWantItButNotNow:
	.string "Huh?\n"
	.string "You want it, but not right now?$"

Athens_GameCorner_Text_DontBeNegative:
	.string "Oh, don't be so negative!\n"
	.string "You can have this!$"

Athens_GameCorner_Text_CantWinJackpot:
	.string "There's a prize I want, but I can't win\n"
	.string "the jackpot.$"

Athens_GameCorner_Text_NeedCoinCaseGoNextDoor:
	.string "Hey, kid, if you want to play here,\n"
	.string "you need a COIN CASE.\p"
	.string "I think the young lady next door\n"
	.string "had one. Go see her!$"

Athens_GameCorner_Text_LuckOnlyLastSoLongTakeCoins:
	.string "My luck can only last so long.\n"
	.string "This is too much for me.\l"
	.string "Here, take some COINS!$"

Athens_GameCorner_Text_MauvilleSomethingForEveryone:
	.string "ATHENS has something for\n"
	.string "everyone.\p"
	.string "For me, it's the GAME CORNER.$"

Athens_GameCorner_Text_RouletteTablesDifferentRates:
	.string "The ROULETTE tables have different\n"
	.string "rates.\p"
	.string "Check your COINS if you're going to\n"
	.string "pick a table.$"

Athens_GameCorner_Text_EasyToLoseTrackOfTime:
	.string "It's easy to lose track of time in here. \n"
	.string "I should get back to work.$"

Athens_GameCorner_Text_CoinsAreNeededToPlay:
	.string "COINS are needed to play here\n"
	.string "in the GAME CORNER.$"

Athens_GameCorner_Text_RouletteOnlyLuck:
	.string "This ROULETTE thing…\n"
	.string "It's rather demanding.\p"
	.string "Win or lose, it's only by luck.$"

Athens_GameCorner_Text_UpTo3CoinsCanBeUsed:
	.string "Up to three COINS can be used to play\n"
	.string "the SLOTS.$"

Athens_GameCorner_Text_DifficultToStopOn7:
	.string "It's very difficult to make it stop\n"
	.string "right on “7.”\p"
	.string "If it stops on “7” during the REEL TIME\n"
	.string "bonus game, you'll receive extra COINS.$"

Athens_GameCorner_Text_HeresSomeSlotsInfo:
	.string "Here's some information for you\n"
	.string "about the SLOTS.\p"
	.string "The more lightning bolts you stock,\n"
	.string "the more REEL TIME chances you get.\p"
	.string "In a game with the maximum five\n"
	.string "REEL TIME chances…\p"
	.string "It is possible to receive four regular\n"
	.string "bonuses, then a big bonus.\p"
	.string "That would total 660 COINS, but it's\n"
	.string "very difficult to get.$"

Athens_GameCorner_Text_CantPlayWithNoCoinCase:
	.string "You can't play if you don't have\n"
	.string "a COIN CASE.$"

