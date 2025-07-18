.set LOCALID_NURSE, 1

Athens_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Athens_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Athens_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_ATHENS
	call Common_EventScript_UpdateBrineyLocation
	goto Athens_PokemonCenter_1F_EventScript_SetAthensOldManGfx
	end

Athens_PokemonCenter_1F_EventScript_SetAthensOldManGfx::
	special SetAthensOldManObjEventGfx
	end

Athens_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Athens_PokemonCenter_1F_EventScript_Woman1::
	msgbox Athens_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

Athens_PokemonCenter_1F_EventScript_Woman2::
	msgbox Athens_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

Athens_PokemonCenter_1F_EventScript_Youngster::
	msgbox Athens_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

Athens_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "That man over there, he says weird\n"
	.string "things!\p"
	.string "He's funny in a weird way.\n"
	.string "I doubt I'll forget about him!$"

Athens_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "When I accessed the RECORD CORNER,\n"
	.string "the data for what's hot in CRETE\l"
	.string "got updated.\p"
	.string "Now that bit of data is the same\n"
	.string "as my friend's!$"

Athens_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "A RECORD CORNER opened upstairs in\n"
	.string "the POKéMON CENTER.\p"
	.string "I don't know what it's about, but it\n"
	.string "sounds fun. I'll go check it out!$"

