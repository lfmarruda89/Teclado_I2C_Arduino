/*
	ds1307.cpp - Biblioteca RTC para Arduino desenvolvida por
  Luiz Fernando M. Arruda
*/

#include "Arduino.h"
#include <Wire.h>
#include "teclado_i2c.h"

byte teclado_i2c::getTecla(){
  byte memoria = 1;
  byte valor = 0;
  for (int i = 1; i <=4 ; i++){
    Wire.beginTransmission(_Endereco);
    Wire.write(memoria);
    Wire.endTransmission();
    Wire.requestFrom(_Endereco, 1);
     
    if (Wire.available()){
      valor=Wire.read();
    }
    Wire.endTransmission();
    if (valor > 16 ){       
      break;
    }
    memoria = memoria << 1;
  }
  return valor;  
}
void teclado_i2c::begin(){
  Wire.beginTransmission(_Endereco);
  Wire.write(0x00); // MEMORIA INIC
  Wire.write(0x00); 
  Wire.endTransmission();
}
  
void teclado_i2c::setEndereco(byte Endereco){
  _Endereco = Endereco;
}

