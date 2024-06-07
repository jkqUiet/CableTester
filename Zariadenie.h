#pragma once
#include <Arduino.h>
#include "Mode.h"

class Zariadenie {
protected:
  String nazovKonektoru;
  byte* pinout;
  byte arr_length;
  KonektorTest* test;

public:
  Zariadenie(String nazov, byte* piny, KonektorTest* testing, size_t length) 
    : nazovKonektoru(nazov), pinout(piny), test(testing), arr_length(length) {
  };

  virtual void vypis() =0;
  void vypisPiny() {
    for (int i = 0; i < arr_length; i++) {
      Serial.print(pinout[i]);
      Serial.print(" , ");
    }
    Serial.println();
  }
  virtual void skontroluj() = 0;
  virtual ~Zariadenie() {
    delete test;
  };
};