.set LOCALID_BRINEY, 11
.set LOCALID_WANDAS_BF_OUTSIDE, 21

Route8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route8_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route8_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route8_OnFrame
	.byte 0

Route8_OnTransition:
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route8_EventScript_SetWandasBoyfriendPos
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_8_NORTH, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_8_SOUTH, AbnormalWeather_StartGroudonWeather
	end

Route8_EventScript_SetWandasBoyfriendPos::
	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
	return

Route8_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_8_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute8North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_8_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute8South
	end

Route8_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route8_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route8_EventScript_BoyfriendGruntLeftTunnel
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route8_EventScript_BoyfriendGruntInTunnel
	msgbox Route8_Text_WantToDigTunnel, MSGBOX_DEFAULT
	release
	end

Route8_EventScript_BoyfriendGruntLeftTunnel::
	msgbox Route8_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
	release
	end

Route8_EventScript_BoyfriendGruntInTunnel::
	msgbox Route8_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
	release
	end

Route8_EventScript_DevonEmployee::
	lock
	faceplayer
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route8_EventScript_TryGiveRepeatBallAgain
	msgbox Route8_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
	goto Route8_EventScript_GiveRepeatBall
	end

Route8_EventScript_GiveRepeatBall::
	setflag FLAG_MET_DEVON_EMPLOYEE
	giveitem ITEM_REPEAT_BALL
	goto_if_eq VAR_RESULT, FALSE, Route8_EventScript_NoRoomForRepeatBall
	msgbox Route8_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, Route8_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_SOUTH, Route8_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_WEST, Route8_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_EAST, Route8_EventScript_DevonEmployeeExitEast
	removeobject VAR_LAST_TALKED
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setflag FLAG_RECEIVED_REPEAT_BALL
	release
	end

Route8_EventScript_DevonEmployeeExit::
	applymovement VAR_LAST_TALKED, Route8_Movement_DevonEmployeeExit
	waitmovement 0
	return

Route8_EventScript_DevonEmployeeExitEast::
	applymovement VAR_LAST_TALKED, Route8_Movement_DevonEmployeeExitEast
	waitmovement 0
	return

Route8_EventScript_TryGiveRepeatBallAgain::
	msgbox Route8_Text_TokenOfAppreciation, MSGBOX_DEFAULT
	goto Route8_EventScript_GiveRepeatBall
	end

Route8_EventScript_NoRoomForRepeatBall::
	msgbox Route8_Text_BagIsJamPacked, MSGBOX_DEFAULT
	release
	end

Route8_Movement_DevonEmployeeExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route8_Movement_DevonEmployeeExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route8_EventScript_RouteSignRustboro::
	msgbox Route8_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route8_EventScript_RusturfTunnelSign::
	msgbox Route8_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

Route8_EventScript_TunnelersRestHouseSign::
	msgbox Route8_Text_TunnelersRestHouse, MSGBOX_SIGN
	end

Route8_EventScript_TrainerTipsBToStopEvolution::
	msgbox Route8_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
	end

Route8_EventScript_TrainerTipsBagHasPockets::
	msgbox Route8_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
	end

Route8_EventScript_Briney::
	lock
	faceplayer
	msgbox Route8_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE8_STATE, 2
	release
	end

Route8_EventScript_BrineyTrigger::
	lockall
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox Route8_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_ROUTE8_STATE, 2
	releaseall
	end

Route8_EventScript_GlassesMan::
	lock
	faceplayer
	checkitem ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, TRUE, Route8_EventScript_PlayerHasGlasses
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route8_EventScript_FoundGlassesNotOnPlayer
	msgbox Route8_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	release
	end

Route8_EventScript_FoundGlassesNotOnPlayer::
	msgbox Route8_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
	closemessage
	goto Route8_EventScript_GlassesManExit
	end

Route8_EventScript_PlayerHasGlasses::
	msgbox Route8_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	msgbox Route8_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route8_EventScript_FoundGlassesOnPlayer
	msgbox Route8_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
	release
	end

Route8_EventScript_FoundGlassesOnPlayer::
	msgbox Route8_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
	closemessage
	goto Route8_EventScript_GlassesManExit
	end

Route8_EventScript_GlassesManExit::
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, Route8_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_SOUTH, Route8_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_WEST, Route8_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_EAST, Route8_EventScript_GlassesManExitEast
	removeobject VAR_LAST_TALKED
	release
	end

Route8_EventScript_GlassesManExitNormal::
	applymovement VAR_LAST_TALKED, Route8_Movement_GlassesManExit
	waitmovement 0
	return

Route8_EventScript_GlassesManExitEast::
	applymovement VAR_LAST_TALKED, Route8_Movement_GlassesManExitEast
	waitmovement 0
	return

Route8_Movement_GlassesManExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route8_Movement_GlassesManExitEast:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route8_EventScript_Joey::
	trainerbattle_single TRAINER_JOEY, Route8_Text_JoeyIntro, Route8_Text_JoeyDefeat
	msgbox Route8_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE, Route8_Text_JoseIntro, Route8_Text_JoseDefeat
	msgbox Route8_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY_1, Route8_Text_JerryIntro, Route8_Text_JerryDefeat, Route8_EventScript_TryRegisterJerryAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route8_EventScript_RematchJerry
	setvar VAR_0x8004, TRAINER_JERRY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route8_EventScript_TryRegisterJerry
	msgbox Route8_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route8_EventScript_TryRegisterJerryAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route8_EventScript_RegisterJerryAfterBattle
	release
	end

Route8_EventScript_RegisterJerryAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route8_Text_JerryRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route8_EventScript_TryRegisterJerry::
	goto_if_set FLAG_HAS_MATCH_CALL, Route8_EventScript_RegisterJerry
	msgbox Route8_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route8_EventScript_RegisterJerry::
	msgbox Route8_Text_JerryRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end

Route8_EventScript_RematchJerry::
	trainerbattle_rematch TRAINER_JERRY_1, Route8_Text_JerryRematchIntro, Route8_Text_JerryRematchDefeat
	msgbox Route8_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Clark::
	trainerbattle_single TRAINER_CLARK, Route8_Text_ClarkIntro, Route8_Text_ClarkDefeat
	msgbox Route8_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Janice::
	trainerbattle_single TRAINER_JANICE, Route8_Text_JaniceIntro, Route8_Text_JaniceDefeat
	msgbox Route8_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Karen::
	trainerbattle_single TRAINER_KAREN_1, Route8_Text_KarenIntro, Route8_Text_KarenDefeat, Route8_EventScript_TryRegisterKarenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route8_EventScript_RematchKaren
	setvar VAR_0x8004, TRAINER_KAREN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route8_EventScript_TryRegisterKaren
	msgbox Route8_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route8_EventScript_TryRegisterKarenAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route8_EventScript_RegisterKarenAfterBattle
	release
	end

Route8_EventScript_RegisterKarenAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route8_Text_KarenRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route8_EventScript_TryRegisterKaren::
	goto_if_set FLAG_HAS_MATCH_CALL, Route8_EventScript_RegisterKaren
	msgbox Route8_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route8_EventScript_RegisterKaren::
	msgbox Route8_Text_KarenRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route8_EventScript_RematchKaren::
	trainerbattle_rematch TRAINER_KAREN_1, Route8_Text_KarenRematchIntro, Route8_Text_KarenRematchDefeat
	msgbox Route8_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Sarah::
	trainerbattle_single TRAINER_SARAH, Route8_Text_SarahIntro, Route8_Text_SarahDefeat
	msgbox Route8_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Dawson::
	trainerbattle_single TRAINER_DAWSON, Route8_Text_DawsonIntro, Route8_Text_DawsonDefeat
	msgbox Route8_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Devan::
	trainerbattle_single TRAINER_DEVAN, Route8_Text_DevanIntro, Route8_Text_DevanDefeat
	msgbox Route8_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_EventScript_Johnson::
	trainerbattle_single TRAINER_JOHNSON, Route8_Text_JohnsonIntro, Route8_Text_JohnsonDefeat
	msgbox Route8_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route8_Text_ScoundrelMadeOffWithPeeko:
	.string "Ohhh, what am I to do?\p"
	.string "We were on our walk, PEEKO and I, when\n"
	.string "we were jumped by an odd thug…\p"
	.string "The scoundrel made off with my\n"
	.string "darling PEEKO!\p"
	.string "Wrrrooooooaaaar! PEEKO!$"

Route8_Text_WantToDigTunnel:
	.string "Nnn… Roar!\p"
	.string "I want to dig that tunnel!$"

Route8_Text_DiggingTunnelWhenGoonOrderedMeOut:
	.string "Nnn… Roar!\n"
	.string "What's going on?\p"
	.string "I was digging the tunnel without any\n"
	.string "tools when some goon ordered me out!\p"
	.string "That tunnel's filled with POKéMON\n"
	.string "that react badly to loud noises.\l"
	.string "They could cause an uproar.\p"
	.string "That's why we stopped using heavy\n"
	.string "equipment for tunneling…\p"
	.string "I'm worried that the goon will do\n"
	.string "something stupid and startle the\l"
	.string "POKéMON into an uproar.$"

Route8_Text_GoonHightailedItOutOfTunnel:
	.string "Nnn… Roar!\p"
	.string "That goofy goon hightailed it out of\n"
	.string "the tunnel! I can go back to digging!$"

Route8_Text_ThankYouTokenOfAppreciation:
	.string "Oh! It's you!\p"
	.string "You're that person who not only helped\n"
	.string "me in ENTOMO WOODS, but also got\l"
	.string "back my stolen package and then even\l"
	.string "graciously delivered it to SLATEPORT!\p"
	.string "CAPT. STERN informed us that the\n"
	.string "package arrived, too!\p"
	.string "I thank you very, very much!\p"
	.string "Why, if I were a rain cloud, I would\n"
	.string "shower you with gratitude and hail\l"
	.string "you as a hero!\p"
	.string "For you, the most wonderful TRAINER,\n"
	.string "I bear good news!\p"
	.string "Recently, our company developed\n"
	.string "a new kind of POKé BALL.\p"
	.string "As a token of our appreciation, this\n"
	.string "is our gift to our wonderful TRAINER!$"

Route8_Text_NewBallAvailableAtMart:
	.string "Our new POKé BALL will be available\n"
	.string "at the POKéMON MART in RUSTBORO.\p"
	.string "Please do try it out!\n"
	.string "Thank you and bye-bye!$"

Route8_Text_BagIsJamPacked:
	.string "Your BAG is jam-packed.\n"
	.string "I can't give you this REPEAT BALL.$"

Route8_Text_TokenOfAppreciation:
	.string "As a token of our appreciation for\n"
	.string "your delivering our package, I have\l"
	.string "a gift of a new kind of POKé BALL\l"
	.string "for our most wonderful TRAINER!$"

Route8_Text_CanYouHelpMeFindGlasses:
	.string "I dropped my glasses…\n"
	.string "Can you help me find them?$"

Route8_Text_MayISeeThoseGlasses:
	.string "Those glasses!\n"
	.string "May I see them for a second?$"

Route8_Text_NotWhatImLookingForMaybeTheyArentHere:
	.string "Hmm…\n"
	.string "These are BLACKGLASSES.\l"
	.string "They're not what I'm looking for…\p"
	.string "Maybe my glasses aren't around\n"
	.string "here…$"

Route8_Text_CantFindGlassesNotHere:
	.string "Hmm…\n"
	.string "I can't find my glasses anywhere…\l"
	.string "Maybe they're not around here…$"

Route8_Text_NotWhatImLookingFor:
	.string "Hmm…\n"
	.string "These are BLACKGLASSES.\l"
	.string "They're not what I'm looking for…$"

Route8_Text_RouteSignRustboro:
	.string "ROUTE 8\n"
	.string "{LEFT_ARROW} RUSTBORO CITY$"

Route8_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL\n"
	.string "“Linking RUSTBORO and VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

Route8_Text_TunnelersRestHouse:
	.string "TUNNELER'S REST HOUSE$"

Route8_Text_TrainerTipsBToStopEvolution:
	.string "TRAINER TIPS\p"
	.string "If you want to stop a POKéMON from\n"
	.string "evolving, press the B Button while it\l"
	.string "is trying to evolve.\l"
	.string "The startled POKéMON will stop.\p"
	.string "This is called an evolution cancel.$"

Route8_Text_TrainerTipsBagHasPockets:
	.string "TRAINER TIPS\p"
	.string "Your BAG has several POCKETS.\p"
	.string "Items you obtain are automatically\n"
	.string "placed in the appropriate POCKETS.\p"
	.string "No TRAINER can afford to be without\n"
	.string "a BAG of their own.$"

