#include "LCD.h"
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include "I_O.h" 
#include <stdlib.h>

void init_LCD() {
    LCD_Half_Dir |= (0xF0);
    setPinDir(LCD_control_dir, RS, OUT);
    setPinDir(LCD_control_dir, RW, OUT);
    setPinDir(LCD_control_dir, EN, OUT);
    setPinData(LCD_control, RW, OFF); ////writing mode only

    LCD_CMD(ReturnHome);
    LCD_CMD(_4BIT_MODE);
    LCD_CMD(D_ON_C_OFF);
    LCD_CMD(Inc_Cur);
    LCD_CLEAR();
    _delay_ms(50);

}

void LCD_DATA(char data) {
    setPinData(LCD_control, RS, ON);

    LCD_Half_Data = (LCD_Half_Data & 0x0F) | (data & 0xF0);
    LCD_EN();
    _delay_ms(10);

    LCD_Half_Data = (LCD_Half_Data & 0x0F) | (data << 4);
    LCD_EN();
    _delay_ms(10);

}

void LCD_CMD(char cmd) {

    setPinData(LCD_control, RS, OFF);

    LCD_Half_Data = (LCD_Half_Data & 0x0F) | (cmd & 0xF0); // 11010000
    LCD_EN();
    _delay_ms(10);

    LCD_Half_Data = (LCD_Half_Data & 0x0F) | (cmd << 4);
    LCD_EN();
    _delay_ms(10);
}

void LCD_EN() {

    setPinData(LCD_control, EN, ON);
    _delay_us(200);
    setPinData(LCD_control, EN, OFF);

}

void LCD_CLEAR() {
    LCD_CMD(0x01);
}

void LCD_Write_Str(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        LCD_DATA(str[i]);
    }
}

void LCD_Write_Num(int num) {
    char buffer[11];
    itoa(num, buffer, 10);
    LCD_Write_Str(buffer);
}

void LCD_goto(int row, int column) {
    if (row) {
        // Second Line
        LCD_CMD(0xC0 | (column & 0x0F));
    } else {
        // First Line
        LCD_CMD(0x80 | (column & 0x0F));
    }


}
