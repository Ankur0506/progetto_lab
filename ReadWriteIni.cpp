//
// Created by Ankur Meozzi on 21/08/2017.
//

#include "ReadWriteIni.h"




//getline(cin,tuaStringa);
void ReadWriteIni::writeIni(std::string section, std::string key, std::string value) {

}

void ReadWriteIni::readIni(std::string section, std::string key, std::string error = nullptr) {

}

const std::string &ReadWriteIni::getPathFIle() const {
    return pathFIle;
}

void ReadWriteIni::setPathFIle(const std::string &pathFIle) {
    ReadWriteIni::pathFIle = pathFIle;
}
