



typedef enum{

 sysInit,

 sysReady,

 sysArmed,

 sysDisarmed,

   sysError,

}sysStates_t;



void systemInit(void);

void systemStatePoll(void);

sysStates_t systemStateChange(sysStates_t newState);



int8_t setTriggerLevel(uint16_t parameter);

int8_t setQtyAdquisitions(uint16_t parameter);

int8_t setQtySamples(uint16_t parameter);
