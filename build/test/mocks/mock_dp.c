#include <string.h>
#include "fff.h"
#include "mock_dp.h"

DEFINE_FAKE_VOID_FUNC0(systemInit);
DEFINE_FAKE_VOID_FUNC0(systemStatePoll);
DEFINE_FAKE_VALUE_FUNC1(sysStates_t, systemStateChange, sysStates_t);
DEFINE_FAKE_VALUE_FUNC1(int8_t, setTriggerLevel, uint16_t);
DEFINE_FAKE_VALUE_FUNC1(int8_t, setQtyAdquisitions, uint16_t);
DEFINE_FAKE_VALUE_FUNC1(int8_t, setQtySamples, uint16_t);

void mock_dp_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(systemInit)
    RESET_FAKE(systemStatePoll)
    RESET_FAKE(systemStateChange)
    RESET_FAKE(setTriggerLevel)
    RESET_FAKE(setQtyAdquisitions)
    RESET_FAKE(setQtySamples)
}
void mock_dp_Verify(void)
{
}
void mock_dp_Destroy(void)
{
}
