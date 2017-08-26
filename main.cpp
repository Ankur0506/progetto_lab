#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include "ReadWriteIni.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    ReadWriteIni f;
    f.writeIni("s","k",5.7);
}