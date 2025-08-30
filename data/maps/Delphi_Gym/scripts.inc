Delphi_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Delphi_Gym_OnTransition
	.byte 0

Delphi_Gym_OnTransition:
	call Delphi_Gym_EventScript_SetFlashLevel
	end

Delphi_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, Delphi_Gym_EventScript_SetLightsOn
	call Delphi_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, Delphi_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, Delphi_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, Delphi_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, Delphi_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, Delphi_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, Delphi_Gym_EventScript_SetFlashLevel2
	goto Delphi_Gym_EventScript_SetFlashLevel1

Delphi_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
Delphi_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

Delphi_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

Delphi_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

Delphi_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

Delphi_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

Delphi_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
Delphi_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

Delphi_Gym_EventScript_BrightenRoom::
	call Delphi_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, Delphi_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, Delphi_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, Delphi_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, Delphi_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, Delphi_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, Delphi_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, Delphi_Gym_EventScript_AnimateFlash6Trainers

Delphi_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
Delphi_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call Delphi_Gym_EventScript_SetFlashLevel
	return

Delphi_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call Delphi_Gym_EventScript_SetFlashLevel
	return

Delphi_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call Delphi_Gym_EventScript_SetFlashLevel
	return

Delphi_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call Delphi_Gym_EventScript_SetFlashLevel
	return

Delphi_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call Delphi_Gym_EventScript_SetFlashLevel
	return

Delphi_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call Delphi_Gym_EventScript_SetFlashLevel
	return

Delphi_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call Delphi_Gym_EventScript_SetFlashLevel
	return

Delphi_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, Delphi_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
Delphi_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, Delphi_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
Delphi_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, Delphi_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
Delphi_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, Delphi_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
Delphi_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, Delphi_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
Delphi_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, Delphi_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
Delphi_Gym_EventScript_StopCountingTrainers::
	return

Delphi_Gym_EventScript_Brawly::
	trainerbattle_double TRAINER_APOLLO_AND_ARTEMIS, Delphi_Gym_Text_ApolloArtemisIntro, Delphi_Gym_Text_BrawlyDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, Delphi_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Delphi_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, Delphi_Gym_EventScript_GiveBulkUp2
	msgbox Delphi_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

Delphi_Gym_EventScript_BrawlyDefeated::
	call Delphi_Gym_EventScript_AnimateFlashFullBrightness
	message Delphi_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox Delphi_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DELPHI_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_Limani_GYM_STATE, 1
	call_if_eq VAR_Limani_GYM_STATE, 6, Common_EventScript_ReadyLimaniGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call Delphi_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Delphi_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

Delphi_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox Delphi_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

Delphi_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox Delphi_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

Delphi_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, Delphi_Gym_Text_BrawlyPreRematch, Delphi_Gym_Text_BrawlyRematchDefeat, Delphi_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox Delphi_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

Delphi_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, Delphi_Gym_Text_TakaoIntro, Delphi_Gym_Text_TakaoDefeat, Delphi_Gym_EventScript_TakaoBrightenRoom
	msgbox Delphi_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

Delphi_Gym_EventScript_TakaoBrightenRoom::
	call Delphi_Gym_EventScript_BrightenRoom
	release
	end

Delphi_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, Delphi_Gym_Text_JocelynIntro, Delphi_Gym_Text_JocelynDefeat, Delphi_Gym_EventScript_JocelynBrightenRoom
	msgbox Delphi_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

Delphi_Gym_EventScript_JocelynBrightenRoom::
	call Delphi_Gym_EventScript_BrightenRoom
	release
	end

Delphi_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, Delphi_Gym_Text_LauraIntro, Delphi_Gym_Text_LauraDefeat, Delphi_Gym_EventScript_LauraBrightenRoom
	msgbox Delphi_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

Delphi_Gym_EventScript_LauraBrightenRoom::
	call Delphi_Gym_EventScript_BrightenRoom
	release
	end

Delphi_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, Delphi_Gym_Text_BrendenIntro, Delphi_Gym_Text_BrendenDefeat, Delphi_Gym_EventScript_BrendenBrightenRoom
	msgbox Delphi_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

Delphi_Gym_EventScript_BrendenBrightenRoom::
	call Delphi_Gym_EventScript_BrightenRoom
	release
	end

Delphi_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, Delphi_Gym_Text_CristianIntro, Delphi_Gym_Text_CristianDefeat, Delphi_Gym_EventScript_CristianBrightenRoom
	msgbox Delphi_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

Delphi_Gym_EventScript_CristianBrightenRoom::
	call Delphi_Gym_EventScript_BrightenRoom
	release
	end

Delphi_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, Delphi_Gym_Text_LilithIntro, Delphi_Gym_Text_LilithDefeat, Delphi_Gym_EventScript_LilithBrightenRoom
	msgbox Delphi_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

Delphi_Gym_EventScript_LilithBrightenRoom::
	call Delphi_Gym_EventScript_BrightenRoom
	release
	end

Delphi_Gym_EventScript_Margot::
	trainerbattle_single TRAINER_MARGOT, Delphi_Gym_Text_LilithIntro, Delphi_Gym_Text_LilithDefeat
	msgbox Delphi_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

Delphi_Gym_EventScript_Holly::
	trainerbattle_single TRAINER_HOLLY, Delphi_Gym_Text_LilithIntro, Delphi_Gym_Text_LilithDefeat
	msgbox Delphi_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

Delphi_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DELPHI_GYM, Delphi_Gym_EventScript_GymGuidePostVictory
	msgbox Delphi_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

Delphi_Gym_EventScript_GymGuidePostVictory::
	msgbox Delphi_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

Delphi_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, Delphi_Gym_EventScript_GymStatueCertified
	goto Delphi_Gym_EventScript_GymStatue
	end

Delphi_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, Delphi_Gym_EventScript_GymStatueCertified
	goto Delphi_Gym_EventScript_GymStatue
	end

Delphi_Gym_EventScript_GymStatueCertified::
	msgbox Delphi_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

Delphi_Gym_EventScript_GymStatue::
	msgbox Delphi_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

Delphi_Gym_Text_GymGuideAdvice:
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "CRETE's GYM LEADER BRAWLY commands\n"
	.string "FIGHTING-type POKéMON.\p"
	.string "Going against him with NORMAL-type\n"
	.string "POKéMON is asking for trouble.\p"
	.string "FIGHTING POKéMON will lay a serious\n"
	.string "smack down on NORMAL POKéMON,\l"
	.string "so be careful!\p"
	.string "What's worse, the GYM is as dark as\n"
	.string "the ocean floor.\p"
	.string "But it will get brighter after defeating\n"
	.string "the TRAINERS in your way.\p"
	.string "Hey, okay, go for it!$"

Delphi_Gym_Text_GymGuidePostVictory:
	.string "Whoah! It's turned too bright in here!\p"
	.string "Your future is bright, too!$"

Delphi_Gym_Text_TakaoIntro:
	.string "Might is right!\n"
	.string "Come on!$"

Delphi_Gym_Text_TakaoDefeat:
	.string "Not enough power…$"

Delphi_Gym_Text_TakaoPostBattle:
	.string "Your skill overcame my strength!\n"
	.string "Your technique is commendable!$"

Delphi_Gym_Text_JocelynIntro:
	.string "There's no need for BRAWLY to be\n"
	.string "involved!\p"
	.string "I'll crush you!$"

Delphi_Gym_Text_JocelynDefeat:
	.string "But… How?\n"
	.string "How could I lose so easily?$"

Delphi_Gym_Text_JocelynPostBattle:
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a GYM LEADER…\p"
	.string "No, I'll become the POKéMON LEAGUE\n"
	.string "CHAMPION!$"

Delphi_Gym_Text_LauraIntro:
	.string "Don't you dare brush me off!\n"
	.string "It's not my fault if you cry!$"

Delphi_Gym_Text_LauraDefeat:
	.string "Waaaaaaah!\n"
	.string "I lost!$"

Delphi_Gym_Text_LauraPostBattle:
	.string "I battle in the dark to make my heart\n"
	.string "stronger.\p"
	.string "But because it's so dark, I can never\n"
	.string "see BRAWLY's face…$"

Delphi_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Are you stumbling around in the dark?$"

Delphi_Gym_Text_LilithDefeat:
	.string "Oh, you…\n"
	.string "I don't want to know you!$"

Delphi_Gym_Text_LilithPostBattle:
	.string "You deserve to stay lost and end up\n"
	.string "back at the entrance again!$"

Delphi_Gym_Text_BrendenIntro:
	.string "I'll show you the gumption of\n"
	.string "a sailing man!$"

Delphi_Gym_Text_BrendenDefeat:
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"

Delphi_Gym_Text_BrendenPostBattle:
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our GYM LEADER.$"

Delphi_Gym_Text_CristianIntro:
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"

Delphi_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"

Delphi_Gym_Text_CristianPostBattle:
	.string "You win!\n"
	.string "Go after that BADGE!$"

Delphi_Gym_Text_ApolloArtemisIntro:
	.string "I'm APOLLO. \p"
	.string "I'm ARTEMIS. \p"
	.string "APOLLO: The oracle told us how you \n"
	.string "rescued her, you have our thanks. \p"
	.string "ARTEMIS: And apologies we weren't \n"
	.string "there to help. We never expected such \l"
	.string "a rash attack from HERCULES. \p"

	.string "APOLLO: We will make sure HERCULES \n"
	.string "pays for this insult. \p"
	.string "ARTEMIS: But first, we must test your \n"
	.string "strength. \p"
	.string "APOLLO: We will not go easy on you!$"

Delphi_Gym_Text_BrawlyDefeat:
	.string "Whoah, wow! You made a much bigger\n"
	.string "splash than I expected!\p"
	.string "You swamped me!\p"
	.string "Okay, you've got me.\n"
	.string "Take this GYM BADGE!$"

Delphi_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} received the KNUCKLE BADGE\n"
	.string "from BRAWLY.$"

Delphi_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "The KNUCKLE BADGE makes all POKéMON\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "FLASH outside of battle.\p"
	.string "If you'd like, use this TECHNICAL\n"
	.string "MACHINE, too.$"

Delphi_Gym_Text_ExplainBulkUp:
	.string "That TM08 contains BULK UP.\p"
	.string "It's a move that raises both ATTACK\n"
	.string "and DEFENSE stats.\p"
	.string "… … … … … …$"

Delphi_Gym_Text_RegisteredBrawly:
	.string "Registered GYM LEADER BRAWLY\n"
	.string "in the POKéNAV.$"

Delphi_Gym_Text_BrawlyPostBattle:
	.string "I can see your talent becoming a giant\n"
	.string "wave to cause a storm of astonishment\l"
	.string "among TRAINERS one day!$"

Delphi_Gym_Text_GymStatue:
	.string "CRETE POKéMON GYM$"

Delphi_Gym_Text_GymStatueCertified:
	.string "CRETE POKéMON GYM\p"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

Delphi_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Show me how much higher\n"
	.string "you've gone!$"

Delphi_Gym_Text_BrawlyRematchDefeat:
	.string "Wow!\n"
	.string "Swamped again!$"

Delphi_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: Battling is vast and it's deep.\n"
	.string "You can't see the bottom.\l"
	.string "It's just like the sea of HOENN!$"

Delphi_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Oh? You only have one POKéMON\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
	.string "with at least two POKéMON.$"
