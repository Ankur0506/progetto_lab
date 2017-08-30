//
// Created by Ankur Meozzi on 21/08/2017.
//

#ifndef PROGETTO_LAB_WRITEINI_H
#define PROGETTO_LAB_WRITEINI_H

#include <string>
#include <fstream>
#include <vector>

class ReadWriteIni {
public:
    explicit ReadWriteIni(std::string address = "") : pathFIle(std::move(address)) {};
    ~ReadWriteIni() = default;




    void writeIni( std::string section,std::string key, float value);
    void writeIni( std::string section,std::string key, int value);
    void writeIni( std::string section,std::string key, double value);
    void writeIni(const std::string &section, const std::string &key, const std::string &value, std::string comment="");
    void writeIni( std::string section);

    std::string readIni (const std::string &section,const std::string &key);
    std::vector<std::string> readIni (const std::string &section);
    std::vector<std::string> readIni ();

    const std::string &getPathFIle() const;
    void setPathFIle(const std::string &pathFIle);

private:
    std::string pathFIle;
    std::string deleteComment( std::string str);
    std::vector<std::string> readFile() const;

    void writeKey(const std::string &key, const std::string &value, const std::string &comment,
                  const std::vector<std::string> &file, bool rigthSection, int i, bool &found, std::ofstream &outfile,
                  std::string &str) const;

    bool cheackSection(const std::string &str) const;
};


#endif //PROGETTO_LAB_WRITEINI_H
