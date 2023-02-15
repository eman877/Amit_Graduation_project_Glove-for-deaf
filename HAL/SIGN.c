#include <avr/io.h>
#include "config.h"
#include "ADC.h"
#include "I_O.h"
#include "LCD.h"
#include "Sign.h"

void Print_Sign(int* Result) {

    char str1[] = "I LOVE U";
    char str2[] = "YOU";
    char str3[] = "GOOD JOB";
    char str4[] = "THIS IS TERRIBLE";
    char str5[] = "WISH U A HAPPY";
    char str51[] = "LIFE";
    char str6[] = "I'M WATCHING U";
    char str7[] = "I REALLY LOVE U";
    char str8[] = "CAN'T FIND WORD";
    if ((Result[0] == 4) && (Result[1] == 4) &&(Result[2] == 2)&&(Result[3] == 2) &&(Result[4] == 4)) {
        LCD_Write_Str(str1);
    } else if ((Result[0] == 2) && (Result[1] == 4) &&(Result[2] == 2)&&(Result[3] == 2) &&(Result[4] == 2)) {
        LCD_Write_Str(str2);

    } else if ((Result[0] == 4) && (Result[1] == 2) &&(Result[2] == 2)&&(Result[3] == 2) &&(Result[4] == 2)) {
        LCD_Write_Str(str3);

    } else if ((Result[0] == 2) && (Result[1] == 4) &&(Result[2] == 2)&&(Result[3] == 2) &&(Result[4] == 4)) {
        LCD_Write_Str(str4);

    } else if ((Result[0] == 4) && (Result[1] == 4) &&(Result[2] == 4)&&(Result[3] == 4) &&(Result[4] == 4)) {
        LCD_Write_Str(str5);
        LCD_goto(row1, column5);
        LCD_Write_Str(str51);

    } else if ((Result[0] == 2) && (Result[1] == 3) &&(Result[2] == 3)&&(Result[3] == 2) &&(Result[4] == 2)) {
        LCD_Write_Str(str6);

    } else if ((Result[0] == 4) && (Result[1] == 3) &&(Result[2] == 4)&&(Result[3] == 2) &&(Result[4] == 4)) {
        LCD_Write_Str(str7);
    } else {
        LCD_Write_Str(str8);

    }
}

void Print_Sign_Optmized(int* Result) 
{
    char str1[] = "I LOVE U";
    char str2[] = "YOU";
    char str3[] = "GOOD JOB";
    char str4[] = "THIS IS TERRIBLE";
    char str5[] = "WISH U A HAPPY";
    char str51[] = "LIFE";
    char str6[] = "I'M WATCHING U";
    char str7[] = "I REALLY LOVE U";
       if ((Result[0] == 4))
       {
        if ((Result[1] == 4) &&(Result[2] == 2)&&(Result[3] == 2) &&(Result[4] == 4)) {
            LCD_Write_Str(str1);
        }
        if ((Result[1] == 2) &&(Result[2] == 2)&&(Result[3] == 2) &&(Result[4] == 2)) {
            LCD_Write_Str(str3);

        }
        if ((Result[1] == 4) &&(Result[2] == 4)&&(Result[3] == 4) &&(Result[4] == 4)) {
            LCD_Write_Str(str5);
            LCD_goto(row1, column5);
            LCD_Write_Str(str51);
        }
        if ((Result[1] == 3) &&(Result[2] == 4)&&(Result[3] == 2) &&(Result[4] == 4)) {
            LCD_Write_Str(str7);
        }
    } else if ((Result[0] == 2)) {
        if ((Result[1] == 3) &&(Result[2] == 3)&&(Result[3] == 2) &&(Result[4] == 2)) {
            LCD_Write_Str(str6);

        }
        if ((Result[1] == 4) &&(Result[2] == 2)&&(Result[3] == 2) &&(Result[4] == 2)) {
            LCD_Write_Str(str2);

        }
        if ((Result[1] == 4) &&(Result[2] == 2)&&(Result[3] == 2) &&(Result[4] == 4)) {
            LCD_Write_Str(str4);
        } 
        
    }}
