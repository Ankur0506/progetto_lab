//
// Created by Ankur Meozzi on 21/08/2017.
//

#include "ReadWriteIni.h"

#include <iostream>

void ReadWriteIni::writeIni(std::string section) {
    auto sections = readIni();
    bool found=false;
    for( int i=0; i<sections.size() && !found;i++) {
        if(sections[i]==section) found = true;
    }
    if(!found){
        std::ofstream outfile;
        outfile.open(pathFIle+".ini", std::ios::app);
        outfile<<"\n["+section+"]\n";
        outfile.close();
    }
    else std::cout<<"Section already exist"<<std::endl;
}

void ReadWriteIni::writeIni(const std::string &section, const std::string &key, const std::string &value, std::string comment) {

    bool found = false;;
    std::vector<std::string> file = readFile();
    std::ofstream outfile;
    std::string str;
    outfile.open(pathFIle+".ini");

    if( !comment.empty()) comment = " ;"+comment;

    bool rightSection = false;
    int i;
    //std::cout<<"file size "<<file.size()<<std::endl;
    for ( i=0; i<file.size() && !found; i++) {
        str = file[i];
        str = deleteComment(str);
        writeKey(key, value, comment, file, rightSection, i, found, outfile, str);
        if( !cheackSection(str)) outfile<<"\n";
        if(!found)outfile<< file[i]+"\n";
        if(str=="["+section+"]") {
            rightSection  = true;
        }
    }
    for ( i; i<file.size(); i++) outfile<< file[i]+"\n";
    if(!found) {
        std::cout<<found<<std::endl;
        outfile<<"\n["+section+']'+"\n";
        outfile<<key+"="+value+comment+"\n";
    }

    for( i=0;i<file.size(); i++) {

    }

    outfile.close();
}

void ReadWriteIni::writeKey(const std::string &key, const std::string &value, const std::string &comment, const std::vector<std::string> &file, bool rigthSection, int i, bool &found,
                            std::ofstream &outfile, std::string &str) const {
    if(rigthSection) {
            if(cheackSection(str) && file.size() - 1 > i){
                auto posZ = str.find('=');
                str= str.substr(0,posZ);
                if( key == str) {
                    //std::cout<<str<<std::endl;
                    outfile<<str+"="+value+comment+"\n";
                    found = true;
                }
            }
            else {
                std::cout<<"branch else "<<file[i]<<std::endl;
                outfile<< key+"="+value+comment+"\n";
                outfile<< file[i]+"\n";
                found = true;
            }
        }
}

bool ReadWriteIni::cheackSection(const std::string &str) const {
    return str.find('[') == std::string::npos && str.find(']') == std::string::npos;
}

std::vector<std::string> ReadWriteIni::readFile() const {
    std::ifstream infile;
    infile.open(pathFIle + ".ini");
    std::__cxx11::string str;
    std::vector<std::__cxx11::string> file;
    if(!infile.fail()) {
        while(getline(infile,str)) {
            std::cout<<str<<std::endl;
            if(!str.empty())  {
                std::cout<<str<<std::endl;
                file.push_back(str);}
        }
        infile.close();
    }
    return file;
}

void ReadWriteIni::writeIni(std::string section, std::string key, float value) {
    writeIni(section, key,std::to_string(value));
}

void ReadWriteIni::writeIni(std::string section, std::string key, int value) {
    writeIni(section, key,std::to_string(value));
}

void ReadWriteIni::writeIni(std::string section, std::string key, double value) {
    writeIni(section,key,std::to_string(value));
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
        infile.close();
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
        infile.close();
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
        infile.close();
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







