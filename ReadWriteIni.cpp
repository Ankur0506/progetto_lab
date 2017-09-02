//
// Created by Ankur Meozzi on 21/08/2017.
//

#include "ReadWriteIni.h"

#include <iostream>
#include <utility>


void ReadWriteIni::writeIni(std::string section, std::string comment) {
    if( !comment.empty()) comment = " ;"+comment;// if comment isn't null we ad the marker ;
    bool found=false;
    for( int i=0; i<file.size() && !found;i++) {
        file[i][0]=deleteComment(file[i][0]);
        if(file[i][0]=='['+section+']') {
            file[i][0]=file[i][0]+std::move(comment);
            found = true;
        }// stop the cycle if we find the section
    }// we cheack if section dosen't exist already
    if(!found){// we write the new section at the end with push_back
        std::deque<std::string> newSection;// creation of the vector
        newSection.push_back('['+std::move(section)+']'+std::move(comment));// the first one is the name of the section
        file.push_back(newSection);
    }
    else std::cout<<"Section already exist. Comment changed"<<std::endl;
}

void ReadWriteIni::writeIni( std::string section, std::string key, std::string value, std::string comment) {
    if( !section.empty() && !key.empty()) {// we cheack not null value for section and key
        std::string str;
        bool written = false;// with this variable we can discern if at the end we have written value
        if( !comment.empty()) comment = " ;"+comment;// if comment isn't null we ad the marker ;
        int i,k;// we declare because we need them also outside of cycle
        for ( i=0; i<file.size() && !written; i++) {
            auto posS= file[i][0].find("["+section+"]"); // searching the section int the string
            if( posS != std::string::npos ) {
                for ( k=1; k<file[i].size() ; k++) {
                    auto posK= file[i][k].find(key);// searching the key int the string
                    if( posK != std::string::npos) {
                        str = file[i][k];// we need to copy in a local variable if we won't to no delete comment
                        auto posEq= file[i][k].find("=");
                        str = str.substr(0,posEq);
                        file[i][k] = std::move(str)+"="+std::move(value)+std::move(comment);
                        written = true;
                    }
                }
                if(file[i].size()==k && !written) {// if we don't find the key int the section we write it
                    file[i].push_back(std::move(key)+"="+std::move(value)+std::move(comment));
                    written = true;
                }
            }
        }
        if(!written ) {// if we never get in in any section we have to write a new section and the key
            std::deque<std::string> newSection;
            newSection.push_back('['+std::move(section)+']');
            newSection.push_back(std::move(key)+"="+std::move(value)+std::move(comment));
            file.push_back(newSection);
        }
    }
    else std::cout<<" section or key null"<<std::endl;
}

bool ReadWriteIni::cheackSection(const std::string &str) const {
    return str.find('[') == std::string::npos && str.find(']') == std::string::npos;
}

void  ReadWriteIni::readFile() {
    std::ifstream infile;
    std::deque<std::string> keys;
    infile.open(pathFIle);
    if(!infile.fail()) {
        readFileRicorsivo(infile, keys);
        infile.close();
    }
}

void ReadWriteIni::readFileRicorsivo( std::ifstream &infile, std::deque<std::string> &keys) {
    std::string str;
    if(getline(infile, str)) {
        readFileRicorsivo(infile, keys);
        if(!str.empty())  {// we delete empty line
            keys.push_front(str);
            if(!cheackSection(str)) {
                file.push_front(keys);
                keys.erase(keys.begin(),keys.end());
            }
        }
    }
}

void ReadWriteIni::writeIni(std::string section, std::string key, float value, std::string comment) {
    writeIni(std::move(section), std::move(key),std::to_string(value), std::move(comment));
}

void ReadWriteIni::writeIni(std::string section, std::string key, int value, std::string comment) {
    writeIni(std::move(section), std::move(key),std::to_string(value), std::move(comment));
}

void ReadWriteIni::writeIni(std::string section, std::string key, double value, std::string comment) {
    writeIni(std::move(section), std::move(key),std::to_string(value), std::move(comment));
}


std::string ReadWriteIni::readIni(const std::string &section, const std::string &key) {
    std::string str;
    std::string value;
    for (auto i : file) {
        auto posS= i[0].find("["+section+"]");
        if( posS != std::string::npos ) {
            for (int k = 1; k < i.size(); k++) {
                auto posK= i[k].find(key);
                if( posK != std::string::npos) {
                    str = i[k];// we use str to no modify file
                    str = deleteComment(str);
                    auto posEq = str.find('=');
                    value = str.substr(posEq+1);
                }
            }
        }
    }
    if( value.empty()) std::cout<<"value not found"<<std::endl;
    return std::move(value);
}

std::deque<std::string> ReadWriteIni::readIni(const std::string &section) {
    std::deque<std::string> keys;
    for (auto i : file) {
        auto posS= i[0].find("["+section+"]");
        if( posS != std::string::npos ) {
            for (int k = 1; k < i.size(); k++) {
                auto posEq = i[k].find('=');
                keys.push_back(i[k].substr(0,posEq));
            }
        }
    }
    if( keys.empty()) std::cout<<"I can't find this section or section without keys"<<std::endl;
    return move(keys);
}

std::deque<std::string> ReadWriteIni::readIni() {
    std::deque<std::string> sections;
    for (auto i : file) {
        auto posX = i[0].find('[');
        auto posY = i[0].find(']');
        sections.push_back(i[0].substr(posX+1,posY-1));
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

void ReadWriteIni::writeAll() {
    std::ofstream outfile;
    outfile.open(pathFIle);
    int i,k;
    for ( i=0; i<file.size() ; i++) {
        if(i!=0) outfile<<"\n";
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
    writeAll();
    file.erase(file.begin(),file.end());
    ReadWriteIni::pathFIle = pathFIle;
    readFile();
}

