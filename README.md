# CableTester

Tester pre káble, s rôznymi typmi konektorov. 
Jednoduhé pridávanie nových káblov, prípadne tlačidiel alebo switchov - stačí podediť z niektorej z tried a preťažiť funkciu skontroluj, v ktorej je logika testovania. 
Pre fungovanie potom pridať nový wrapper do wrappers, o zvyšok sa postará program.

# Requirements
Je potrebné nainštalovať knižnicu ArduinoSTL. V nej je následne potrebné upraviť "new_handler.cpp" a to zakomentovať riadok 22. 
https://github.com/mike-matera/ArduinoSTL/issues/84
