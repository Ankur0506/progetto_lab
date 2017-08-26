//
// Created by Ankur Meozzi on 21/08/2017.
//

#ifndef PROGETTO_LAB_WRITEINI_H
#define PROGETTO_LAB_WRITEINI_H

#include <string>
#include <fstream>
#include <list>

class ReadWriteIni {
public:
    explicit ReadWriteIni(std::string address = "") : pathFIle(std::move(address)) {};
    ~ReadWriteIni() = default;




    void writeIni( std::string section,std::string key, float value);
    void writeIni( std::string section,std::string key, int value);
    void writeIni( std::string section,std::string key, double value);
    void writeIni( std::string section,std::string key, std::string value);
    void writeIni( std::string section);

    std::string readIni (std::string section,std::string key, std::string error = "error");
    std::list<std::string> readIni (std::string section);
    std::list<std::string> readIni ();

    const std::string &getPathFIle() const;
    void setPathFIle(const std::string &pathFIle);

private:
    std::string pathFIle;
};


#endif //PROGETTO_LAB_WRITEINI_H
