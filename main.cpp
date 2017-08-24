#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include "ReadWriteIni.h"


int main() {
    /*std::cout << "Hello, World!" << std::endl;

    int n =13;
    float f=445.12;
    bool b=true;
    std::string s = std::to_string(b);
    std::cout<< s;

    std::cerr<< "s";*/

    ReadWriteIni f("fff");
    f.writeIni("s","k",5.7);
}