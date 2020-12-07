#include "build/temp/_test_shell.c"
#include "build/test/mocks/mock_dp.h"
#include "build/test/mocks/mock_com.h"
#include "src/shell.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"






char miUartRxMock[100];

uint16_t miUmbral;

uint16_t miQtyAdquisiciones;

uint16_t miQtyMuestras;

sysStates_t miEstado;





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





void test_no_se_recibio_nada(void){

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((taskShell())), (

   ((void *)0)

   ), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_recibio_un_comando_valido(void){

    strcpy(miUartRxMock,"mode -a\r\n");

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((taskShell())), (

   ((void *)0)

   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_recibio_un_comando_no_valido(void){

    strcpy(miUartRxMock,"mode -l\r\n");

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((taskShell())), (

   ((void *)0)

   ), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_recibio_un_nivel_de_ubral_valido(void){

    strcpy(miUartRxMock,"conf -t 350\r\n");

    taskShell();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((350)), (UNITY_INT)(UNITY_INT16)((miUmbral)), (

   ((void *)0)

   ), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_recibio_un_nivel_de_ubral_invalido(void){

    strcpy(miUartRxMock,"conf -t 1001\r\n");

    taskShell();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((10)), (UNITY_INT)(UNITY_INT16)((miUmbral)), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_recibio_una_cantidad_de_adquisiciones_valida(void){

    strcpy(miUartRxMock,"conf -q 15\r\n");

    taskShell();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((15)), (UNITY_INT)(UNITY_INT16)((miQtyAdquisiciones)), (

   ((void *)0)

   ), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_recibio_una_cantidad_de_adquisiciones_invalidas(void){

    strcpy(miUartRxMock,"conf -q 2000\r\n");

    taskShell();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((10)), (UNITY_INT)(UNITY_INT16)((miQtyAdquisiciones)), (

   ((void *)0)

   ), (UNITY_UINT)(97), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_recibio_una_cantidad_de_muestras_valida(void){

    strcpy(miUartRxMock,"conf -s 1200\r\n");

    taskShell();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1200)), (UNITY_INT)(UNITY_INT16)((miQtyMuestras)), (

   ((void *)0)

   ), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_recibio_una_cantidad_de_muestras_invalidas(void){

    strcpy(miUartRxMock,"conf -s 2000\r\n");

    taskShell();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((10)), (UNITY_INT)(UNITY_INT16)((miQtyMuestras)), (

   ((void *)0)

   ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_armo_el_sistema(void){

    strcpy(miUartRxMock,"mode -a\r\n");

    taskShell();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((sysArmed)), (UNITY_INT)(UNITY_INT16)((miEstado)), (

   ((void *)0)

   ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_desarmo_el_sistema(void){

    strcpy(miUartRxMock,"mode -d\r\n");

    taskShell();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((sysDisarmed)), (UNITY_INT)(UNITY_INT16)((miEstado)), (

   ((void *)0)

   ), (UNITY_UINT)(121), UNITY_DISPLAY_STYLE_HEX16);

}



void test_se_recibio_un_estado_incorrecto(void){

    strcpy(miUartRxMock,"mode -l\r\n");

    taskShell();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((sysInit)), (UNITY_INT)(UNITY_INT16)((miEstado)), (

   ((void *)0)

   ), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_HEX16);

}
