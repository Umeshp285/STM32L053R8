#include "stm32l053xx.h"

#ifndef FGPMMOPA6H_H
#define FGPMMOPA6H_H

extern volatile uint8_t Transmission_In_Progress;
extern char 						GGA_Message[128];											/* Original GGA message */
extern char 						GSA_Message[128];											/* Original GSA message */
extern char 						GSV_Message[128];											/* Original GSV message */
extern char 						RMC_Message[128];											/* Original RMC message */
extern char 						VTG_Message[128];											/* Original VTG message */

/* Raw RMC data */
typedef struct RMC_Data
{
	int New_Data_Ready;
	char Message_ID[7];						/* RMC Protocol header */
	char UTC_Time[11];						/* hhmmss.sss */
	char Status[2];								/* A = data valid, V = data NOT valid */
	char Latitude[10];						/* ddmm.mmmm */
	char N_S_Indicator[2];				/* N = North, S = South */
	char Longitude[11];						/* dddmm.mmmm */
	char E_W_Indicator[2];				/* E = East, W = West */
	char Speed_Over_Ground[5];		/* In Knots */
	char Course_Over_Ground[7];		/* Degrees */
	char Date[7];									/* ddmmyy */
	char Mode[5];									/* A = autonomous mode, D = Differential mode, E = Estimated mode */
}RMC_Data;

/* This is the data after it has been parsed properly formated */
typedef struct GPS_Data
{
	int Valid_Data;
	char UTC_Time[15];
	char Date[9];
	char Latitude[15];
	char Longitude[15];
	float Ground_Speed;
}GPS_Data;

/* Initialization methods */
extern void USART1_Init(void);
extern void FGPMMOPA6H_Init(void);

/* USART Methods */
extern int USART1_GetChar(void);
extern char USART1_PutChar(char character);
extern void USART1_Read(void);
extern void USART1_Send(char c[]);

/* RMC Data */
extern void FGPMMOPA6H_Parse_RMC_Data(void);
extern char* FGPMMOPA6H_Get_RMC_UTC_Time(void);
extern char* FGPMMOPA6H_Get_RMC_Latitude(void);
extern char* FGPMMOPA6H_Get_RMC_Longitude(void);
extern float FGPMMOPA6H_Get_RMC_Ground_Speed(void);
extern int FGPMMOPA6H_Get_RMC_Status(void);
extern char* FGPMMOPA6H_Get_RMC_Date(void);
extern void Print_RMC_Data(void);

/*GPS Data*/
extern void FGPMMOPA6H_Get_GPS_Data(void);

#endif
