#pragma once
#include "Zariadenie.h"

class Konektor : public Zariadenie {
protected:
  TestingMode* mode;

public:
  Konektor(String nazov, byte* piny, TestingMode* test_mode, KonektorTest* testing, size_t length) : Zariadenie(nazov, piny, testing, length), mode(test_mode) {
    for (byte i = 0; i < arr_length; i++) {
      pinMode(pinout[i], OUTPUT);
      digitalWrite(pinout[i], LOW);
    }
  };

  void skontroluj() {
    if (*test == KonektorTest::YES) {
      vypisPiny();
      vypis();

      for (byte i = 0; i < arr_length; i++) {
        digitalWrite(pinout[i], HIGH);
        delay(int(*mode));
        digitalWrite(pinout[i], LOW);
      }
    }
  };

  void vypis() {
    Serial.print("Testujem : " + nazovKonektoru);
    Serial.print("Testmode : ");
    Serial.println(int(*mode));
    Serial.print("Dlzka Pola : ");
    Serial.println(arr_length);
    Serial.println("_______________________");
    for (int i = 0; i < 5; i++) {
      Serial.print(pinout[i]);
      Serial.print(" , ");
    }
    Serial.println();
  }

  ~Konektor() {};
};