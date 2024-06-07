#pragma once

#include "Zariadenie.h"

class Button : public Zariadenie {

public:
  Button(String nazov, byte* piny, KonektorTest* testing, size_t length) : Zariadenie(nazov, piny, testing, length) {
    for (byte i = 0; i < arr_length; i++) {
      pinMode(pinout[i], INPUT);
    }
  };

  void skontroluj() {
    
    for (byte i = 0; i < arr_length; i++) {
      int value = digitalRead(pinout[i]);
      if (value == HIGH) {
        vypisPiny();
        vypis();
        *test = KonektorTest::YES;
      } else {
        *test = KonektorTest::NO;
      }
    }
  };

  void vypis() {
    Serial.print("Testujem : " + nazovKonektoru);
    Serial.print("TESTING : ");
    Serial.println(int(*test));
    Serial.print("Dlzka Pola : ");
    Serial.println(arr_length);
    Serial.println("_______________________");
  }

  ~Button() {};
};