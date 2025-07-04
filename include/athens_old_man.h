#ifndef GUARD_ATHENS_OLD_MAN_H
#define GUARD_ATHENS_OLD_MAN_H

extern struct BardSong gBardSong;

void SetAthensOldMan(void);
u8 GetCurrentAthensOldMan(void);
void SetAthensOldManObjEventGfx(void);
void SanitizeAthensOldManForRuby(OldMan *dest);
void SanitizeReceivedRubyOldMan(union OldMan * oldMan, u32 version, u32 language);
void SanitizeReceivedEmeraldOldMan(union OldMan * oldMan, u32 version, u32 language);
void ResetAthensOldManFlag(void);

#endif // GUARD_ATHENS_OLD_MAN_H
