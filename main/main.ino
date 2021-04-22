#include "lcd.hpp"
#include "cooler.hpp"

int Vo;
float logR2, R2, T;

LCD_class ecranLCD;
LiquidCrystal_I2C lcd = ecranLCD.initialize();


Cooler cooler(350, 440 , 600, 10, 255); // example of values for starting the cooler around 23 degrees Celsius at 5% of the power ( barely spinning )
                                        // You have to adjust it to work for your room temperature

int sensorPin = A0; // gets output of the Voltage Divider
int PWM = 3; // Output going to Transistor
int sensorVal;
int PWMVal;

void setup() {
//   lcd.begin(16, 2);

  // LCD I2C setup code
  lcd.init();
  lcd.backlight();
  
  
  pinMode(sensorPin, INPUT); // gets the values from the Voltage Divider 
  pinMode(PWM, OUTPUT); // 
  Serial.begin(9600); // we are going to look at a 10 bit value coming from the Voltage Divider

}

void loop() {
  //
  // COOLER Code Section
  // 
  

  sensorVal = analogRead(sensorPin); // reading the Voltage Divider value in 10-bit format ( interval : [0, 1023] ) 
  Serial.println(sensorVal); // prints the Voltage Divider value 
  if(sensorVal >cooler.getLimitaMAX()){
    sensorVal = cooler.getLimitaMAX();
  }

  // 
  
  // example of custom use : PWMVal = map(sensorVal, 400, 800, 0, 255);
    // this means that we map values in a linear manner, from 10-bit to 8-bit  
    // PWM values are represented in 8-bit while digital  
    // second and third parameter represent a range of values where the measured value from the sensor pin will be in, 
    // PWMVal = 0 -> 0% Cooler Power
    // PWMVal = 255  -> 100% Cooler Power 
  PWMVal = map(sensorVal, cooler.getLimitaStart(), cooler.getLimitaMAX(), cooler.getPutereMIN(), cooler.getPutereMAX()); 

  
  // Below a certain value there wont be enough power to spin the cooler so don't give it any power 
  if(sensorVal <cooler.getLimitaOFF()){
    PWMVal = 0;
  }

  //write the PWM value to the pwm output 
  analogWrite(PWM, PWMVal);

 //
 // LCD Code Section
 // 
  Vo = analogRead(ecranLCD.getPin());
  R2 = ecranLCD.getR() * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (ecranLCD.getC1() + ecranLCD.getC2()*logR2 + ecranLCD.getC3()*logR2*logR2*logR2));
  T = T - 273.15;



  Serial.println(T);
  lcd.setCursor(0, 0);
  lcd.print("Temp = ");
  lcd.print(T);   
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Cooler = ");
   if(sensorVal <cooler.getLimitaStart())
    lcd.print("0");
   else
    lcd.print((float)100*(sensorVal - cooler.getLimitaStart()) / (cooler.getLimitaMAX() - cooler.getLimitaStart()));   
  lcd.print("%");



  
  delay(500);            
  lcd.clear();

}
