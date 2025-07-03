Labyrinth_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Labyrinth_FirstRoom_PlayerJustEntered
	.byte 0

Labyrinth_FirstRoom_PlayerJustEntered::
	clearflag FLAG_TEMP_MINOTAUR_BATTLE_IN_PROGRESS
	end

Labyrinth_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, Labyrinth_1F_EventScript_ReceivedFlash
	msgbox Labyrinth_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox Labyrinth_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

Labyrinth_1F_EventScript_ReceivedFlash::
	msgbox Labyrinth_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

Labyrinth_1F_EventScript_David::
	trainerbattle_single TRAINER_DAVID, Route3_Text_DavidIntro, Route3_Text_DavidDefeated
	msgbox Route3_Text_DavidPostBattle, MSGBOX_AUTOCLOSE
	end

Labyrinth_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

Labyrinth_1F_Text_ExplainFlash:
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from CRETE's POKéMON GYM.$"

