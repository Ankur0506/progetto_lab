#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include "ReadWriteIni.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    system("del prova.ini");
    ReadWriteIni f("prova");
    f.writeIni("system","ios","windows");
    f.writeIni("system","version",5.7);
    f.writeIni("system","ram","4Gb");
    f.writeIni("internet access","name","My internet");
    f.writeIni("internet access","password","******");
    f.writeIni("internet access","proxy","");
    f.writeIni("system","processor","Intel");
    f.writeIni("internet access","theme",3);
    f.writeIni("Memory");
    f.writeIni("Programs");
    f.writeIni("Memory","total memory","200 Gb");
    f.writeIni("Memory","system memory","25 Gb");
    f.writeIni("Programs","games","windows games");
    f.writeIni("Memory","free memory","172 Gb");
    f.writeIni("Programs","driver","");
    f.writeIni("system","serial number",1943);
    f.writeIni("internet access","adsblock","true");
}