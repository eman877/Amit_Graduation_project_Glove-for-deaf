

#ifndef LCD_H
#define	LCD__H

#ifdef	__cplusplus
extern "C" {
#endif
#define RS      PD0
#define RW      PD1
#define EN      PD2

#define LCD_Half_Data       PORTC
#define LCD_Half_Dir        DDRC
#define LCD_control         _PD
#define LCD_control_dir     _PD

#define LCD_data            _PC       
#define LCD_data_dir        _PC
///////////////////////////////////////
#define _4BIT_MODE 0x28
#define ReturnHome 0x02
#define D_ON_C_OFF 0x0C
#define Inc_Cur    0x06

#define row0        0
#define row1        1
#define column5     5

void init_LCD();
void LCD_DATA(char data);
void LCD_CMD(char cmd);
void LCD_EN();
void LCD_CLEAR();
void LCD_Write_Str(char*);
void LCD_Write_Num(int num);
void LCD_goto(int row, int column);




#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

