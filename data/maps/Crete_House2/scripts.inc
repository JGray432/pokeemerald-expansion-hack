Crete_House2_MapScripts::
	.byte 0

Crete_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, Crete_House2_EventScript_ExplainSilkScarf
	msgbox Crete_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SERIOUS_MINT
	goto_if_eq VAR_RESULT, FALSE, Crete_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

Crete_House2_EventScript_NoRoomForScarf::
	msgbox Crete_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

Crete_House2_EventScript_ExplainSilkScarf::
	msgbox Crete_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

Crete_House2_EventScript_Boy::
	msgbox Crete_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

Crete_House2_Text_WantYouToHaveSilkScarf:
	.string "Hey kiddo, thanks for stopping by!\p"
	.string "Take one of these for your troubles.$"

Crete_House2_Text_NoRoom:
	.string "Oh, you don't have room?\p"
	.string "Now, listen tight, this SCARF is a must-\n"
	.string "have! Why, I would sell all my items\l"
	.string "in order to get it!$"

Crete_House2_Text_ExplainSilkScarf:
	.string "A Serious nature is nothing glamorous\n"
	.string "but sometimes it's just what your \l"
	.string "pokemon needs!$"

Crete_House2_Text_BrawlySoCool:
	.string "Wow, you bothered to cross the sea\n"
	.string "to visit CRETE?\p"
	.string "Did you maybe come here to see the \n"
	.string "labyrinth?\p"
	.string "I've heard some scary sounds coming out\n"
	.string "of that place recently.\p"
	.string "If you're planning a visit then be careful!$"

