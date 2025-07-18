.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

EntomoWoods_MapScripts::
	.byte 0

EntomoWoods_EventScript_DevonResearcherLeft::
	lockall
	call EntomoWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, EntomoWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox EntomoWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, EntomoWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox EntomoWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, EntomoWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox EntomoWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, EntomoWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox EntomoWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, EntomoWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox EntomoWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HARRY, EntomoWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, EntomoWoods_Movement_AquaBackOff
	waitmovement 0
	call EntomoWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, EntomoWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, EntomoWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto EntomoWoods_EventScript_RemoveDevonResearcher
	end

EntomoWoods_EventScript_DevonResearcherRight::
	lockall
	call EntomoWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, EntomoWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox EntomoWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, EntomoWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox EntomoWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, EntomoWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox EntomoWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, EntomoWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox EntomoWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox EntomoWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_HARRY, EntomoWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, EntomoWoods_Movement_AquaBackOff
	waitmovement 0
	call EntomoWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, EntomoWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, EntomoWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto EntomoWoods_EventScript_RemoveDevonResearcher
	end

EntomoWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, EntomoWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox EntomoWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

EntomoWoods_EventScript_DevonResearcherPostBattle::
	msgbox EntomoWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, EntomoWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EntomoWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, EntomoWoods_EventScript_BagFull
	goto EntomoWoods_EventScript_DevonResearcherFinish
	end

EntomoWoods_EventScript_BagFull::
	msgbox EntomoWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto EntomoWoods_EventScript_DevonResearcherFinish
	end

EntomoWoods_EventScript_DevonResearcherFinish::
	msgbox EntomoWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, EntomoWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox EntomoWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

EntomoWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_ENTOMO_WOODS_STATE, 1
	releaseall
	end

EntomoWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

EntomoWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

EntomoWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

EntomoWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

EntomoWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

EntomoWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

EntomoWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

EntomoWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

EntomoWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

EntomoWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

EntomoWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

EntomoWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

EntomoWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

EntomoWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

EntomoWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

EntomoWoods_EventScript_Boy1::
	msgbox EntomoWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

EntomoWoods_EventScript_Boy2::
	msgbox EntomoWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

EntomoWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, EntomoWoods_EventScript_ExplainMiracleSeed
	msgbox EntomoWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

EntomoWoods_EventScript_ExplainMiracleSeed::
	msgbox EntomoWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

EntomoWoods_EventScript_Sign1::
	msgbox EntomoWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

EntomoWoods_EventScript_Sign2::
	msgbox EntomoWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

EntomoWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, EntomoWoods_Text_GoBugPokemonTeam, EntomoWoods_Text_ICouldntWin
	msgbox EntomoWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

EntomoWoods_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY, EntomoWoods_Text_GoBugPokemonTeam, EntomoWoods_Text_ICouldntWin
	msgbox EntomoWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

EntomoWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, EntomoWoods_Text_InstantlyPopularWithBugPokemon, EntomoWoods_Text_CantBePopularIfILose, EntomoWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, EntomoWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, EntomoWoods_EventScript_TryRegisterJames2
	msgbox EntomoWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

EntomoWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, EntomoWoods_EventScript_RegisterJames
	release
	end

EntomoWoods_EventScript_RegisterJames::
	msgbox EntomoWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

EntomoWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, EntomoWoods_EventScript_RegisterJames2
	msgbox EntomoWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

EntomoWoods_EventScript_RegisterJames2::
	msgbox EntomoWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

EntomoWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, EntomoWoods_Text_MyPokemonHaveGrown, EntomoWoods_Text_CantBePopularIfLose
	msgbox EntomoWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

EntomoWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "Not a one to be found…$"

EntomoWoods_Text_HaveYouSeenShroomish:
	.string "Hello, have you seen any POKéMON\n"
	.string "called SHROOMISH around here?\p"
	.string "I really love that POKéMON.$"

EntomoWoods_Text_IWasGoingToAmbushYou:
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in ENTOMO WOODS\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"

EntomoWoods_Text_HandOverThosePapers:
	.string "You! DEVON RESEARCHER!\p"
	.string "Hand over those papers!$"

EntomoWoods_Text_YouHaveToHelpMe:
	.string "Aiyeeeh!\p"
	.string "You're a POKéMON TRAINER, aren't you?\n"
	.string "You've got to help me, please!$"

EntomoWoods_Text_NoOneCrossesTeamAqua:
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses TEAM AQUA\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"

EntomoWoods_Text_YoureKiddingMe:
	.string "You're kidding me! You're tough!$"

EntomoWoods_Text_YouveGotSomeNerve:
	.string "Grrr… You've got some nerve\n"
	.string "meddling with TEAM AQUA!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "POKéMON…\p"
	.string "And, hey, we of TEAM AQUA are also\n"
	.string "after something in RUSTBORO.\p"
	.string "I'll let you go today!$"

EntomoWoods_Text_ThatWasAwfullyClose:
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a GREAT BALL as\n"
	.string "my thanks!$"

EntomoWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Didn't that TEAM AQUA thug say\n"
	.string "they were after something in\l"
	.string "RUSTBORO, too?$"

EntomoWoods_Text_ICantBeWastingTime:
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"

EntomoWoods_Text_YoureLoadedWithItems:
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

EntomoWoods_Text_GoBugPokemonTeam:
	.string "I caught a whole bunch of POKéMON!\p"
	.string "Go, go, go!\n"
	.string "My BUG POKéMON team!$"

EntomoWoods_Text_ICouldntWin:
	.string "I have all these POKéMON,\n"
	.string "but I couldn't win…$"

EntomoWoods_Text_ImOutOfPokeBalls:
	.string "I caught a bunch of POKéMON.\n"
	.string "Now I'm out of POKé BALLS.$"

EntomoWoods_Text_InstantlyPopularWithBugPokemon:
	.string "If you take BUG POKéMON to school,\n"
	.string "you get to be instantly popular!$"

EntomoWoods_Text_CantBePopularIfILose:
	.string "I can't be popular if I lose.$"

EntomoWoods_Text_PeopleRespectYou:
	.string "If you have a big BUG POKéMON,\n"
	.string "people respect you for it.$"

EntomoWoods_Text_IWantRematch1:
	.string "I want a rematch when my BUG\n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

EntomoWoods_Text_IWantRematch2:
	.string "I want a rematch when my BUG \n"
	.string "POKéMON grow up!\p"
	.string "I'm registering you in my POKéNAV!$"

EntomoWoods_Text_MyPokemonHaveGrown:
	.string "My BUG POKéMON have grown.\n"
	.string "I'll be popular again.$"

EntomoWoods_Text_CantBePopularIfLose:
	.string "I can't be popular if I lose.$"

EntomoWoods_Text_IveBeenTrainingHard:
	.string "You get to be popular if you have\n"
	.string "strong POKéMON, right?\l"
	.string "So, I've been training hard.$"

EntomoWoods_Text_StayOutOfTallGrass:
	.string "Yo, there!\n"
	.string "Your POKéMON doing okay?\p"
	.string "If your POKéMON are weak and you want\n"
	.string "to avoid battles, you should stay out\l"
	.string "of tall grass.$"

EntomoWoods_Text_HiddenItemsExplanation:
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"

EntomoWoods_Text_TryUsingThisItem:
	.string "Oh, neat!\n"
	.string "That's the BADGE from RUSTBORO GYM!\p"
	.string "You must be a TRAINER.\n"
	.string "You should try using this item.$"

EntomoWoods_Text_MiracleSeedExplanation:
	.string "It's a MIRACLE SEED.\n"
	.string "If a POKéMON holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides MIRACLE SEED, I think there are\n"
	.string "other convenient items for POKéMON\l"
	.string "to hold.$"

EntomoWoods_Text_TrainerTipsExperience:
	.string "TRAINER TIPS\p"
	.string "Any POKéMON that appears even once\n"
	.string "in a battle is awarded EXP Points.\p"
	.string "To raise a weak POKéMON, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn EXP Points without\l"
	.string "being exposed to any harm.$"

EntomoWoods_Text_TrainerTipsPP:
	.string "TRAINER TIPS\p"
	.string "In addition to Hit Points (HP), POKéMON\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a POKéMON runs out of PP, it must be\n"
	.string "taken to a POKéMON CENTER.$"

