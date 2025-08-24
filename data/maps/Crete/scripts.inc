@ Sailing to and from Crete uses local IDs from different maps
@ e.g. Route 104's sail to Crete script references local IDs from Crete's map
@ All of these local IDs are labeled here
.equ LOCALID_BRINEY_CRETE, 2
.equ LOCALID_BOAT_CRETE, 4

.equ LOCALID_BOAT_R109, 1
.equ LOCALID_BRINEY_R109, 2

.equ LOCALID_BOAT_R104, 7
.equ LOCALID_BRINEY_R104, 8

Crete_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Crete_OnTransition
	.byte 0

Crete_OnTransition:
	setflag FLAG_VISITED_CRETE
	end

Crete_EventScript_Briney::
	lock
	faceplayer
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, Crete_EventScript_NoReturnPrompt
	msgbox Crete_Text_WhereAreWeBound, MSGBOX_NPC
	msgbox Crete_SailBackToAthens_Briney, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Crete_EventScript_ChooseSlateport
	goto_if_eq VAR_RESULT, NO, Crete_EventScript_CancelSailSelect
	end

Crete_EventScript_ChooseDelphi::
	msgbox Crete_Text_DelphiWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto Crete_EventScript_SailToDelphi
	release
	end

Crete_EventScript_ChooseSlateport::
	msgbox Crete_Text_SlateportWereSettingSail, MSGBOX_DEFAULT
	closemessage
	goto Crete_EventScript_SailToSlateport
	release
	end

Crete_EventScript_CancelSailSelect::
	msgbox Crete_Text_JustTellMeWhenYouNeedToSetSail, MSGBOX_DEFAULT
	closemessage
	release
	end

Crete_EventScript_NoReturnPrompt::
	msgbox Crete_Text_GoDeliverIllBeWaiting, MSGBOX_DEFAULT
	release
	end

Crete_EventScript_SailBackToDelphi::
	msgbox Crete_Text_DelphiWereSettingSail2, MSGBOX_DEFAULT
	closemessage
	goto Crete_EventScript_SailToDelphi
	end

Crete_EventScript_Woman::
	msgbox Crete_Text_TinyIslandCommunity, MSGBOX_NPC
	end

Crete_EventScript_TownSign::
	msgbox Crete_Text_TownSign, MSGBOX_SIGN
	end

Crete_EventScript_GymSign::
	msgbox Crete_Text_GymSign, MSGBOX_SIGN
	end

Crete_EventScript_HallSign::
	msgbox Crete_Text_HallSign, MSGBOX_SIGN
	end

Crete_EventScript_OldRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_ROD, Crete_EventScript_HowsFishing
	msgbox Crete_Text_GettingItchToFish, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Crete_EventScript_GiveOldRod
	goto_if_eq VAR_RESULT, NO, Crete_EventScript_NotGettingItchToFish
	end

Crete_EventScript_GiveOldRod::
	msgbox Crete_Text_GiveYouOneOfMyRods, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox Crete_Text_ThrowInFishingAdvice, MSGBOX_DEFAULT
	release
	end

Crete_EventScript_NotGettingItchToFish::
	msgbox Crete_Text_ThatsTooBadThen, MSGBOX_DEFAULT
	release
	end

Crete_EventScript_HowsFishing::
	message Crete_Text_HowsYourFishing
	waitmessage
	multichoice 20, 8, MULTI_HOWS_FISHING, TRUE
	goto_if_eq VAR_RESULT, 0, Crete_EventScript_FishingExcellent
	goto_if_eq VAR_RESULT, 1, Crete_EventScript_FishingNotSoGood
	end

Crete_EventScript_FishingExcellent::
	msgbox Crete_Text_GreatHaulInSomeBigOnes, MSGBOX_DEFAULT
	release
	end

Crete_EventScript_FishingNotSoGood::
	msgbox Crete_Text_FishingAdvice, MSGBOX_DEFAULT
	release
	end

Crete_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Crete_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart Athens_Mart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
Crete_Mart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	pokemartlistend

Crete_EventScript_UtilityScientist::
	lock
	faceplayer
	call Common_EventScript_UtilitiesScientist
	waitmessage
	release
	end

Crete_EventScript_SailToDelphi::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_CRETE, MAP_CRETE, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_CRETE, 0
	applymovement LOCALID_BRINEY_CRETE, Crete_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_CRETE
	applymovement OBJ_EVENT_ID_PLAYER, Crete_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CRETE
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_CRETE, Crete_Movement_SailToDelphi
	applymovement OBJ_EVENT_ID_PLAYER, Crete_Movement_SailToDelphi
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	call Common_EventScript_StopBrineysBoatMusic
	applymovement OBJ_EVENT_ID_PLAYER, Crete_Movement_ExitBoatDelphi
	waitmovement 0
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE104
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_CRETE
	hideobjectat LOCALID_BOAT_CRETE, MAP_CRETE
	setvar VAR_BOARD_BRINEY_BOAT_STATE, 2
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_CRETE
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 5, 4
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end

Crete_EventScript_SailToSlateport::
	call EventScript_BackupMrBrineyLocation
	setobjectsubpriority LOCALID_BRINEY_CRETE, MAP_CRETE, 0
	setobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_CRETE, 1
	applymovement LOCALID_BRINEY_CRETE, Crete_Movement_BrineyBoardBoat
	waitmovement 0
	removeobject LOCALID_BRINEY_CRETE
	applymovement OBJ_EVENT_ID_PLAYER, Crete_Movement_PlayerBoardBoat
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, MAP_CRETE
	call Common_EventScript_PlayBrineysBoatMusic
	applymovement LOCALID_BOAT_CRETE, Crete_Movement_SailToSlateport
	applymovement OBJ_EVENT_ID_PLAYER, Crete_Movement_SailToSlateport
	waitmovement 0
	call Common_EventScript_StopBrineysBoatMusic
	showobjectat OBJ_EVENT_ID_PLAYER, MAP_ROUTE3
	applymovement OBJ_EVENT_ID_PLAYER, Crete_Movement_ExitBoatSlateport
	waitmovement 0
	setobjectxyperm LOCALID_BRINEY_R109, 16, 9
	addobject LOCALID_BRINEY_R109
	setobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE3, 0
	clearflag FLAG_HIDE_ROUTE_3_MR_BRINEY
	addobject LOCALID_BOAT_R109
	clearflag FLAG_HIDE_ROUTE_3_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_CRETE
	hideobjectat LOCALID_BOAT_CRETE, MAP_CRETE
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, Crete_EventScript_LandedSlateportDeliverGoods
	call_if_set FLAG_DELIVERED_DEVON_GOODS, Crete_EventScript_LandedSlateport
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectsubpriority OBJ_EVENT_ID_PLAYER, MAP_CRETE
	resetobjectsubpriority LOCALID_BRINEY_R109, MAP_ROUTE3
	copyobjectxytoperm LOCALID_BRINEY_R109
	release
	end

Crete_EventScript_LandedSlateportDeliverGoods::
	msgbox Crete_Text_BrineyLandedInSlateportDeliverGoods, MSGBOX_DEFAULT
	return

Crete_EventScript_LandedSlateport::
	msgbox Crete_Text_BrineyLandedInSlateport, MSGBOX_DEFAULT
	return

Crete_Movement_SailToDelphi:
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Crete_Movement_SailToSlateport:
	walk_in_place_right
	walk_fast_right
	walk_fast_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_fast_up
	walk_fast_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_up
	walk_fast_up
	step_end

Crete_Movement_PlayerBoardBoat:
	walk_right
	walk_up
	step_end

Crete_Movement_ExitBoatDelphi:
	walk_up
	walk_up
	walk_up
	step_end

Crete_Movement_ExitBoatSlateport:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

Crete_Movement_BrineyBoardBoat:
	walk_up
	step_end

Crete_Movement_BrineyExitBoat:
	walk_up
	walk_up
	step_end

Crete_EventScript_TrendyPhraseBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox Crete_Text_XIsTheBiggestHappeningThingRight, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Crete_EventScript_ConfirmTrendyPhrase
	goto_if_eq VAR_RESULT, NO, Crete_EventScript_RejectTrendyPhrase
	end

Crete_EventScript_ConfirmTrendyPhrase::
	msgbox Crete_Text_YeahDefinitionOfInRightNow, MSGBOX_DEFAULT
	release
	end

Crete_EventScript_RejectTrendyPhrase::
	msgbox Crete_Text_TellMeWhatsNewAndIn, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, TRUE, Crete_EventScript_GiveNewTrendyPhrase
	goto_if_eq VAR_RESULT, FALSE, Crete_EventScript_CancelNewTrendyPhrase
	end

Crete_EventScript_GiveNewTrendyPhrase::
	incrementgamestat GAME_STAT_STARTED_TRENDS
	goto_if_eq VAR_0x8004, FALSE, Crete_EventScript_PhraseNotTrendyEnough
	msgbox Crete_Text_OfCourseIKnowAboutThat, MSGBOX_DEFAULT
	release
	end

Crete_EventScript_CancelNewTrendyPhrase::
	msgbox Crete_Text_HearOfAnyTrendsComeShareWithMe, MSGBOX_DEFAULT
	release
	end

Crete_EventScript_PhraseNotTrendyEnough::
	msgbox Crete_Text_XHuhIThinkYIsCool, MSGBOX_DEFAULT
	release
	end

Crete_Text_TinyIslandCommunity:
	.string "CRETE is a tiny island community.\n"
	.string "If something gets trendy here,\l"
	.string "everyone picks up on it right away.$"

Crete_Text_TownSign:
	.string "CRETE\n"
	.string "“A tiny island in the blue sea.”$"

Crete_Text_GymSign:
	.string "CRETE POKéMON GYM\n"
	.string "LEADER: BRAWLY\l"
	.string "“A big wave in fighting!”$"

Crete_Text_HallSign:
	.string "CRETE HALL\n"
	.string "“Everyone's information exchange!”$"

Route104_Text_LandedInCreteDeliverLetter:
	.string "CPT. MORGAN: Ahoy!\n"
	.string "We've hit land in CRETE.\p"
	.string "I suppose you're off to deliver that\n"
	.string "LETTER to, who was it now, STEVEN!$"

Crete_Text_SetSailBackToDelphi:
	.string "CPT. MORGAN: Have you delivered your\n"
	.string "LETTER?\p"
	.string "Or were you meaning to sail back to\n"
	.string "DELPHI?$"

Crete_Text_DelphiWereSettingSail2:
	.string "CPT. MORGAN: DELPHI it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

Crete_Text_GoDeliverIllBeWaiting:
	.string "CPT. MORGAN: What, who do you think\n"
	.string "I am, your personal chauffeur?\p"
	.string "We ain't leaving till you've got\n"
	.string "that thread!$"

Crete_Text_BrineyLandedInCrete:
	.string "CPT. MORGAN: Ahoy!\n"
	.string "We've hit land in CRETE!\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail again!$"

Crete_Text_WhereAreWeBound:
	.string "CPT. MORGAN: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Now, my friend, where are we bound?$"

Crete_Text_DelphiWereSettingSail:
	.string "CPT. MORGAN: DELPHI, is it?\p"
	.string "Anchors aweigh!\n"
	.string "PEEKO, we're setting sail, my darling!$"

Crete_Text_SlateportWereSettingSail:
	.string "CPT. MORGAN: Anchors aweigh!$"

Crete_SailBackToAthens_Briney:
	.string "CPT. MORGAN: You about ready \n"
	.string "to head back to ATHENS?$"

Crete_Text_JustTellMeWhenYouNeedToSetSail:
	.string "CPT. MORGAN: You just tell me whenever\n"
	.string "you need to set sail again!$"

Crete_Text_GettingItchToFish:
	.string "This is a renowned fishing spot.\n"
	.string "Are you getting the itch to fish?$"

Crete_Text_GiveYouOneOfMyRods:
	.string "I hear you, and I like what\n"
	.string "you're saying!\p"
	.string "I'll give you one of my fishing RODS.$"

Crete_Text_ThrowInFishingAdvice:
	.string "And, as an added bonus, I'll even throw\n"
	.string "in a little fishing advice!\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull on the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"

Crete_Text_ThatsTooBadThen:
	.string "Oh, is that so?\n"
	.string "That's too bad, then.$"

Crete_Text_HowsYourFishing:
	.string "Yo!\n"
	.string "How's your fishing?$"

Crete_Text_GreatHaulInSomeBigOnes:
	.string "Is that right! That's great!\n"
	.string "Haul in some big ones!$"

Crete_Text_FishingAdvice:
	.string "Oh, hey, don't get down on yourself!\n"
	.string "I'll give you a little fishing advice.\p"
	.string "First, you want to face the water,\n"
	.string "then use the ROD.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull the ROD.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your ROD\l"
	.string "to haul them in.$"

Crete_Text_XIsTheBiggestHappeningThingRight:
	.string "I like what's hip, happening, and trendy.\n"
	.string "I'm always checking it out.\p"
	.string "Listen, have you heard about this new\n"
	.string "“{STR_VAR_1}”?\p"
	.string "That's right!\n"
	.string "Of course you know!\p"
	.string "I mean, sheesh,\n"
	.string "“{STR_VAR_1}”…\l"
	.string "It's the hottest thing in cool!\p"
	.string "Wherever you're from,\n"
	.string "“{STR_VAR_1}”\l"
	.string "is the biggest happening thing, right?$"

Crete_Text_TellMeWhatsNewAndIn:
	.string "Hunh?\n"
	.string "It's not the hip and happening thing?\p"
	.string "Well, hey, you have to tell me,\n"
	.string "what's new and what's “in”?$"

Crete_Text_OfCourseIKnowAboutThat:
	.string "Hunh?\n"
	.string "“{STR_VAR_2}”?\p"
	.string "… …\p"
	.string "…Uh… Yeah! That's right!\n"
	.string "Yeah, I knew that! Knew it all along!\p"
	.string "Of course I know about that!\n"
	.string "“{STR_VAR_2},” right?\p"
	.string "Yeah, that's it, it's there!\n"
	.string "Isn't “{STR_VAR_2}”\l"
	.string "the coolest, or what?\p"
	.string "It's the hippest thing in hip.\n"
	.string "You think I'd not know about it?\p"
	.string "“{STR_VAR_1}”…\n"
	.string "It's, like, so five minutes ago.\p"
	.string "Now, “{STR_VAR_2}” is\n"
	.string "what's vital and in tune with the times!$"

Crete_Text_XHuhIThinkYIsCool:
	.string "Hmm…\n"
	.string "“{STR_VAR_2},” huh?\p"
	.string "But personally, I think\n"
	.string "“{STR_VAR_1}”\l"
	.string "is what's real in cool.$"

Crete_Text_HearOfAnyTrendsComeShareWithMe:
	.string "Well, if you hear of any happening new\n"
	.string "trends, come share them with me, okay?$"

Crete_Text_YeahDefinitionOfInRightNow:
	.string "Yeah, absolutely right!\p"
	.string "“{STR_VAR_1}” is the\n"
	.string "definition of “in” right now.$"
