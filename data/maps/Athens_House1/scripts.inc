Athens_House1_MapScripts::
	.byte 0

Athens_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Athens_House1_EventScript_ReceivedRockSmash
	msgbox Athens_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM10
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox Athens_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

Athens_House1_EventScript_ReceivedRockSmash::
	msgbox Athens_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

Athens_House1_Text_ImRockSmashDudeTakeThis:
	.string "...\p"
	.string "I sense hidden potential within you.\n"
	.string "Take this.$"

Athens_House1_Text_ExplainRockSmash:
	.string "Unleash your hidden power.$"

Athens_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Oh, yes, if you smash a rock, a POKéMON\n"
	.string "could come flying out of hiding.\p"
	.string "Woohoo!$"

