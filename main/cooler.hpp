#pragma once

class Cooler{
private:
    int limitaOFF; // Under this limit the cooler will stop 
    int limitaStart;  // The smallest value that we allow to spin the cooler
    int limitaMAX; // If this limit is exceeded then the cooler will work at max power
    int putereMIN; // The percentage of power that will be applied to the cooler when 'limitaStart' is exceeded
    int putereMAX; // The percentage of power that will be applied to the cooler when 'limitaMAX' is exceeded
public:
    Cooler();
    Cooler(int, int, int, int, int);
    ~Cooler();

    int getLimitaOFF();
    int getLimitaStart();
    int getLimitaMAX();
    int getPutereMIN();
    int getPutereMAX();
};
