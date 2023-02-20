/*
  teclado_i2c.h - Biblioteca de Teclado i2c para Arduino desenvolvida por
  Luiz Fernando M. Arruda
*/

#ifndef teclado_i2c_h
#define teclado_i2c_h

#include "Arduino.h"

class teclado_i2c {
    public:
		byte getTecla();
		void setEndereco(byte Endereco);
		void begin();
	private:
		byte _Tecla;
		byte _Endereco;
};

#endif
