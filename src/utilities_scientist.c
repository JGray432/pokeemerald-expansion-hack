#include "global.h"
#include "battle.h"
#include "battle_ai_main.h"
#include "battle_ai_util.h"
#include "constants/battle_ai.h"
#include "battle_arena.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_tv.h"
#include "battle_z_move.h"
#include "bg.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "item.h"
#include "link.h"
#include "main.h"
#include "m4a.h"
#include "palette.h"
#include "pokeball.h"
#include "pokemon.h"
#include "random.h"
#include "reshow_battle_screen.h"
#include "script_menu.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"
#include "constants/battle_anim.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/trainers.h"
#include "trainer_hill.h"
#include "test_runner.h"
#include "party_menu.h"
#include "utilities_scientist.h"

void ApplyStatusConditionToPartyMon(void)
{
    u16 chosenStatus = VarGet(VAR_RESULT);
    struct Pokemon *mon = &gPlayerParty[gSpecialVar_0x8004];
    u32 status = 0;
    switch (chosenStatus) {
        case 1: status = STATUS1_POISON; break;
        case 2: status = STATUS1_PARALYSIS; break;
        case 3: status = STATUS1_BURN; break;
        case 4: status = STATUS1_FREEZE; break;
        case 5: status = STATUS1_SLEEP; break;
    }
    SetMonData(mon, MON_DATA_STATUS, &status);
}

void MaximizeIVOfChosenMon(void)
{
    u8 statId = VarGet(VAR_RESULT); // 0 = HP, 1 = Atk, ...
    u8 monId = GetCursorSelectionMonId();
    struct Pokemon *mon = &gPlayerParty[monId];

    u8 maxIV = 31;
    SetMonData(mon, MON_DATA_HP_IV + statId, &maxIV);
}