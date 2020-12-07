#ifndef mock_com_H
#define mock_com_H

#include "fff.h"
#include "fff_unity_helper.h"
#include "com.h"


DECLARE_FAKE_VOID_FUNC1(getLine, char*);
DECLARE_FAKE_VOID_FUNC0(comRxInit);

void mock_com_Init(void);
void mock_com_Verify(void);
void mock_com_Destroy(void);

#endif // mock_com_H
