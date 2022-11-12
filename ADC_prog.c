/*   !Author      :         Karim Amr El Gendy                                  */
/*   !Date        :         11 NOV, 2022                                        */
/*   !LAYER       :         MCAL                                                */
/*   !Version     :         v1.0                                                */


#include "ADC_interface.h"



/* Global Pointer to the function */
static void (*Global_pvCallBackFunction)(void) = NULL;

/* Global Variable to store the data */
extern u16    Global_u16DigitalValue = 0;

/*
    Prebuilt initialization function to save both space
    and time prebuilding the code
*/
void MADC_voidInit(void)
{
    /*Check if the ADC is Enabled or Not*/
    #if     ADC_ENABLE      ==      ENABLE
        #if     ADC_REF_SELECTION   ==  AREF
                CLR_BIT(ADMUX, ADMUX_REFS0);
                CLR_BIT(ADMUX, ADMUX_REFS1);
        #elif   ADC_REF_SELECTION   ==  AVCC
                SET_BIT(ADMUX, ADMUX_REFS0);
                CLR_BIT(ADMUX, ADMUX_REFS1);
        #elif   ADC_REF_SELECTION   ==  INT_256VOLT
                SET_BIT(ADMUX, ADMUX_REFS0);
                SET_BIT(ADMUX, ADMUX_REFS1);
        #else
            #error "ADC_REF_SELECTION Configuration Error"else
        #endif

        /********** Check for the prescalar value **********/
        ADCSRA &= PRESCALER_MASK;                           // Mask the first three bits
        ADCSRA |= ADC_PRESCALER_VALUE;                  // Set the new prescaler Value
        
        /* Enable the ADC */    
        SET_BIT(ADCSRA, ADCSRA_ADEN);
    #elif   ADC_ENABLE      ==      DISABLE
        CLR_BIT(ADCSRA, ADCSRA_ADEN)
    #else
        #error  "ADC_ENABLE = CONFIGURATION ERROR"
    #endif    
}

u16 MADC_u16StartConversionSync(u8 Copy_u8ChannelNumber)
{
    /* Set The Channel Num */
    ADMUX &= CHANNEL_MASK;
    ADMUX |= Copy_u8ChannelNumber;
	
    /* Start the Conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);
	
    /* Polling (busy wait) Till the Flag is Raised */
    while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);
	
    /* Clear the Flag */
    SET_BIT(ADCSRA, ADCSRA_ADIF);
    return  ADC;
}

void MADC_voidStartConversionAsync(u8 Copy_u8ChannelNumber)
{
    /* Set The Channel Num */
    ADMUX &= CHANNEL_MASK;
    ADMUX |= Copy_u8ChannelNumber;
	
    /* Start the Conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);
	
    /* Enable The Interrupt */
    SET_BIT(ADCSRA, ADCSRA_ADIE);

}

/***********************************/
void MADC_voidSetCallBack(void (*Copy_pvNotificationFunction)(void))
{
    Global_pvCallBackFunction = &Copy_pvNotificationFunction;
}

/* ISR Function For ADC */
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
    if(Global_pvCallBackFunction != NULL)
    {
        /* Get Data and Store it in a global variable */
        Global_u16DigitalValue = ADC;
		
        /* Call the Callback Function */
        Global_pvCallBackFunction();
		
        /* Disable the interrupt */
        CLR_BIT(ADCSRA, ADCSRA_ADIE);
    }
    else
    {

    }
}

u8 MADC_u8StartConversionSync(u8 Copy_u8ChannelNumber)
{
    /* Set The Channel Num */
    ADMUX &= CHANNEL_MASK;
    ADMUX |= Copy_u8ChannelNumber;
    /* Select the left Adjust */

    /* Start the Conversion */
    SET_BIT(ADCSRA, ADCSRA_ADSC);
    /* Polling (busy wait) Till the Flag is Raised */
    while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);
	
    /* Clear the Flag */
    SET_BIT(ADCSRA, ADCSRA_ADIF);
    return  ADC;
}

