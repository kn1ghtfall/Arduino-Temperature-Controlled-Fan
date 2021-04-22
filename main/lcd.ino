#include "lcd.hpp"


LCD_class::LCD_class(){
   ThermistorPin = 0 ; 
   R1 = 10000; // date preluate din datasheetul termistorului
   c1 = 1.009249522e-03;
   c2 = 2.378405444e-04;
   c3 = 2.019202697e-07;
}

LCD_class::LCD_class(int ThermistorPin, float R1, float c1, float c2, float c3){
  this->ThermistorPin = ThermistorPin;
  this->R1 = R1;
  this->c1 = c1;
  this->c2 = c2;
  this->c3 = c3;
}

LCD_class::~LCD_class(){}

LiquidCrystal_I2C LCD_class::initialize(){
//  LiquidCrystal_I2C lcd(12, 11, 5, 4, 3, 2); // numerele reprezinta pinurile digitale de pe Arduino, acesta sunt conectate la ecranul LCD 
  LiquidCrystal_I2C lcd(0x27, 16, 2);
  return lcd;
}

int LCD_class::getPin(){
  return ThermistorPin;
}

float LCD_class::getR(){
  return R1;
}

float LCD_class::getC1(){
  return c1;
}

float LCD_class::getC2(){
  return c2;
}

float LCD_class::getC3(){
  return c3;
}
