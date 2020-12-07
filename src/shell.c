#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "shell.h"
#include "string.h"
#include "dp.h"
#include "com.h"

/*==================[macros and definitions]=================================*/
//#define debugDP
#define maxCommandLength 10
#define maxRxCommandLength 50
/*==================[internal data declaration]==============================*/
static const char command[][maxCommandLength]={
		"mode -a\0",
		"mode -d\0",
		"conf -t\0",
		"conf -q\0",
		"conf -s\0",
		"conf -c\0",
		"conf -r\0",
		"lsdp\0",
		"downldp\0",
		"restart\0"
		"\0",
};
/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
shellCmd_t searchCmd(char *ptrParams){
   int x;
   shellCmd_t com;
   char myCmd[maxRxCommandLength];

   *ptrParams=0;

   getLine(myCmd);
   for(x=0;x<11;x++)
    {
      if(strstr(myCmd,command[x])==myCmd)
      {
    	 strcpy(ptrParams,myCmd+strlen(command[x]));
         return x;
      }
    }
   return noCmd;
}

void shellInit(void)
{
   comRxInit();
}

int8_t taskShell(void)
{
   shellCmd_t cmd;
   char parameters[50];
   uint16_t auxParam;

   cmd=searchCmd(parameters);
   switch(cmd)
   {
	   case modeA:
		    systemStateChange(sysArmed);
		    break;
	   case modeD:
		    systemStateChange(sysDisarmed);
		    break;
	   case restart:
		    systemStateChange(sysInit);
		    break;
	   case confT:
	        auxParam=atoi(parameters);
	        if(auxParam>=minTriggerLevelmV&&auxParam<=maxTriggerLevelmV)
		        setTriggerLevel(auxParam);
		    break;
	   case confQ:
	        auxParam=atoi(parameters);
	        if(auxParam>=minQtyAdquisitions&&auxParam<=maxQtyAdquisitions)
		        setQtyAdquisitions(auxParam);
		    break;
	   case	confS:
	        auxParam=atoi(parameters);
	        if(auxParam>=minQtySamples&&auxParam<=maxQtySamples)
		        setQtySamples(auxParam);
		    break;
	   case noCmd:
	   default:
            return 0;
		   break;
	}
    return 1;
}



