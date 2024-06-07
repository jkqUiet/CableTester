#pragma once

#include "TimerButton.h"
#include "TripleSwitch.h"
#include "KonektorThreeWay.h"
#include "KonektorCTL.h"

#include <ArduinoSTL.h>
#include <vector>

class KonButWrapper {
  std::vector<Zariadenie*> devices;
public:
  KonButWrapper(String nazov, std::initializer_list<byte> pinyTlacidlo, std::initializer_list<byte> pinyKonektor, TestingMode* test_mode) {
    KonektorTest* testing = new KonektorTest;
    String buttonNazov = "Spinac : " + nazov;
    String konektorNazov = "Konektor : " + nazov;
    devices.push_back(new Button(buttonNazov, const_cast<byte*>(pinyTlacidlo.begin()), testing, pinyTlacidlo.size()));
    devices.push_back(new Konektor(konektorNazov, const_cast<byte*>(pinyKonektor.begin()), test_mode, testing, pinyKonektor.size()));
  }

  KonButWrapper(String nazov, std::initializer_list<byte> pinyTlacidlo, TestingMode* test_mode) {
    String buttonNazov = "Spinac : " + nazov;
    devices.push_back(new TimerButton(buttonNazov, const_cast<byte*>(pinyTlacidlo.begin()), test_mode, pinyTlacidlo.size())); 
  }

  KonButWrapper(String nazov, String nazov2, String nazov3, std::initializer_list<byte> pinyTlacidlo, std::initializer_list<byte> pinyThreeWay, 
                std::initializer_list<byte> pinyKonektor, std::initializer_list<byte> pinyKonektor2, std::initializer_list<byte> pinyKonektor3, 
                TestingMode* test_mode) {
    KonektorTest* testing = new KonektorTest;
    MultipleSwitchKonektorTest* switchCon = new MultipleSwitchKonektorTest;
    String buttonNazov = "Spinac ThreeWay YES/NO : " + nazov;
    String buttonNazovThree = "Spinac ThreeWay Positions : " + nazov;
    String konektorNazov = "Konektor : " + nazov;
    String konektorNazov2 = "Konektor : " + nazov2;
    String konektorNazov3 = "Konektor : " + nazov3;
    devices.push_back(new Button(buttonNazov, const_cast<byte*>(pinyTlacidlo.begin()), testing, pinyTlacidlo.size()));
    devices.push_back(new TripleSwitch(buttonNazovThree, const_cast<byte*>(pinyThreeWay.begin()), switchCon, pinyThreeWay.size()));
    devices.push_back(new KonektorThreeWay(konektorNazov, const_cast<byte*>(pinyKonektor.begin()), test_mode, testing, switchCon, 0, pinyKonektor.size()));
    devices.push_back(new KonektorThreeWay(konektorNazov2, const_cast<byte*>(pinyKonektor2.begin()), test_mode, testing, switchCon, 1, pinyKonektor2.size()));
    devices.push_back(new KonektorThreeWay(konektorNazov3, const_cast<byte*>(pinyKonektor3.begin()), test_mode, testing, switchCon, 2, pinyKonektor3.size()));
  }

  KonButWrapper(String nazov, std::initializer_list<byte> pinyTlacidlo, std::initializer_list<byte> pinyKonektor, std::initializer_list<int> hranice, TestingMode* test_mode) {
    KonektorTest* testing = new KonektorTest;
    String buttonNazov = "Spinac : " + nazov;
    String konektorNazov = "Konektor : " + nazov;
    devices.push_back(new Button(buttonNazov, const_cast<byte*>(pinyTlacidlo.begin()), testing, pinyTlacidlo.size()));
    devices.push_back(new KonektorCTL(konektorNazov, const_cast<byte*>(pinyKonektor.begin()), const_cast<int*>(hranice.begin()), test_mode, testing, pinyKonektor.size(), hranice.size()));
  }

  void skontroluj() {
    for (int i = 0; i < devices.size(); i++) {
      devices[i]->skontroluj();
    }
  };

  ~KonButWrapper() {
  };
};