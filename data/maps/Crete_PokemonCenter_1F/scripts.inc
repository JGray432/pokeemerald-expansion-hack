.set LOCALID_NURSE, 1

Crete_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Crete_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Crete_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_CRETE
	call Common_EventScript_UpdateBrineyLocation
	end

Crete_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

Crete_PokemonCenter_1F_EventScript_PokefanF::
	msgbox Crete_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

Crete_PokemonCenter_1F_EventScript_Man::
	msgbox Crete_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

Crete_PokemonCenter_1F_Text_StoneCavern:
	.string "There's a stone cavern at the edge\n"
	.string "of town.\p"
	.string "I've heard you can find rare stones\n"
	.string "there.$"

Crete_PokemonCenter_1F_Text_FaintedMonCanUseHM:
	.string "Even if a POKéMON faints and can't\n"
	.string "battle, it can still use a move learned\l"
	.string "from a HIDDEN MACHINE (HM).$"

