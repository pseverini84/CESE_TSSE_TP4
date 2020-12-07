#ifndef mock_dp_H
#define mock_dp_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "dp.h"


DECLARE_FAKE_VOID_FUNC0(systemInit);
DECLARE_FAKE_VOID_FUNC0(systemStatePoll);
DECLARE_FAKE_VALUE_FUNC1(sysStates_t, systemStateChange, sysStates_t);
DECLARE_FAKE_VALUE_FUNC1(int8_t, setTriggerLevel, uint16_t);
DECLARE_FAKE_VALUE_FUNC1(int8_t, setQtyAdquisitions, uint16_t);
DECLARE_FAKE_VALUE_FUNC1(int8_t, setQtySamples, uint16_t);

void mock_dp_Init(void);
void mock_dp_Verify(void);
void mock_dp_Destroy(void);

#endif // mock_dp_H
