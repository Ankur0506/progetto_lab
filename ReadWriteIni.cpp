//
// Created by Ankur Meozzi on 21/08/2017.
//

#include "ReadWriteIni.h"

#include <iostream>

void ReadWriteIni::writeIni(std::string section) {

}
//getline(cin,tuaStringa);
void ReadWriteIni::writeIni(std::string section, std::string key, std::string value) {
    std::ofstream outfile;
    outfile.open(pathFIle+".ini");
    outfile.close();
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
    std::ifstream infile;
    std::string str;
    bool readOn = false;
    infile.open(pathFIle+".ini");
    std::string value;
    if(!infile.fail()){
        std::cout << "File is open" << std::endl;
        while(getline(infile,str)) {
            //std::cout<< str <<std::endl;
            while(readOn) {
                if((str.find("[") == std::string::npos) && (str.find("]") == std::string::npos)){

                }
                else readOn=false;
            }
            if(str=="["+section+"]") readOn = true;
        }
    }
    else std::cout<< "Error! the file doesn't exist in this path"<< std::endl;
    if() std::cout<< "I can't find this section"<< std::endl;
    return std::move(value);
}

std::list<std::string> ReadWriteIni::readIni(std::string section) {
    std::ifstream infile;
    std::string str;
    bool readOn = false;
    infile.open(pathFIle+".ini");
    std::list<std::string> keys;
    if(!infile.fail()){
        std::cout << "File is open" << std::endl;
        while(getline(infile,str)) {
            //std::cout<< str <<std::endl;
            while(readOn) {
                if((str.find("[") == std::string::npos) && (str.find("]") == std::string::npos)){
                    keys.push_back(std::move(str));
                }
                else readOn=false;
            }
            if(str=="["+section+"]") readOn = true;
        }
    }
    else std::cout<< "Error! the file doesn't exist in this path"<< std::endl;
    if(keys.empty()) std::cout<< "I can't find this section"<< std::endl;
    return std::move(keys);

}

std::list<std::string> ReadWriteIni::readIni() {
    std::ifstream infile;
    std::string str;
    infile.open(pathFIle+".ini");
    std::list<std::string> sections;
    if(!infile.fail()){
        std::cout << "File is open" << std::endl;
        while(getline(infile,str)) {
            std::cout<< str <<std::endl;
            if((str.find("[") != std::string::npos) && (str.find("]") != std::string::npos)){
                sections.push_back(std::move(str));
            }
        }
    }
    else std::cout<< "Error! the file doesn't exist in this path"<< std::endl;
    if(sections.empty()) std::cout<< "I can't find any section"<< std::endl;
    return std::move(sections);
}

const std::string &ReadWriteIni::getPathFIle() const {
    return pathFIle;
}

void ReadWriteIni::setPathFIle(const std::string &pathFIle) {
    ReadWriteIni::pathFIle = pathFIle;
}











