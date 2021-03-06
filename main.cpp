#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include "ReadWriteIni.h"

int main() {
    system("rm prova.ini");
    system("rm error.ini");
    ReadWriteIni f("prova.ini");
    f.writeIni("system","ios","windows");
    f.writeIni("internet access","name","My internet");
    f.writeIni("internet access","password","******", "not visible");
    f.writeIni("system","version",5.7);
    f.writeIni("system","ram","4Gb");

    f.writeIni("internet access","proxy","");
    f.writeIni("system","processor","Intel");
    f.writeIni("internet access","theme",3);
    f.writeIni("Memory","rom");
    f.writeIni("Programs");
    f.writeIni("Memory","total memory","200 Gb");
    f.writeIni("Memory","system memory","25 Gb","also recovery unit");
    f.writeIni("Programs","games","windows games");
    f.writeIni("Memory","free memory","172 Gb");
    f.writeIni("Programs","driver","");
    f.writeIni("system","serial number",1943);
    f.writeIni("internet access","adsblock","true");
    f.writeIni("Programs","word","open");
    f.writeIni("directory");
    f.writeIni("directory","documenti","3");
    f.writeIni("Programs","clion autentication","");
    f.writeIni("Programs","cmake","true");
    f.writeIni("directory","scrivania","23");
    f.writeIni("internet access","password","******", "not visible, you aren't authorized");
    f.writeIni("Memory","system memory","25 Gb");
    f.writeIni("Memory");

    std::cout<<"\nlettura"<<std::endl;
    std::cout<<f.readIni("Memory","total memory")<<std::endl;
    std::cout<<f.readIni("Programs","word")<<std::endl;
    std::cout<<f.readIni("Memory")[2]<<std::endl;
    std::cout<<f.readIni()[0]<<std::endl;
    f.setPathFIle("error.ini");
    f.writeIni("bho","non","so");
    f.setPathFIle("prova.ini");
    f.writeIni("Veicolo","macchina","auto");
}
