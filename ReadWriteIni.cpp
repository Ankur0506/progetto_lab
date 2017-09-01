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
        outfile<<"\n["+section+"]\n";// separo la sezione con il blocco precedente
        outfile.close();
    }
    else std::cout<<"Section already exist"<<std::endl;
}

void ReadWriteIni::writeIni(const std::string &section, const std::string &key, const std::string &value, std::string comment) {
    if( !section.empty() && !key.empty()) {
        std::string str;
        bool written = false;
        if( !comment.empty()) comment = " ;"+comment;
        int i,k;
        for ( i=0; i<file.size() && !written; i++) {
            auto posS= file[i][0].find("["+section+"]");
            std::cout<<file[i][0]<<std::endl;
            if( posS != std::string::npos ) {
                for ( k=1; k<file[i].size() ; k++) {
                    auto posK= file[i][k].find(key);
                    //std::cout<<file[i][k];
                    if( posK != std::string::npos) {
                        str = file[i][k];
                        str = deleteComment(str);
                        file[i][k] = str+"="+value+comment;
                        written = true;
                    }
                }
                if(file[i].size()==k) {
                    file[i].push_back(key+"="+value+comment);
                    written = true;
                }
            }
        }
        if(!written ) {
            std::vector<std::string> newSection;
            newSection.push_back('['+section+']');
            newSection.push_back(key+"="+value+comment);
            file.push_back(newSection);
        }
    }
    else std::cout<<" section or key null"<<std::endl;
}

bool ReadWriteIni::cheackSection(const std::string &str) const {
    return str.find('[') == std::string::npos && str.find(']') == std::string::npos;
}

std::vector< std::vector<std::string> >  ReadWriteIni::readFile() const {
    std::ifstream infile;
    std::vector<std::string> keys;
    infile.open(pathFIle + ".ini");
    std::string str;
    std::vector< std::vector<std::string> >  file;
    if(!infile.fail()) {
        while(getline(infile,str)) {
            if(!str.empty())  {
                if(!cheackSection(str)) {
                    file.push_back(keys);
                    keys.erase(keys.begin(),keys.end());
                }
                keys.push_back(str);}
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

    std::string value;
    for (auto &i : file) {
        auto posS= i[0].find("["+section+"]");
        if( posS != std::string::npos ) {
            for (int k = 1; k < i.size(); k++) {
                auto posK= i[k].find(key);
                if( posK != std::string::npos) {
                    str = file[i][k];
                    str = deleteComment(str);
                    file[i][k] = str+"="+value+comment;
                    written = true;
                }
            }
        }
    }
    if( value.empty()) std::cout<<"I can't find any section or section without keys"<<std::endl;
    return std::move(value);
}

std::vector<std::string> ReadWriteIni::readIni(const std::string &section) {
    std::vector<std::string> keys;
    for (auto &i : file) {
        auto posS= i[0].find("["+section+"]");
        if( posS != std::string::npos ) {
            for (int k = 1; k < i.size(); k++) {
                keys.push_back(i[k]);
            }
        }
    }
    if( keys.empty()) std::cout<<"I can't find any section or section without keys"<<std::endl;
    return move(keys);
}

std::vector<std::string> ReadWriteIni::readIni() {
    std::vector<std::string> sections;
    for (auto i : file) {
        sections.push_back(deleteComment(i[0]));
    }
    if( sections.empty()) std::cout<<"I can't find any section"<<std::endl;
    return move(sections);
}


std::string ReadWriteIni::deleteComment( std::string str){
    auto i = str.find(';');
    if(i != std::string::npos) {
        for( i=i-1 ; str[i]==' '; i-- ) {}
        str = str.substr(0,i+1);
    }

    return str;
}

void ReadWriteIni::wirteAll() {
    std::ofstream outfile;
    outfile.open(pathFIle+".ini");
    int i,k;
    for ( i=0; i<file.size() ; i++) {
        outfile<<"\n";
        for ( k=0; k<file[i].size() ; k++) {
            outfile<<file[i][k]+"\n";
        }
    }
    outfile.close();
}

const std::string &ReadWriteIni::getPathFIle() const {
    return pathFIle;
}

void ReadWriteIni::setPathFIle(const std::string &pathFIle) {
    wirteAll();
    file.erase(file.begin(),file.end());
    ReadWriteIni::pathFIle = pathFIle;
}


