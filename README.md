# Temperature Controlled Fan - Arduino

## Introduction
This project makes a cooler spin faster as the temperature rises. 


## Circuit
Here is the circuit:
![Circuit](/images/Wiring_Cooler_PID.png)
## Components:
* Arduino UNO 
* 12V Power Suppy ( you can use a 9V battery as well )
* 12V Fan 
* N-Channel MOSFET
* Thermistor
* 10K Resistance
* LCD 1602 I2C 

## Installation
You need Arduino IDE : https://www.arduino.cc/en/software

You need to install the Library "LiquidCrystal_I2C.h" : https://www.makerguides.com/character-i2c-lcd-arduino-tutorial/


## How to use the
Upload the code provided in your Arduino board. Try heating up the thermistor, the hotter it gets the faster the fan will spin. 

In Arduino IDE open the Serial Monitor and see what 10-bit value is printed alongside the temperature of your room. Memorize that value (let's say the value is 'x') and heat up the thermistor as much as you can, memorize that value as well( this one is 'y'). These values should be used inside the Cooler constructor.
```cpp
Cooler cooler(350, x , y, 10, 255);
```

## How it works
Wiring our thermistor to a voltage devider, we get higher voltage with higher temperatures. This voltage is the input in our Arduino board. We read this value and determine how fast should the fan spin. 

This is how it should look like: 
![Real_Circuit](/images/Circuit.png)


## Credits
Check out this video for a well-done tutorial: https://www.youtube.com/watch?v=DAn4UguyzfE