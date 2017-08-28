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
    outfile.open(pathFIle+".ini",);

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


std::string ReadWriteIni::readIni(const std::string &section, const std::string &key ) {
    std::ifstream infile;
    std::string str;
    std::string value;
    bool found = false;
    bool readOn = false;
    infile.open(pathFIle+".ini");
    if(!infile.fail()){
        std::cout << "File is open" << std::endl;
        while(getline(infile,str) && !found) {
            str = deleteComment(str);
            if(readOn) {
                if(str.find('[') == std::string::npos || (str.find(']') == std::string::npos)){
                    auto posZ = str.find('=');
                    if( key == str.substr(0,posZ)) {
                        value = str.substr(posZ+1);
                        found = true;
                    }
                }
                else readOn=false;
            }
            if(str=="["+section+"]") readOn = true;
        }
        if(value.empty()) std::cout<< "I can't find this section"<< std::endl;
    }
    else std::cout<< "Error! the file doesn't exist in this path"<< std::endl;
    return std::move(value);
}

std::vector<std::string> ReadWriteIni::readIni(const std::string &section) {
    std::ifstream infile;
    std::string str;
    bool found = false;
    bool readOn = false;
    infile.open(pathFIle+".ini");
    std::vector<std::string> keys;
    if(!infile.fail()){
        std::cout << "File is open" << std::endl;
        while(getline(infile,str) && !found) {
            str = deleteComment(str);
            if(readOn) {
                if(str.find('[') == std::string::npos || (str.find(']') == std::string::npos)){
                    auto posZ = str.find('=');
                    str = str.substr(0,posZ);
                    if(!str.empty()) {
                        keys.push_back(std::move(str));
                    }
                }
                else {
                    readOn=false;
                    found = true;
                }
            }
            if(str=="["+section+"]") readOn = true;
        }
        if(keys.empty()) std::cout<< "I can't find this section"<< std::endl;
    }
    else std::cout<< "Error! the file doesn't exist in this path"<< std::endl;
    return std::move(keys);

}

std::vector<std::string> ReadWriteIni::readIni() {
    std::ifstream infile;
    std::string str;
    infile.open(pathFIle+".ini");
    std::vector<std::string> sections;
    if(!infile.fail()){
        std::cout << "File is open" << std::endl;
        while(getline(infile,str)) {
            std::cout<< str <<std::endl;
            auto posX=str.find('[');
            auto posY=str.find(']');
            if(( posX!= std::string::npos) && ( posY!= std::string::npos)){
                str = str.substr(posX+1,posY-posX-1);
                sections.push_back(std::move(str));
            }
        }
        if(sections.empty()) std::cout<< "I can't find any section"<< std::endl;
    }
    else std::cout<< "Error! the file doesn't exist in this path"<< std::endl;
    return std::move(sections);
}

const std::string &ReadWriteIni::getPathFIle() const {
    return pathFIle;
}

void ReadWriteIni::setPathFIle(const std::string &pathFIle) {
    ReadWriteIni::pathFIle = pathFIle;
}




std::string ReadWriteIni::deleteComment( std::string str){
    auto i = str.find(';');
    if(i != std::string::npos) {
        for( i=i-1 ; str[i]==' '; i-- ) {}
        str = str.substr(0,i+1);
    }

    return str;
}







