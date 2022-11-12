/*   !Author      :         Karim Amr El Gendy                                  */
/*   !Date        :         11 NOV, 2022                                        */
/*   !LAYER       :         MCAL                                                */
/*   !Version     :         v1.0                                                */

#ifndef ADC_INTERFACE
#define ADC_INTERFACE

#include "ADC_private.h"
#include "ADC_config.h"

// Set the ADC Channel
#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_CHANNEL_6 6
#define ADC_CHANNEL_7 7



enum
{
OK,
NOK
}ADC_ErrorStatus;

// ADC Function
void 			  ADC_init          ();
ADC_ErrorStatus   ADC_StartConvSyn	(u8 channel,u8* result);
ADC_ErrorStatus   ADC_StartConvAsyn	(u8 channel,u8* result, void (*fun)(void));



#endif