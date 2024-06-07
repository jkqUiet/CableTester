#pragma once
#include "Button.h"

class TimerButton : public Button {

  TestingMode* testing_mode;

public:
  TimerButton(String nazov, byte* piny, TestingMode* testing_mode, size_t length) : Button(nazov, piny, nullptr, length), testing_mode(testing_mode) {
    for (byte i = 0; i < arr_length; i++) {
      pinMode(pinout[i], INPUT);
    }
  };

  void skontroluj() {
    for (byte i = 0; i < arr_length; i++) {
      int value = digitalRead(pinout[i]);
      //Serial.println("_____:_:_:_:_:_:_:_:");
      //vypis();
      //Serial.println(value);
      //Serial.println("_____:_:_:_:_:_:_:_:");
      if (value == HIGH) {
        *testing_mode = TestingMode::FAST;
      } else {
        *testing_mode = TestingMode::SLOW;
      }
    }
  };

  void vypis() {
    vypisPiny();
    
  }

  ~TimerButton() {};
};