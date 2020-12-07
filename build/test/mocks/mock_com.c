#include <string.h>
#include "fff.h"
#include "mock_com.h"

DEFINE_FAKE_VOID_FUNC1(getLine, char*);
DEFINE_FAKE_VOID_FUNC0(comRxInit);

void mock_com_Init(void)
{
    FFF_RESET_HISTORY();
    RESET_FAKE(getLine)
    RESET_FAKE(comRxInit)
}
void mock_com_Verify(void)
{
}
void mock_com_Destroy(void)
{
}
