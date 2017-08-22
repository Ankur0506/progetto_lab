//
// Created by Ankur Meozzi on 21/08/2017.
//

#ifndef PROGETTO_LAB_WRITEINI_H
#define PROGETTO_LAB_WRITEINI_H

#include <string>
#include <utility>

class ReadWriteIni {
public:
    explicit ReadWriteIni(std::string address = "") : pathFIle(std::move(address)) {};
    ~ReadWriteIni() = default;

    void writeIni( std::string section,std::string key, std::string value);
    std::string readIni (std::string section,std::string key, std::string error = "error");

    const std::string &getPathFIle() const;
    void setPathFIle(const std::string &pathFIle);

private:
    std::string pathFIle;
};


#endif //PROGETTO_LAB_WRITEINI_H
