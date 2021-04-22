#include "cooler.hpp"


Cooler::Cooler(){
  limitaOFF = 450;
  limitaStart = 450;
  limitaMAX =  600;
  putereMIN = 10;
  putereMAX = 255;
}

Cooler::Cooler(int limitaOFF, int limitaStart, int limitaMAX, int putereMIN, int putereMAX){
  this->limitaOFF = limitaOFF;
  this->limitaStart = limitaStart;
  this->limitaMAX = limitaMAX;
  this->putereMIN = putereMIN;
  this->putereMAX = putereMAX;
}

Cooler::~Cooler(){}


int Cooler::getLimitaOFF(){return limitaOFF;}
int Cooler::getLimitaStart(){ return limitaStart;}
int Cooler::getLimitaMAX(){ return limitaMAX; }
int Cooler::getPutereMIN(){ return putereMIN; }
int Cooler::getPutereMAX(){ return putereMAX; }
