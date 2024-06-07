#include "KonButWrapper.h"


std::vector<KonButWrapper*>* wrappers;
TestingMode test_mode = TestingMode::FAST;

void setup() {
Serial.begin(9600);
wrappers = new std::vector<KonButWrapper*>();
wrappers->push_back(new KonButWrapper("Cierny", {36}, { 13, 12, 11, 10 }, &test_mode));
wrappers->push_back(new KonButWrapper("ModryNeviemCislo", "Modry295", "Modry214", {34}, {40,38},
                                { 9, 8, 7, 6, 5, 4, 3, 2 },
                                { 9, 8, 7, 6, 5, 4, 3, 16 },
                                { 9, 8, 7, 6, 5, 4, 3, 27 },
                                &test_mode));
wrappers->push_back(new KonButWrapper("Biely", {32}, { 14, 15, 16, 17, 18, 19, 20, 21 }, &test_mode));
wrappers->push_back(new KonButWrapper("Zlty", {28}, { 37, 39 }, &test_mode));
wrappers->push_back(new KonButWrapper("MalyBiely", {30}, { 27, 33, 35 }, &test_mode));
wrappers->push_back(new KonButWrapper("CTL", {0}, { 41, 43, 49, 51, 53 }, { 64, 30 }, &test_mode));
wrappers->push_back(new KonButWrapper("Prepinanie_Timer", {24}, &test_mode));
}

void loop() {
  for (int i = 0; i < wrappers->size() - 1; i++) {
    wrappers->at(wrappers->size()-1)->skontroluj();
    wrappers->at(i)->skontroluj();
  }
}

