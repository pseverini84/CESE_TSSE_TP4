#define minTriggerLevelmV 10
#define maxTriggerLevelmV 1000
#define minQtyAdquisitions 10
#define	maxQtyAdquisitions 1000
#define minQtySamples 10
#define	maxQtySamples 1200

typedef enum{
	modeA,
	modeD,
	confT,
	confQ,
	confS,
	confC,
	confR,
	lsdp,
	downldp,
	restart,
	noCmd
} shellCmd_t;//posibles comandos del sistema

shellCmd_t searchCmd(char *ptrParams);//funcion que busca un comando, si lo encuentra lo devuelve como return.
void shellInit(void);
int8_t taskShell(void);


