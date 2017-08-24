//
// Created by Ankur Meozzi on 21/08/2017.
//

#include "ReadWriteIni.h"

#include <utility>

void ReadWriteIni::writeIni(std::string section) {

}
//getline(cin,tuaStringa);
void ReadWriteIni::writeIni(std::string section, std::string key, std::string value) {

}

void ReadWriteIni::writeIni(std::string section, std::string key, float value) {
    writeIni(std::move(section), std::move(key),std::to_string(value));
}

void ReadWriteIni::writeIni(std::string section, std::string key, int value) {
    writeIni(std::move(section), std::move(key),std::to_string(value));
}

void ReadWriteIni::writeIni(std::string section, std::string key, double value) {
    writeIni(std::move(section), std::move(key),std::to_string(value));
}


std::string ReadWriteIni::readIni(std::string section, std::string key, std::string error ) {

    return error;
}

std::vector<std::string> ReadWriteIni::readIni(std::string section) {
    return std::vector<std::string>();
}

std::vector<std::string> ReadWriteIni::readIni() {
    return std::vector<std::string>();
}

const std::string &ReadWriteIni::getPathFIle() const {
    return pathFIle;
}

void ReadWriteIni::setPathFIle(const std::string &pathFIle) {
    ReadWriteIni::pathFIle = pathFIle;
}











