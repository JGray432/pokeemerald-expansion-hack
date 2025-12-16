ROUTE2_MapScripts::
	.byte 0

ROUTE2_EventScript_LittleBoy::
	msgbox ROUTE2_Text_ImNotVeryTall, MSGBOX_NPC
	end

ROUTE2_EventScript_RouteSignOldale::
	msgbox ROUTE2_Text_RouteSignOldale, MSGBOX_SIGN
	end

ROUTE2_EventScript_RouteSignPetalburg::
	msgbox ROUTE2_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

ROUTE2_EventScript_Boy::
	msgbox ROUTE2_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

ROUTE2_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, ROUTE2_Text_CalvinIntro, ROUTE2_Text_CalvinDefeated, ROUTE2_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, ROUTE2_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, ROUTE2_EventScript_CalvinTryRegister
	msgbox ROUTE2_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

ROUTE2_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, ROUTE2_EventScript_CalvinRegisterMatchCall
	release
	end

ROUTE2_EventScript_CalvinRegisterMatchCall::
	msgbox ROUTE2_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

ROUTE2_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, ROUTE2_EventScript_CalvinRegister
	msgbox ROUTE2_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

ROUTE2_EventScript_CalvinRegister::
	msgbox ROUTE2_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

ROUTE2_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, ROUTE2_Text_CalvinRematchIntro, ROUTE2_Text_CalvinRematchDefeated
	msgbox ROUTE2_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

ROUTE2_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, ROUTE2_Text_RickIntro, ROUTE2_Text_RickDefeated
	msgbox ROUTE2_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

ROUTE2_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, ROUTE2_Text_TianaIntro, ROUTE2_Text_TianaDefeated
	msgbox ROUTE2_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

ROUTE2_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, ROUTE2_Text_AllenIntro, ROUTE2_Text_AllenDefeated
	msgbox ROUTE2_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

ROUTE2_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

ROUTE2_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

ROUTE2_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

ROUTE2_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

ROUTE2_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

ROUTE2_Text_RouteSignOldale:
	.string "ROUTE 102\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

ROUTE2_Text_RouteSignPetalburg:
	.string "ROUTE 102\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"
