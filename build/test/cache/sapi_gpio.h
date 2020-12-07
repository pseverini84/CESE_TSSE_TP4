

typedef enum {

      VCC = -2, GND = -1,



      T_FIL1, T_COL2, T_COL0, T_FIL2, T_FIL3, T_FIL0, T_COL1,

      CAN_TD, CAN_RD, RS232_TXD, RS232_RXD,



      GPIO8, GPIO7, GPIO5, GPIO3, GPIO1,

      LCD1, LCD2, LCD3, LCDRS, LCD4,

      SPI_MISO,

      ENET_TXD1, ENET_TXD0, ENET_MDIO, ENET_CRS_DV, ENET_MDC, ENET_TXEN, ENET_RXD1,

      GPIO6, GPIO4, GPIO2, GPIO0,

      LCDEN,

      SPI_MOSI,

      ENET_RXD0,





      TEC1, TEC2, TEC3, TEC4,





      LEDR, LEDG, LEDB, LED1, LED2, LED3,



} gpioMap_t;





typedef enum {

   GPIO_INPUT, GPIO_OUTPUT,

   GPIO_INPUT_PULLUP, GPIO_INPUT_PULLDOWN,

   GPIO_INPUT_PULLUP_PULLDOWN,

   GPIO_ENABLE

} gpioInit_t;









typedef struct {

   int8_t port;

   int8_t pin;

} gpioInitLpc4337_t;



_Bool 

      gpioInit( gpioMap_t pin, gpioInit_t config );



_Bool 

      gpioRead( gpioMap_t pin );



_Bool 

      gpioWrite( gpioMap_t pin, 

                                _Bool 

                                       value );



_Bool 

      gpioToggle( gpioMap_t pin );
