/*   !Author      :         Karim Amr El Gendy                                  */
/*   !Date        :         11 NOV, 2022                                        */
/*   !LAYER       :         MCAL                                                */
/*   !Version     :         v1.0                                                */

#ifndef ADC_PRIVATE
#define ADC_PRIVATE


#define ACSR       		*((volatile u8*)0x28)
#define ADMUX       	*((volatile u8*)0x27)
#define ADCSRA       	*((volatile u8*)0x26)
#define ADCH       		*((volatile u8*)0x25)
#define ADCL       		*((volatile u8*)0x24)


#define     ADMUX_MUX0      0         // MUX 0 Bit
#define     ADMUX_MUX1      1         // MUX 1 Bit
#define     ADMUX_MUX2      2         // MUX 2 Bit
#define     ADMUX_MUX3      3         // MUX 3 Bit
#define     ADMUX_MUX4      4         // MUX 4 Bit
#define     ADMUX_ADLAR     5         // ADC Left Adjust Bit
#define     ADMUX_REFS0     6         // ADC Ref Select
#define     ADMUX_REFS1     7         // ADC Ref Select

#define     ADCSRA_ADPS0    0         // ADC Prescalar Selection Bit 0
#define     ADCSRA_ADPS1    1         // ADC Prescalar Selection Bit 1
#define     ADCSRA_ADPS2    2         // ADC Prescalar Selection Bit 2
#define     ADCSRA_ADIE     3         // ADC Interrupt Enable
#define     ADCSRA_ADIF     4         // ADC Interrupt Flag
#define     ADCSRA_ADATE    5         // ADC Auto Trigger Enable
#define     ADCSRA_ADSC     6         // ADC Start Conversion
#define     ADCSRA_ADEN     7         // ADC Enable Bit

// Set the ADC Mode
#define     ENABLE               0
#define     DISABLE              1

// Set the Reference Voltage
#define     AREF                 0
#define     AVCC                 1   
#define     INTERNAL             2


// Set ADC Prescaler 
#define     PRESCALER_MASK       0b11111000
#define     CHANNEL_MASK         0b11100000


#define     DIV_BY_2             0b001
#define     DIV_BY_4             0b010
#define     DIV_BY_8             0b011
#define     DIV_BY_16            0b100
#define     DIV_BY_32            0b101
#define     DIV_BY_64            0b110
#define     DIV_BY_128           0b111



#endif