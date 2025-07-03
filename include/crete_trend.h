#ifndef GUARD_CRETETREND_H
#define GUARD_CRETETREND_H

void InitCreteTrend(void);
void UpdateCreteTrendPerDay(u16 days);
bool8 TrySetTrendyPhrase(u16 *phrase);
void ReceiveCreteTrendData(struct CreteTrend *linkedTrends, size_t size, u8 unused);


#endif // GUARD_CRETETREND_H
