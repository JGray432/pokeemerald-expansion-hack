.set LOCALID_HERCULES, 3

MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	msgbox MtPyre_6F_Text_OracleFutureBright, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARTEMIS
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_ARTEMIS, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Hercules::
	msgbox MtPyre_6F_Text_HerculesIntro, MSGBOX_DEFAULT
	waitmessage
	msgbox MtPyre_6F_Text_OracleIntro, MSGBOX_DEFAULT
	waitmessage
	msgbox MtPyre_6F_Text_HerculesReply, MSGBOX_DEFAULT
	waitmessage
	msgbox MtPyre_6F_Text_OracleReply, MSGBOX_DEFAULT
	waitmessage
	applymovement LOCALID_HERCULES, MtPyre_6F_Movement_HerculesTurn
	trainerbattle_single TRAINER_HERCULES, MtPyre_6F_Text_HerculesStartBattle, MtPyre_6F_Text_HerculesDefeat
	msgbox MtPyre_6F_Text_HerculesPostBattle, MSGBOX_AUTOCLOSE
	waitmessage
	fadescreenspeed FADE_TO_BLACK, 24
	setvar VAR_PETALBURG_CITY_STATE, 2
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setflag FLAG_EVIL_TEAM01
	removeobject LOCALID_HERCULES
	fadescreenspeed FADE_FROM_BLACK, 24
	msgbox MtPyre_6F_Text_OraclePostHercules, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

MtPyre_6F_Text_HerculesIntro:
	.string "HERCULES: So you're the famous \n"
	.string "Delphi oracle?\p"
	.string "Ha! What a pity you couldn't \n"
	.string "predict me coming here and taking \l"	
	.string "you away - maybe your foresight \l"
	.string "isn't as good as they say.$"

MtPyre_6F_Text_OracleIntro:
	.string "ORACLE: ... My foresight is as \n"
	.string "certain and unwavering as the sun \l"
	.string "rising in the morning.\p"
	.string "I knew you'd come here before even \n"
	.string "you did, Hercules. And no, I don't \l"
	.string "believe I will be coming with you today.\p"
	.string "Thank you for the kind offer, though.$"

MtPyre_6F_Text_HerculesReply:
	.string "HERCULES: Hmph! I respect your \n"
	.string "foolhardy bravado, but your defiance\l"
	.string "is futile. I have a team of loyal \l"
	.string "Argonauts right behind me, you don't\n"
	.string "have the power to stop us!$"

MtPyre_6F_Text_OracleReply:
	.string "ORACLE: Perhaps not, but they do. $"

MtPyre_6F_Movement_HerculesTurn:
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	delay_8
	walk_in_place_faster_right
	delay_8
	step_end

MtPyre_6F_Text_HerculesStartBattle:
	.string "HERCULES: HAHAHAHAHA! \n"
	.string "You truly believe such a puny \l"
	.string "child has a chance against me, \l"
	.string "the mighty Hercules?\p"
	.string "This ought to be fun!$"

MtPyre_6F_Text_HerculesDefeat:
	.string "Were my labours not enough?$"

MtPyre_6F_Text_HerculesPostBattle:
	.string "Grr Jason said this would be an \n"
	.string "easy stunt to pull with both Artemis \l"
	.string "and Apollo distracted. \p"
	.string "{PLAYER}… Where in Tartarus did you\n"
	.string "come from?\p"
	.string "No matter, the rest of the plan will \n"
	.string "continue as before. And if you dare \l"
	.string "cross paths with us again, you will \l"
	.string "find the others less merciful than me.$"

MtPyre_6F_Text_OraclePostHercules:
	.string "ORACLE: Thank you for saving me \n"
	.string "from that brute Hercules. \p"
	.string "Of course I knew I was never really \n"
	.string "in danger teehee. \p"
	.string "I believe Apollo and Artemis have \n"
	.string "returned to their temple now, you \l"
	.string "should seek their blessing as the next \l"
	.string "step in your journey. \p"
	.string "As for those Argonauts... \n"
	.string "I hope you will be equally prepared \l"
	.string "to face them in future. $"

MtPyre_6F_Text_OracleFutureBright:
	.string "ORACLE: Zeus' blood runs strong \n"
	.string "within you {PLAYER}.\p"
	.string "Perhaps some day...$"

MtPyre_6F_Text_ValerieIntro:
	.string "When I'm here…\n"
	.string "A curious power flows into me…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "The power is ebbing away…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Perhaps the power is from the spirits\n"
	.string "of POKéMON in fitful sleep here…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… I lost the match, but…\n"
	.string "I have this little ability…\p"
	.string "Without ever laying my hands on\n"
	.string "your POKéNAV… Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Behind you…\n"
	.string "What is it…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Something faded away…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "The POKéMON at rest here…\n"
	.string "Sometimes, they play…$"

MtPyre_6F_Text_CedricIntro:
	.string "Have you lost your bearings?\n"
	.string "Have no fear for I am here!$"
