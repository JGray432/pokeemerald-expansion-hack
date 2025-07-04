Athens_PokemonCenter_1F_EventScript_AthensOldMan::
	special Script_GetCurrentAthensMan
	switch VAR_RESULT
	case ATHENS_MAN_BARD, Athens_PokemonCenter_1F_EventScript_Bard
	case ATHENS_MAN_HIPSTER, Athens_PokemonCenter_1F_EventScript_Hipster
	case ATHENS_MAN_TRADER, Athens_PokemonCenter_1F_EventScript_Trader
	case ATHENS_MAN_STORYTELLER, Athens_PokemonCenter_1F_EventScript_Storyteller
	case ATHENS_MAN_GIDDY, Athens_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
Athens_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox Athens_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Athens_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_DeclineSong
	end

Athens_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, FALSE  @ Play his current song
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, Athens_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox Athens_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox Athens_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox Athens_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Athens_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

Athens_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, Athens_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox Athens_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, TRUE  @ Play the new song
	special PlayBardSong
	delay 60
	msgbox Athens_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox Athens_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox Athens_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
Athens_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox Athens_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, Athens_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox Athens_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, Athens_PokemonCenter_1F_EventScript_TeachWord
	msgbox Athens_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_TeachWord::
	msgbox Athens_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
Athens_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Hi, I'm the TRADER.\n"
	.string "Want to trade decorations with me?$"

Athens_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

Athens_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "But we've traded decorations already,\n"
	.string "you and I.$"

Athens_PokemonCenter_1F_Text_PickADecorItem:
	.string "If you see any decorative item that\n"
	.string "you want of mine, speak up.$"

Athens_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "You don't want anything?\n"
	.string "I feel unwanted…$"

Athens_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "That decorative item once belonged\n"
	.string "to {STR_VAR_1}.\p"
	.string "Do you want it?$"

Athens_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Uh… Wait a second. You don't have a\n"
	.string "single piece of decoration!$"

Athens_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "Okay, pick the decoration that you'll\n"
	.string "trade to me.$"

Athens_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "You won't trade with me?\n"
	.string "I feel unwanted…$"

Athens_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "You've got all the {STR_VAR_2}S that can\n"
	.string "be stored. You've no room for this.$"

Athens_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "Okay, so we'll trade my {STR_VAR_3}\n"
	.string "for your {STR_VAR_2}?$"

Athens_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "That piece of decoration is in use.\n"
	.string "You can't trade it.$"

Athens_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Then we'll trade!\n"
	.string "I'll send my decoration to your PC.$"

Athens_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Oops! Sorry! That's a really rare\n"
	.string "piece of decoration.\l"
	.string "I can't trade that one away!\p"
	.string "Can I interest you in something else?$"

Athens_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox Athens_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, Athens_PokemonCenter_1F_EventScript_AlreadyTraded
	message Athens_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto Athens_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

Athens_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox Athens_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox Athens_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, Athens_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, Athens_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox Athens_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, Athens_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto Athens_PokemonCenter_1F_EventScript_PickDecorToGive
	end

Athens_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox Athens_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_InvalidDecor::
	message Athens_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto Athens_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

Athens_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message Athens_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto Athens_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

Athens_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox Athens_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox Athens_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, Athens_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, Athens_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, Athens_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox Athens_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox Athens_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox Athens_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox Athens_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto Athens_PokemonCenter_1F_EventScript_PickDecorToGive
	end

Athens_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox Athens_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
Athens_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "I'm the STORYTELLER.\n"
	.string "I'll tell you tales of legendary\l"
	.string "TRAINERS.\p"
	.string "Will you hear my tale?$"

Athens_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

Athens_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "I know of these legends.\n"
	.string "Which tale will you have me tell?$"

Athens_PokemonCenter_1F_Text_IKnowNoTales:
	.string "But, I know of no legendary TRAINERS.\n"
	.string "Hence, I know no tales.\p"
	.string "Where does one find a TRAINER worthy\n"
	.string "of a legendary tale?$"

Athens_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "What's that?!\n"
	.string "You… You…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} time(s)?!\p"
	.string "That is indeed magnificent!\n"
	.string "It's the birth of a new legend!$"

Athens_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "It gets me thinking, could there be\n"
	.string "other TRAINERS with more impressive\l"
	.string "legends awaiting discovery?$"

Athens_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Are you a TRAINER?\p"
	.string "Then tell me, have you any tales that\n"
	.string "are even remotely legendary?$"

@ Unused
Athens_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Incidentally… Would you care to hear\n"
	.string "another legendary tale?$"

Athens_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "I'm not satisfied…\p"
	.string "I wish you would bring me news worthy\n"
	.string "of being called a legend.$"

Athens_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "I wish more people would be interested\n"
	.string "in hearing my epic tales of legendary\l"
	.string "TRAINERS.$"

Athens_PokemonCenter_1F_Text_SavedGameTitle::
	.string "The Save-Happy TRAINER$"

Athens_PokemonCenter_1F_Text_SavedGameAction::
	.string "Saved the game$"

Athens_PokemonCenter_1F_Text_SavedGameStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER saved the game\n"
	.string "{STR_VAR_1} times!\p"
	.string "A more cautious TRAINER than\n"
	.string "{STR_VAR_3} one will never find!$"

Athens_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "The Trendsetter TRAINER$"

Athens_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "Started trends$"

Athens_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER started new trends\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is setting trends for all\n"
	.string "the HOENN region!$"

Athens_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "The BERRY-Planting TRAINER$"

Athens_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "Planted BERRIES$"

Athens_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER planted BERRIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a legendary lover of\n"
	.string "BERRIES!$"

Athens_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "The BIKE-Loving TRAINER$"

Athens_PokemonCenter_1F_Text_BikeTradesAction::
	.string "Traded BIKES$"

Athens_PokemonCenter_1F_Text_BikeTradesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER swapped BIKES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love BIKES deeply\n"
	.string "and passionately!$"

Athens_PokemonCenter_1F_Text_InterviewsTitle::
	.string "The Interviewed TRAINER$"

Athens_PokemonCenter_1F_Text_InterviewsAction::
	.string "Got interviewed$"

Athens_PokemonCenter_1F_Text_InterviewsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got interviewed\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who's\n"
	.string "attracting much attention!$"

Athens_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "The Battle-Happy TRAINER$"

Athens_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "Battled$"

Athens_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER battled {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who can\n"
	.string "never refuse a chance to battle!$"

Athens_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "The POKéMON-Catching TRAINER$"

Athens_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "Caught POKéMON$"

Athens_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON!\p"
	.string "{STR_VAR_3} is a legendary catcher of\n"
	.string "wild POKéMON!$"

Athens_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "The Fishing TRAINER$"

Athens_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Caught POKéMON with a ROD$"

Athens_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER caught\n"
	.string "{STR_VAR_1} POKéMON while fishing!\p"
	.string "{STR_VAR_3} is a legendary fishing\n"
	.string "expert!$"

Athens_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "The EGG-Warming TRAINER$"

Athens_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "Hatched EGGS$"

Athens_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER hatched {STR_VAR_1} POKéMON\n"
	.string "from EGGS!\p"
	.string "{STR_VAR_3} is a legendary warmer\n"
	.string "of EGGS!$"

Athens_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "The Evolver TRAINER$"

Athens_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "Evolved POKéMON$"

Athens_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {STR_VAR_1} POKéMON\n"
	.string "evolve!\p"
	.string "{STR_VAR_3} is the ultimate evolver\n"
	.string "of POKéMON!$"

Athens_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "The POKéMON CENTER-Loving TRAINER$"

Athens_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "Used POKéMON CENTERS$"

Athens_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at POKéMON CENTERS!\p"
	.string "There could be no greater lover of\n"
	.string "POKéMON CENTERS than {STR_VAR_3}!$"

Athens_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "The Homebody TRAINER$"

Athens_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "Rested POKéMON at home$"

Athens_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER healed POKéMON\n"
	.string "{STR_VAR_1} times at home!\p"
	.string "There could be no more of a homebody\n"
	.string "than {STR_VAR_3}!$"

Athens_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "The SAFARI-Loving TRAINER$"

Athens_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Entered the SAFARI ZONE$"

Athens_PokemonCenter_1F_Text_SafariGamesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER went into the SAFARI ZONE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER whose wild side\n"
	.string "must come out in the SAFARI ZONE!$"

Athens_PokemonCenter_1F_Text_UsedCutTitle::
	.string "The CUT-Frenzy TRAINER$"

Athens_PokemonCenter_1F_Text_UsedCutAction::
	.string "Used CUT$"

Athens_PokemonCenter_1F_Text_UsedCutStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used CUT\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who just must\n"
	.string "love to CUT!$"

Athens_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "The ROCK-SMASHING TRAINER$"

Athens_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "Smashed rocks$"

Athens_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used ROCK SMASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "can't leave a stone unsmashed!$"

Athens_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "The Move-Loving TRAINER$"

Athens_PokemonCenter_1F_Text_MovedBasesAction::
	.string "Moved the SECRET BASE$"

Athens_PokemonCenter_1F_Text_MovedBasesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER moved the SECRET BASE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who loves\n"
	.string "to move houses often!$"

Athens_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "The SPLASH-Happy TRAINER$"

Athens_PokemonCenter_1F_Text_UsedSplashAction::
	.string "Used SPLASH$"

Athens_PokemonCenter_1F_Text_UsedSplashStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used SPLASH\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who must love\n"
	.string "SPLASHING around!$"

Athens_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "The Tenacious TRAINER$"

Athens_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "Resorted to using STRUGGLE$"

Athens_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER had to rely on STRUGGLE\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a tenacious TRAINER\n"
	.string "who never gives in to adversity!$"

Athens_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "The SLOT Champ$"

Athens_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "Won the jackpot on the SLOTS$"

Athens_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won the jackpot on\n"
	.string "the SLOTS {STR_VAR_1} times.\p"
	.string "{STR_VAR_3} is a TRAINER who was lucky\n"
	.string "on the SLOTS!$"

Athens_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "The ROULETTE Champ$"

Athens_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "Had consecutive ROULETTE wins of$"

Athens_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won in ROULETTE\n"
	.string "{STR_VAR_1} times in a row.\p"
	.string "{STR_VAR_3} was lucky when the ball\n"
	.string "bounced in ROULETTE!$"

Athens_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "The BATTLE TOWER Challenger$"

Athens_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "Took the BATTLE TOWER challenge$"

Athens_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER took the BATTLE TOWER\n"
	.string "challenge {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} is a TRAINER who aspires\n"
	.string "for excellence in the BATTLE TOWER!$"

Athens_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "The Blend-Loving TRAINER$"

Athens_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "Made {POKEBLOCK}S$"

Athens_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER made {POKEBLOCK}S\n"
	.string "{STR_VAR_1} times!\p"
	.string "There is none better at using a BERRY\n"
	.string "BLENDER than {STR_VAR_3}!$"

Athens_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "The CONTEST-Loving TRAINER$"

Athens_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "Entered CONTESTS$"

Athens_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER entered CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love showing off\n"
	.string "POKéMON to others!$"

Athens_PokemonCenter_1F_Text_WonContestsTitle::
	.string "The CONTEST Master$"

Athens_PokemonCenter_1F_Text_WonContestsAction::
	.string "Won CONTESTS$"

Athens_PokemonCenter_1F_Text_WonContestsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won CONTESTS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be an incredible\n"
	.string "CONTEST master!$"

Athens_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "The Happy Shopper$"

Athens_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "Shopped$"

Athens_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bought items in shops\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be one of those\n"
	.string "people who are born to shop.$"

Athens_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "The Item-Finding TRAINER$"

Athens_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "Used an ITEMFINDER$"

Athens_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER used an ITEMFINDER\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must enjoy scouring the\n"
	.string "ground for hidden items!$"

Athens_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "The Rain-Soaked TRAINER$"

Athens_PokemonCenter_1F_Text_TimesRainedAction::
	.string "Got rained on$"

Athens_PokemonCenter_1F_Text_TimesRainedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER got soaked by rain\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3}'s charisma must even\n"
	.string "attract rain!$"

Athens_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "The Avid POKéDEX Reader$"

Athens_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "Checked a POKéDEX$"

Athens_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked a POKéDEX\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love inspecting\n"
	.string "POKéMON in a POKéDEX!$"

Athens_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "The RIBBON Collector$"

Athens_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "Received RIBBONS$"

Athens_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER received RIBBONS\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER who\n"
	.string "loves to collect RIBBONS!$"

Athens_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "The Ledge-Jumping TRAINER$"

Athens_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "Jumped down ledges$"

Athens_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER jumped down ledges\n"
	.string "{STR_VAR_1} times!\p"
	.string "If there's a ledge to be jumped,\n"
	.string "{STR_VAR_3} can't ignore it!$"

Athens_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "The Legendary TV Viewer$"

Athens_PokemonCenter_1F_Text_TVWatchedAction::
	.string "Watched TV$"

Athens_PokemonCenter_1F_Text_TVWatchedStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER watched TV\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must love watching TV!$"

Athens_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "The Time-Conscious TRAINER$"

Athens_PokemonCenter_1F_Text_CheckedClockAction::
	.string "Checked the time$"

Athens_PokemonCenter_1F_Text_CheckedClockStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER checked the time\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a punctual TRAINER\n"
	.string "who's conscious of the time.$"

Athens_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "The POKéMON LOTTERY Wizard$"

Athens_PokemonCenter_1F_Text_WonLotteryAction::
	.string "Won POKéMON LOTTERIES$"

Athens_PokemonCenter_1F_Text_WonLotteryStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER won POKéMON LOTTERIES\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must have many friends\n"
	.string "to trade POKéMON with!$"

Athens_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "The DAY CARE-Using Trainer$"

Athens_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "Left POKéMON at the DAY CARE$"

Athens_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER left POKéMON with the\n"
	.string "DAY CARE {STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a real go-getter\n"
	.string "who raises POKéMON aggressively!$"

Athens_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "The CABLE CAR-Loving TRAINER$"

Athens_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "Rode the CABLE CAR$"

Athens_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER rode the CABLE CAR\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a busy TRAINER\n"
	.string "who's up and down all the time!$"

Athens_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "The Hot Spring-Loving TRAINER$"

Athens_PokemonCenter_1F_Text_HotSpringsAction::
	.string "Bathed in hot springs$"

Athens_PokemonCenter_1F_Text_HotSpringsStory::
	.string "This is a tale of a TRAINER\n"
	.string "named {STR_VAR_3}.\p"
	.string "This TRAINER bathed in hot springs\n"
	.string "{STR_VAR_1} times!\p"
	.string "{STR_VAR_3} must be a TRAINER with\n"
	.string "baby-smooth skin!$"


Athens_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox Athens_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, Athens_PokemonCenter_1F_EventScript_KnowNoTales
	message Athens_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, Athens_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, Athens_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto Athens_PokemonCenter_1F_EventScript_TellPlayersTale

Athens_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto Athens_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

Athens_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox Athens_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, Athens_PokemonCenter_1F_EventScript_StorytellerEnd
	goto Athens_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

Athens_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox Athens_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
Athens_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox Athens_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, Athens_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox Athens_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox Athens_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox Athens_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
Athens_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox Athens_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
Athens_PokemonCenter_1F_Text_HearMyStory:
	.string "I'm GIDDY!\n"
	.string "I have a scintillating story for you!\p"
	.string "Would you like to hear my story?$"

Athens_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

Athens_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Also, I was thinking…$"

Athens_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "That's about it, I think…\p"
	.string "We should chat again!\n"
	.string "Bye-bye!$"

Athens_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox Athens_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Athens_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_DeclineGiddy
	end

Athens_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, Athens_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, Athens_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

Athens_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, Athens_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, Athens_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

Athens_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox Athens_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto Athens_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
Athens_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, Athens_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, Athens_PokemonCenter_1F_EventScript_TryTellNewTale
	end

Athens_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox Athens_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox Athens_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

Athens_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Hi, I'm the BARD.\n"
	.string "Would you like to hear my song?$"

Athens_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

Athens_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, what a moving song…\n"
	.string "I wish I could play it for others…$"

Athens_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "So?\n"
	.string "How do you like my song?\p"
	.string "But I'm none too happy about\n"
	.string "the lyrics.\p"
	.string "How would you like to write some\n"
	.string "new lyrics for me?$"

Athens_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"
	.string "You've left me feeling the blues…$"

Athens_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Thank you kindly!\n"
	.string "Let me sing it for you.$"

Athens_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "Was that how you wanted your song\n"
	.string "to go?$"

Athens_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "Okay! That's it, then.\n"
	.string "I'll sing this song for a while.$"

Athens_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Hey, yo! They call me the HIPSTER.\n"
	.string "I'll teach you what's hip and happening.$"

Athens_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "But, hey, I taught you what's hip and\n"
	.string "happening already.\p"
	.string "I'd like to spread the good word to\n"
	.string "other folks.$"

Athens_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "But, hey, you already know a lot about\n"
	.string "what's hip and happening.\p"
	.string "I've got nothing new to teach you!$"

Athens_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Hey, have you heard about\n"
	.string "“{STR_VAR_1}”?\p"
	.string "What's it mean? Well…\n"
	.string "Ask your daddy or mommy, okay?$"
