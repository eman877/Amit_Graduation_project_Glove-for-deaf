

#include <avr/io.h>
#include "config.h"
#include "ADC.h"
#include "I_O.h"
#include "LCD.h"
#include "SIGN.h"
#include <avr/interrupt.h>

int main() {
    init_LCD();
    init_ADC(AREF, PRE_128);
    int Results[5];

    while (1) {

        for (int ChannelNumber = 0; ChannelNumber < 5; ChannelNumber++) {
            ///Sweeping 5 Channels For Readings
            ADC_Channel_Select(ChannelNumber);
            ADC_StartConv();
            ///TMAPPING POT TO FINGERS MOVEMENS(4v FOR FLAT POSITION ,2v FOR 90BEND & 3v FOR 45BEND)
            Results[ChannelNumber] = ADC_read()*.00488;//convert to actual voltage
        }

        LCD_CLEAR();
        Print_Sign(Results);
        _delay_ms(300);
     

    }

}
