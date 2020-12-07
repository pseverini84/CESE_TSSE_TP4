#include "unity.h"
#include "shell.h"
#include "string.h"

#include "mock_com.h"
#include "mock_dp.h"


char miUartRxMock[100];
uint16_t miUmbral;
uint16_t miQtyAdquisiciones;
uint16_t miQtyMuestras;
sysStates_t miEstado;

//======================== Funciones Internas ======================================
sysStates_t aux_systemStateChange(sysStates_t newState)
{
    miEstado=newState;
}

void aux_getLine(char *ptr)
{
    strcpy(ptr,miUartRxMock);
}

int8_t aux_setTriggerLevel(uint16_t parameter)
{
    miUmbral=parameter;
}

int8_t aux_setQtyAdquisitions(uint16_t parameter)
{
    miQtyAdquisiciones=parameter;
}

int8_t aux_setQtySamples(uint16_t parameter)
{
    miQtyMuestras=parameter;
}


//========================== Funciones del software de testeo =====================
void setUp(void){
    getLine_fake.custom_fake=aux_getLine;
    setTriggerLevel_fake.custom_fake=aux_setTriggerLevel;
    setQtyAdquisitions_fake.custom_fake=aux_setQtyAdquisitions;
    setQtySamples_fake.custom_fake=aux_setQtySamples;
    systemStateChange_fake.custom_fake=aux_systemStateChange;
    
    strcpy(miUartRxMock,"");

    miUmbral=10;
    miQtyAdquisiciones=10;
    miQtyMuestras=10;
    miEstado=sysInit;
}

void tearDown(void){
}

//======================================== Testeos ==================================
void test_no_se_recibio_nada(void){
    TEST_ASSERT_EQUAL_HEX16(0,taskShell());
}

void test_se_recibio_un_comando_valido(void){
    strcpy(miUartRxMock,"mode -a\r\n");
    TEST_ASSERT_EQUAL_HEX16(1,taskShell());
}

void test_se_recibio_un_comando_no_valido(void){
    strcpy(miUartRxMock,"mode -l\r\n");
    TEST_ASSERT_EQUAL_HEX16(0,taskShell());
}

void test_se_recibio_un_nivel_de_ubral_valido(void){
    strcpy(miUartRxMock,"conf -t 350\r\n");
    taskShell();
    TEST_ASSERT_EQUAL_HEX16(350,miUmbral);
}

void test_se_recibio_un_nivel_de_ubral_invalido(void){
    strcpy(miUartRxMock,"conf -t 1001\r\n");
    taskShell();
    TEST_ASSERT_EQUAL_HEX16(10,miUmbral);
}

void test_se_recibio_una_cantidad_de_adquisiciones_valida(void){
    strcpy(miUartRxMock,"conf -q 15\r\n");
    taskShell();
    TEST_ASSERT_EQUAL_HEX16(15,miQtyAdquisiciones);
}

void test_se_recibio_una_cantidad_de_adquisiciones_invalidas(void){
    strcpy(miUartRxMock,"conf -q 2000\r\n");
    taskShell();
    TEST_ASSERT_EQUAL_HEX16(10,miQtyAdquisiciones);
}

void test_se_recibio_una_cantidad_de_muestras_valida(void){
    strcpy(miUartRxMock,"conf -s 1200\r\n");
    taskShell();
    TEST_ASSERT_EQUAL_HEX16(1200,miQtyMuestras);
}

void test_se_recibio_una_cantidad_de_muestras_invalidas(void){
    strcpy(miUartRxMock,"conf -s 2000\r\n");
    taskShell();
    TEST_ASSERT_EQUAL_HEX16(10,miQtyMuestras);
}

void test_se_armo_el_sistema(void){
    strcpy(miUartRxMock,"mode -a\r\n");
    taskShell();
    TEST_ASSERT_EQUAL_HEX16(sysArmed,miEstado);
}

void test_se_desarmo_el_sistema(void){
    strcpy(miUartRxMock,"mode -d\r\n");
    taskShell();
    TEST_ASSERT_EQUAL_HEX16(sysDisarmed,miEstado);
}

void test_se_recibio_un_estado_incorrecto(void){
    strcpy(miUartRxMock,"mode -l\r\n");
    taskShell();
    TEST_ASSERT_EQUAL_HEX16(sysInit,miEstado);
}

