Crete_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Crete_Gym_OnTransition
	.byte 0

Crete_Gym_OnTransition:
	call Crete_Gym_EventScript_SetFlashLevel
	end

Crete_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, Crete_Gym_EventScript_SetLightsOn
	call Crete_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, Crete_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, Crete_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, Crete_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, Crete_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, Crete_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, Crete_Gym_EventScript_SetFlashLevel2
	goto Crete_Gym_EventScript_SetFlashLevel1

Crete_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
Crete_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

Crete_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

Crete_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

Crete_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

Crete_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

Crete_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
Crete_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

Crete_Gym_EventScript_BrightenRoom::
	call Crete_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, Crete_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, Crete_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, Crete_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, Crete_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, Crete_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, Crete_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, Crete_Gym_EventScript_AnimateFlash6Trainers

Crete_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
Crete_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call Crete_Gym_EventScript_SetFlashLevel
	return

Crete_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call Crete_Gym_EventScript_SetFlashLevel
	return

Crete_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call Crete_Gym_EventScript_SetFlashLevel
	return

Crete_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call Crete_Gym_EventScript_SetFlashLevel
	return

Crete_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call Crete_Gym_EventScript_SetFlashLevel
	return

Crete_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call Crete_Gym_EventScript_SetFlashLevel
	return

Crete_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call Crete_Gym_EventScript_SetFlashLevel
	return

Crete_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, Crete_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
Crete_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, Crete_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
Crete_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, Crete_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
Crete_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, Crete_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
Crete_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, Crete_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
Crete_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, Crete_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
Crete_Gym_EventScript_StopCountingTrainers::
	return

Crete_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, Crete_Gym_Text_BrawlyIntro, Crete_Gym_Text_BrawlyDefeat, Crete_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Crete_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, Crete_Gym_EventScript_GiveBulkUp2
	msgbox Crete_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

Crete_Gym_EventScript_BrawlyDefeated::
	call Crete_Gym_EventScript_AnimateFlashFullBrightness
	message Crete_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox Crete_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_CRETE_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call Crete_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Crete_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

Crete_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox Crete_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

Crete_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox Crete_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

Crete_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, Crete_Gym_Text_BrawlyPreRematch, Crete_Gym_Text_BrawlyRematchDefeat, Crete_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox Crete_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

Crete_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, Crete_Gym_Text_TakaoIntro, Crete_Gym_Text_TakaoDefeat, Crete_Gym_EventScript_TakaoBrightenRoom
	msgbox Crete_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

Crete_Gym_EventScript_TakaoBrightenRoom::
	call Crete_Gym_EventScript_BrightenRoom
	release
	end

Crete_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, Crete_Gym_Text_JocelynIntro, Crete_Gym_Text_JocelynDefeat, Crete_Gym_EventScript_JocelynBrightenRoom
	msgbox Crete_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

Crete_Gym_EventScript_JocelynBrightenRoom::
	call Crete_Gym_EventScript_BrightenRoom
	release
	end

Crete_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, Crete_Gym_Text_LauraIntro, Crete_Gym_Text_LauraDefeat, Crete_Gym_EventScript_LauraBrightenRoom
	msgbox Crete_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

Crete_Gym_EventScript_LauraBrightenRoom::
	call Crete_Gym_EventScript_BrightenRoom
	release
	end

Crete_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, Crete_Gym_Text_BrendenIntro, Crete_Gym_Text_BrendenDefeat, Crete_Gym_EventScript_BrendenBrightenRoom
	msgbox Crete_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

Crete_Gym_EventScript_BrendenBrightenRoom::
	call Crete_Gym_EventScript_BrightenRoom
	release
	end

Crete_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, Crete_Gym_Text_CristianIntro, Crete_Gym_Text_CristianDefeat, Crete_Gym_EventScript_CristianBrightenRoom
	msgbox Crete_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

Crete_Gym_EventScript_CristianBrightenRoom::
	call Crete_Gym_EventScript_BrightenRoom
	release
	end

Crete_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, Crete_Gym_Text_LilithIntro, Crete_Gym_Text_LilithDefeat, Crete_Gym_EventScript_LilithBrightenRoom
	msgbox Crete_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

Crete_Gym_EventScript_LilithBrightenRoom::
	call Crete_Gym_EventScript_BrightenRoom
	release
	end

Crete_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CRETE_GYM, Crete_Gym_EventScript_GymGuidePostVictory
	msgbox Crete_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

Crete_Gym_EventScript_GymGuidePostVictory::
	msgbox Crete_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

Crete_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, Crete_Gym_EventScript_GymStatueCertified
	goto Crete_Gym_EventScript_GymStatue
	end

Crete_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, Crete_Gym_EventScript_GymStatueCertified
	goto Crete_Gym_EventScript_GymStatue
	end

Crete_Gym_EventScript_GymStatueCertified::
	msgbox Crete_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

Crete_Gym_EventScript_GymStatue::
	msgbox Crete_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

Crete_Gym_Text_GymGuideAdvice:
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

Crete_Gym_Text_GymGuidePostVictory:
	.string "Whoah! It's turned too bright in here!\p"
	.string "Your future is bright, too!$"

Crete_Gym_Text_TakaoIntro:
	.string "Might is right!\n"
	.string "Come on!$"

Crete_Gym_Text_TakaoDefeat:
	.string "Not enough power…$"

Crete_Gym_Text_TakaoPostBattle:
	.string "Your skill overcame my strength!\n"
	.string "Your technique is commendable!$"

Crete_Gym_Text_JocelynIntro:
	.string "There's no need for BRAWLY to be\n"
	.string "involved!\p"
	.string "I'll crush you!$"

Crete_Gym_Text_JocelynDefeat:
	.string "But… How?\n"
	.string "How could I lose so easily?$"

Crete_Gym_Text_JocelynPostBattle:
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a GYM LEADER…\p"
	.string "No, I'll become the POKéMON LEAGUE\n"
	.string "CHAMPION!$"

Crete_Gym_Text_LauraIntro:
	.string "Don't you dare brush me off!\n"
	.string "It's not my fault if you cry!$"

Crete_Gym_Text_LauraDefeat:
	.string "Waaaaaaah!\n"
	.string "I lost!$"

Crete_Gym_Text_LauraPostBattle:
	.string "I battle in the dark to make my heart\n"
	.string "stronger.\p"
	.string "But because it's so dark, I can never\n"
	.string "see BRAWLY's face…$"

Crete_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Are you stumbling around in the dark?$"

Crete_Gym_Text_LilithDefeat:
	.string "Oh, you…\n"
	.string "I don't want to know you!$"

Crete_Gym_Text_LilithPostBattle:
	.string "You deserve to stay lost and end up\n"
	.string "back at the entrance again!$"

Crete_Gym_Text_BrendenIntro:
	.string "I'll show you the gumption of\n"
	.string "a sailing man!$"

Crete_Gym_Text_BrendenDefeat:
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"

Crete_Gym_Text_BrendenPostBattle:
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our GYM LEADER.$"

Crete_Gym_Text_CristianIntro:
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"

Crete_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"

Crete_Gym_Text_CristianPostBattle:
	.string "You win!\n"
	.string "Go after that BADGE!$"

Crete_Gym_Text_BrawlyIntro:
	.string "I'm BRAWLY!\n"
	.string "CRETE's GYM LEADER!\p"
	.string "I've been churned in the rough waves\n"
	.string "of these parts, and I've grown tough\l"
	.string "in the pitch-black cave!\p"
	.string "So you wanted to challenge me?\n"
	.string "Let me see what you're made of!$"

Crete_Gym_Text_BrawlyDefeat:
	.string "Whoah, wow! You made a much bigger\n"
	.string "splash than I expected!\p"
	.string "You swamped me!\p"
	.string "Okay, you've got me.\n"
	.string "Take this GYM BADGE!$"

Crete_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} received the KNUCKLE BADGE\n"
	.string "from BRAWLY.$"

Crete_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "The KNUCKLE BADGE makes all POKéMON\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "FLASH outside of battle.\p"
	.string "If you'd like, use this TECHNICAL\n"
	.string "MACHINE, too.$"

Crete_Gym_Text_ExplainBulkUp:
	.string "That TM08 contains BULK UP.\p"
	.string "It's a move that raises both ATTACK\n"
	.string "and DEFENSE stats.\p"
	.string "… … … … … …$"

Crete_Gym_Text_RegisteredBrawly:
	.string "Registered GYM LEADER BRAWLY\n"
	.string "in the POKéNAV.$"

Crete_Gym_Text_BrawlyPostBattle:
	.string "I can see your talent becoming a giant\n"
	.string "wave to cause a storm of astonishment\l"
	.string "among TRAINERS one day!$"

Crete_Gym_Text_GymStatue:
	.string "CRETE POKéMON GYM$"

Crete_Gym_Text_GymStatueCertified:
	.string "CRETE POKéMON GYM\p"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

Crete_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Show me how much higher\n"
	.string "you've gone!$"

Crete_Gym_Text_BrawlyRematchDefeat:
	.string "Wow!\n"
	.string "Swamped again!$"

Crete_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: Battling is vast and it's deep.\n"
	.string "You can't see the bottom.\l"
	.string "It's just like the sea of HOENN!$"

Crete_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Oh? You only have one POKéMON\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
	.string "with at least two POKéMON.$"
