#include "build/temp/_test_motores.c"
#include "build/test/mocks/mock_sapi_gpio.h"
#include "build/test/mocks/mock_sapi_pwm.h"
#include "src/motores.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




uint16_t ledsVirtuales;

gpioMap_t pinesVirtuales[]={0,0,T_COL0,T_FIL2,T_FIL3,0,T_COL1};

pwmMap_t pwmVirtual[]={MOT_DER,MOT_IZQ};

char mensaje[32];





typedef struct{

    pwmMap_t motor;

    gpioMap_t enable1;

    gpioMap_t enable2;

} ejemplo_t;



ejemplo_t EJEMPLOS[]={

    {.motor=MOT_DER,.enable1=T_COL0,.enable2=T_FIL2},

    {.motor=MOT_IZQ,.enable1=T_FIL3,.enable2=T_COL1}

    };

















_Bool 

      aux_pwmWrite( pwmMap_t pwmNumber, uint8_t percent ){

    switch (pwmNumber) {

        case MOT_DER:

            pwmVirtual[MOT_DER]=percent;

            break;

        case MOT_IZQ:

            pwmVirtual[MOT_IZQ]=percent;

            break;

        default:

            return 

                  0

                       ;

    }

    return 

          1

              ;

}



_Bool 

      aux_gpioWrite( gpioMap_t pin, 

                                    _Bool 

                                           value ){

    switch (pin) {

        case T_COL0:

            pinesVirtuales[T_COL0]=value;

            break;

        case T_FIL2:

            pinesVirtuales[T_FIL2]=value;

            break;

        case T_FIL3:

            pinesVirtuales[T_FIL3]=value;

            break;

        case T_COL1:

            pinesVirtuales[T_COL1]=value;

            break;

        default:

            return 

                  0

                       ;

    }

    return 

          1

              ;

};









_Bool 

    error_informado=

                    0

                         ;



void RegistrarError(void) {

    error_informado=

                   1

                       ;

}





void setUp(void) {

     error_informado=

                    0

                         ;



    pwmWrite_fake.custom_fake=aux_pwmWrite;

    gpioWrite_fake.custom_fake=aux_gpioWrite;

    motor_init();

}



void tearDown(void) {



}









void test_pwmWrite(void){

    for(int i=0;i<sizeof(EJEMPLOS)/sizeof(ejemplo_t);i++){

        ejemplo_t * ejemplo=&EJEMPLOS[i];

        sprintf(mensaje,"Ejemplo %d", i);



        pwmVirtual[ejemplo->motor]=200;



        do {if ((pwmWrite( ejemplo->motor ,0 ))) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(117)));}} while(0);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT32)((0)), (UNITY_INT)(UNITY_INT32)((pwmVirtual[ejemplo->motor])), ((mensaje)), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_HEX32);

    }



}







void test_gpioWrite(void){

    for(int i=0;i<sizeof(EJEMPLOS)/sizeof(ejemplo_t);i++){

        ejemplo_t * ejemplo=&EJEMPLOS[i];

        sprintf(mensaje,"Ejemplo %d", i);



        pinesVirtuales[ejemplo->enable2]=

                                        0

                                             ;



        do {if ((gpioWrite( ejemplo->enable2,1 ))) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(132)));}} while(0);

        UnityAssertEqualNumber((UNITY_INT)((

       1

       )), (UNITY_INT)((pinesVirtuales[ejemplo->enable2])), ((mensaje)), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_INT);

    }

}





void test_initInicializacion(void){



    do {if ((motor_init())) {} else {UnityFail( ((("Init Motores anda"))), (UNITY_UINT)((UNITY_UINT)(140)));}} while(0);

}





void test_velocPositiva(void){

    for(int i=0;i<sizeof(EJEMPLOS)/sizeof(ejemplo_t);i++){

        ejemplo_t * ejemplo=&EJEMPLOS[i];

        sprintf(mensaje,"Ejemplo %d", i);



        do {if ((motorSpeed( 200, ejemplo->motor))) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(149)));}} while(0);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((200)), (UNITY_INT)(UNITY_INT8 )((pwmVirtual[ejemplo->motor])), ((mensaje)), (UNITY_UINT)(150), UNITY_DISPLAY_STYLE_HEX8);

        do {if ((pinesVirtuales[ejemplo->enable1])) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(151)));}} while(0);

        do {if (!(pinesVirtuales[ejemplo->enable2])) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(152)));}} while(0);

    }

}





void test_velocNegativa(void){

    for(int i=0;i<sizeof(EJEMPLOS)/sizeof(ejemplo_t);i++){

        ejemplo_t * ejemplo=&EJEMPLOS[i];

        sprintf(mensaje,"Ejemplo %d", i);



        do {if ((motorSpeed( -200, ejemplo->motor))) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(162)));}} while(0);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((200)), (UNITY_INT)(UNITY_INT8 )((pwmVirtual[ejemplo->motor])), ((mensaje)), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_HEX8);

        do {if (!(pinesVirtuales[ejemplo->enable1])) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(164)));}} while(0);

        do {if ((pinesVirtuales[ejemplo->enable2])) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(165)));}} while(0);

    }

}





void test_velocBandaPositiva(void){

    for(int i=0;i<sizeof(EJEMPLOS)/sizeof(ejemplo_t);i++){

        ejemplo_t * ejemplo=&EJEMPLOS[i];

        sprintf(mensaje,"Ejemplo %d", i);



        do {if ((motorSpeed( 50, ejemplo->motor))) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(175)));}} while(0);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((pwmVirtual[ejemplo->motor])), ((mensaje)), (UNITY_UINT)(176), UNITY_DISPLAY_STYLE_HEX8);

    }

}





void test_velocBandaNegativa(void){

    for(int i=0;i<sizeof(EJEMPLOS)/sizeof(ejemplo_t);i++){

        ejemplo_t * ejemplo=&EJEMPLOS[i];

        sprintf(mensaje,"Ejemplo %d", i);



        do {if ((motorSpeed( -50, ejemplo->motor))) {} else {UnityFail( (((mensaje))), (UNITY_UINT)((UNITY_UINT)(186)));}} while(0);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((0)), (UNITY_INT)(UNITY_INT8 )((pwmVirtual[ejemplo->motor])), ((mensaje)), (UNITY_UINT)(187), UNITY_DISPLAY_STYLE_HEX8);

    }

}







void test_velocUpNew(void){

    motorSpeedMax(195);

    for(int i=0;i<sizeof(EJEMPLOS)/sizeof(ejemplo_t);i++){

        ejemplo_t * ejemplo=&EJEMPLOS[i];

        sprintf(mensaje,"Ejemplo %d", i);



        motorSpeed( -200, ejemplo->motor);

        UnityAssertEqualNumber((UNITY_INT)(UNITY_INT8 )((195)), (UNITY_INT)(UNITY_INT8 )((pwmVirtual[ejemplo->motor])), ((mensaje)), (UNITY_UINT)(200), UNITY_DISPLAY_STYLE_HEX8);

    }

}
