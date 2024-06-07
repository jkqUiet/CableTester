#pragma once
#include "Konektor.h"

class KonektorCTL : public Konektor {
  int* hranice;
  byte hraniceLength;

  void testOneSide(int senzor1, int senzor2) {
    if (senzor1 > senzor2) {
      digitalWrite(pinout[3], HIGH);
    }
    if (senzor1 < senzor2) {
      digitalWrite(pinout[4], HIGH);
    }
    delay(int(*mode));
    digitalWrite(pinout[3], LOW);
    digitalWrite(pinout[4], LOW);
  };

  void testRezistor(int senzor1, int senzor2) {
    int rezistor = senzor1 - senzor2;
    if (rezistor <= hranice[0] && rezistor >= hranice[1]);
    {
      digitalWrite(pinout[2], HIGH);
    }
  };

public:
  KonektorCTL(String nazov, byte* piny, int* hranice, TestingMode* test_mode, KonektorTest* testing, size_t length, size_t hraniceLength) : Konektor(nazov, piny, test_mode, testing, length), hranice(hranice), hraniceLength(hraniceLength) {
    for (byte i = 0; i < arr_length; i++) {
      pinMode(pinout[i], OUTPUT);
      digitalWrite(pinout[i], LOW);
    }
  };

  void skontroluj() {
    if (*test == KonektorTest::YES) {
      digitalWrite(pinout[0], HIGH);
      digitalWrite(pinout[1], LOW);
      int sensorValue1 = analogRead(A0);
      int sensorValue2 = analogRead(A1);
      testRezistor(sensorValue1, sensorValue2);
      testOneSide(sensorValue1, sensorValue2);
      digitalWrite(pinout[0], LOW);
      digitalWrite(pinout[1], HIGH);
      testOneSide(sensorValue2, sensorValue1);
      digitalWrite(pinout[2], LOW);
      digitalWrite(pinout[1], LOW);
    }
  };

  ~KonektorCTL() {};
};