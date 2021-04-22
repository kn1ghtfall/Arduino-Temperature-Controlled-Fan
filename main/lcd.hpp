#pragma once
#include <LiquidCrystal_I2C.h>

class LCD_class
{
private:
    int ThermistorPin ;
    float R1;
    float c1 = 1.009249522e-03;
    float c2 = 2.378405444e-04;
    float c3 = 2.019202697e-07;
public:
    LCD_class();
    LCD_class(int, float, float, float, float);
    ~LCD_class();
    LiquidCrystal_I2C initialize();
    int getPin();
    float getR();
    float getC1();
    float getC2();
    float getC3();

};
