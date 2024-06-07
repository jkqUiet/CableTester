#pragma once
#include "Konektor.h"

class KonektorThreeWay : public Konektor {

MultipleSwitchKonektorTest* threeWayMode;
byte konektorNumber;

public:
  KonektorThreeWay(String nazov, byte* piny, TestingMode* test_mode, KonektorTest* testing, MultipleSwitchKonektorTest* threeWay, byte konNumber, size_t length) : Konektor(nazov, piny, test_mode, testing, length), threeWayMode(threeWay), konektorNumber(konNumber) {
    for (byte i = 0; i < arr_length; i++) {
      pinMode(pinout[i], OUTPUT);
      digitalWrite(pinout[i], LOW);
    }
  };

  void skontroluj() {
    Serial.println("TRIPLEKonektor : ");
    Serial.println(int(*threeWayMode));
    Serial.println(konektorNumber);
    Serial.println("_________________");
    if (*test == KonektorTest::YES && int(*threeWayMode) == konektorNumber) {
      for (byte i = 0; i < arr_length; i++) {
        digitalWrite(pinout[i], HIGH);
        delay(int(*mode));
        digitalWrite(pinout[i], LOW);
      }
    }
  };

  ~KonektorThreeWay() {};
};