/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include "mock_sapi_pwm.h"
#include "mock_sapi_gpio.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_pwmWrite(void);
extern void test_gpioWrite(void);
extern void test_initInicializacion(void);
extern void test_velocPositiva(void);
extern void test_velocNegativa(void);
extern void test_velocBandaPositiva(void);
extern void test_velocBandaNegativa(void);
extern void test_velocUpNew(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_sapi_pwm_Init();
  mock_sapi_gpio_Init();
}
static void CMock_Verify(void)
{
  mock_sapi_pwm_Verify();
  mock_sapi_gpio_Verify();
}
static void CMock_Destroy(void)
{
  mock_sapi_pwm_Destroy();
  mock_sapi_gpio_Destroy();
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_motores.c");
  run_test(test_pwmWrite, "test_pwmWrite", 110);
  run_test(test_gpioWrite, "test_gpioWrite", 125);
  run_test(test_initInicializacion, "test_initInicializacion", 138);
  run_test(test_velocPositiva, "test_velocPositiva", 144);
  run_test(test_velocNegativa, "test_velocNegativa", 157);
  run_test(test_velocBandaPositiva, "test_velocBandaPositiva", 170);
  run_test(test_velocBandaNegativa, "test_velocBandaNegativa", 181);
  run_test(test_velocUpNew, "test_velocUpNew", 193);

  CMock_Guts_MemFreeFinal();
  return UnityEnd();
}

//=======Defintions of FFF variables=====
#include "fff.h"
DEFINE_FFF_GLOBALS;