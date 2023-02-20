/*
Demonstração biblioteca teclado_i2c 
*/
#include "teclado_i2c.h"

teclado_i2c teclado01;

#define i2c_teclado1 0x20

void setup() {
  Serial.begin(9600);
  teclado01.setEndereco(i2c_teclado1);
  Serial.println("Testando modulos no barramento i2c.");
  Wire.begin(); 
  // testa comunicacao teclado01
  Wire.beginTransmission(i2c_teclado1);
  int error = Wire.endTransmission();
  if (error == 0) {
    Serial.println("Teclado01 Online");
  } else {
    Serial.println("Teclado01 Offline");
  }
  teclado01.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int tecla1 = teclado01.getTecla();
  Serial.println(tecla1);
  delay(500);  
}
