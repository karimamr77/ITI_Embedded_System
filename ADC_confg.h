/*   !Author      :         Karim Amr El Gendy                                  */
/*   !Date        :         11 NOV, 2022                                        */
/*   !LAYER       :         MCAL                                                */
/*   !Version     :         v1.0                                                */

#ifndef ADC_Config
#define ADC_Config


#define     ADC_ENABLE           ENABLE
/*
    Options:
                AREF         AVCC        INT_256VOLT
*/                
#define     ADC_REF_SELECTION    AVCC
/*
    Options:
                DIV_BY_2         DIV_BY_4        DIV_BY_8
                DIV_BY_16        DIV_BY_32       DIV_BY_64
                DIV_BY_128  
*/ 
#define     ADC_PRESCALER_VALUE  DIV_BY_128   



#endif