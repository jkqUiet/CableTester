#pragma once

#include "Button.h"

class TripleSwitch : public Button {

MultipleSwitchKonektorTest* threeWaySwitch;

public:
  TripleSwitch(String nazov, byte* piny, MultipleSwitchKonektorTest* threeWay, size_t length) : Button(nazov, piny, nullptr, length), threeWaySwitch(threeWay) {
    for (byte i = 0; i < arr_length; i++) {
      pinMode(pinout[i], INPUT);
    }
  };

  void skontroluj() {
    int pin1 = digitalRead(pinout[0]);
    int pin2 = digitalRead(pinout[1]);
    Serial.println("TRIPLESWITCH : ");
    Serial.println(pin1);
    Serial.println(pin1);
    Serial.println("_________________");
    if (pin1 == LOW && pin2 == LOW) *threeWaySwitch = MultipleSwitchKonektorTest::FIRST;
    if (pin1 == HIGH && pin2 == LOW) *threeWaySwitch = MultipleSwitchKonektorTest::SECOND;
    if (pin1 == LOW && pin2 == HIGH) *threeWaySwitch = MultipleSwitchKonektorTest::THIRD;
  };

  ~TripleSwitch() {};
};
