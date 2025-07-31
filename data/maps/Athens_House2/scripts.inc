Athens_House2_MapScripts::
	.byte 0

Athens_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, Athens_House2_EventScript_ReceivedCoinCase
	msgbox Athens_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, Athens_House2_EventScript_AskToTradeForHarborMail
	release
	end

Athens_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox Athens_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Athens_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, Athens_House2_EventScript_DeclineTrade
	end

Athens_House2_EventScript_AcceptTrade::
	msgbox Athens_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	giveitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_HARBOR_MAIL
	setflag FLAG_RECEIVED_COIN_CASE
	goto Athens_House2_EventScript_ReceivedCoinCase
	end

Athens_House2_EventScript_ReceivedCoinCase::
	msgbox Athens_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

Athens_House2_EventScript_DeclineTrade::
	msgbox Athens_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

Athens_House2_Text_BuyHarborMailAtSlateport:
	.string "Sigh...\p"
	.string "My lover set sail to Kalos and \n"
	.string "I have no way to contact them.\p"
	.string "If only I had some HARBOR MAIL...$"

Athens_House2_Text_TradeHarborMailForCoinCase:
	.string "Oh! You have HARBOR MAIL?\n"
	.string "Will you trade it for a COIN CASE?$"

Athens_House2_Text_IllTradeYouCoinCase:
	.string "Oh, I'm so happy!\n"
	.string "Okay, I'll trade you a COIN CASE!$"

Athens_House2_Text_UseCoinCaseAtGameCorner:
	.string "That COIN CASE can be used\n"
	.string "at the GAME CORNER.$"

Athens_House2_Text_ThatsDisappointing:
	.string "Oh, that's disappointing.\p"
	.string "A COIN CASE is needed for the\n"
	.string "GAME CORNER.$"

