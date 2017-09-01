//
// Created by Ankur Meozzi on 20/08/2017.
//

#include "gtest/gtest.h"
#include "../ReadWriteIni.h"



class TestIniSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        file.setPathFIle("prova.ini");
        file.writeIni("Sezione1","versione","1");
        file.writeIni("Sezione2","versione","2");
    }

    ReadWriteIni file;
};

TEST_F(TestIniSuite, TestSuitPath) {
    ASSERT_STREQ((file.getPathFIle()).c_str(), "prova.ini") << "path different from the one set in the suit";
}

TEST_F(TestIniSuite, TestReading) {
    ASSERT_STREQ((file.readIni("Sezione1","versione")).c_str(),"1")<< "impossible to read the key of first section";
    ASSERT_STREQ((file.readIni("Sezione2","versione")).c_str(),"2")<< "impossible to read the key of second section";
    auto sections = file.readIni();
    ASSERT_STREQ((sections[1]).c_str(),"Sezione2");
    auto keys = file.readIni("Sezione1");
    ASSERT_STREQ((keys[0]).c_str(),"versione");
}

TEST_F(TestIniSuite, TestWriting) {
    file.writeIni("Sezione1","name","player1");
    file.writeIni("Sezione1","LV",13);
    file.writeIni("Sezione1","hp",122);

    EXPECT_EQ(std::stoi(file.readIni("Sezione1","hp")),122);
    EXPECT_STREQ(file.readIni("Sezione1","name").c_str(),"player1");
    EXPECT_EQ(std::stoi(file.readIni("Sezione1","LV")),13);

    file.writeIni("Sezione3","name","player3");
    file.writeIni("Sezione3","speed", static_cast<float>(16/3));
    file.writeIni("Sezione3","strength",18.9);
    file.writeIni("Sezione3","pro user",true);
    EXPECT_STREQ((file.readIni("Sezione3","name")).c_str(),"player3");
    EXPECT_EQ(std::stof(file.readIni("Sezione3","speed")),16/3)<< " problems with value of type float";
    EXPECT_EQ(std::stod(file.readIni("Sezione3","strength")),18.9)<< " problems with value of type double";
    EXPECT_EQ(file.readIni("Sezione3","name"),"player3");

    file.writeIni("Sezione2","defense",58683.561);
    file.writeIni("Sezione1","fortune",-34.56);
    EXPECT_EQ(std::stod(file.readIni("Sezione2","defense")),58683.561)<<"writing to a previous section not fulfilled";
    EXPECT_EQ(std::stod(file.readIni("Sezione1","fortune")),-34.56);

    auto sections = file.readIni();
    EXPECT_STREQ((sections[1]).c_str(),"Sezione2");
    auto keys = file.readIni(sections[2]);
    EXPECT_EQ(keys[1],"speed")<< "function readIni(section) doesn't read keys of section ";
    EXPECT_EQ(keys.size(),4);
    EXPECT_TRUE(std::stoi(file.readIni("Sezione3",keys[3])))<< " problems to write or read bool type"
                        "\n remind! we use implicit cast to int in order to manage bool type";


    file.writeIni("Sezione4");
    sections = file.readIni();
    EXPECT_STREQ((sections[3]).c_str(),"Sezione4")<< " function writeIni for a section doesn't work ";
}

TEST(TestIni, TestPath) {
    ReadWriteIni file;
    file.setPathFIle("library.ini");
    ASSERT_STREQ((file.getPathFIle()).c_str(),"library.ini")<< "path different from the one set in the suit";
    file.writeIni("book","title","A book");
    file.writeIni("book","pages",156);
    file.writeIni("book","first publication",1999);
    file.setPathFIle("Album.ini");
    ASSERT_STREQ((file.getPathFIle()).c_str(),"Album.ini")<< "problems with setting path function";
    file.writeIni("photo","size", "1024x748");
    file.writeIni("photo","flash",false);
    file.writeIni("photo","iso",389);
    EXPECT_STREQ((file.readIni("photo","size")).c_str(),"1024x748")<< "problem with changing path";
    EXPECT_TRUE(std::stoi(file.readIni("photo","flash")));
    EXPECT_STRNE((file.readIni("book","title")).c_str(),"A book")<<"the content of the previous file wasn't erased ";
    file.setPathFIle("prova.ini");
    EXPECT_EQ(std::stoi(file.readIni("book","pages")),156)<< "previous file content was deleted or never written"
                        "after it was closed";
}

TEST_F(TestIniSuite, TestOverWriting) {
    file.writeIni("Sezione1","class","1A");
    file.writeIni("Sezione1","passed",false);
    file.writeIni("Sezione1","mark",16.3);
    file.writeIni("Sezione1","class","2A");
    file.writeIni("Sezione1","passed",true);
    file.writeIni("Sezione1","mark",27);
    EXPECT_STREQ((file.readIni("Sezione1","class")).c_str(),"2A")<< "key isn't overwritten";
    EXPECT_TRUE(std::stoi(file.readIni("Sezione1","passed")))<< "problems to overwritten bool";
    EXPECT_EQ(std::stoi(file.readIni("Sezione1","mark")),27);
}

TEST(TestIni, TestComments) {
    ReadWriteIni f("testComment");
    f.writeIni("system","ios","windows");
    f.writeIni("internet access","name","My internet");
    f.writeIni("internet access","password","******", "not visible");
    f.writeIni("system","version",5.7,"Name version: next one");
    f.writeIni("system","ram","4Gb","system required at least 2Gb");

    f.writeIni("internet access","proxy","");
    f.writeIni("system","processor","Intel");
    f.writeIni("internet access","theme",3);
    f.writeIni("Memory","ROM memory");
    f.writeIni("system","new version available");
    EXPECT_STREQ((f.readIni("internet access","password")).c_str(),"******")<< "maybe comment could be added";
    EXPECT_STREQ((f.readIni("system","ram")).c_str(),"4Gb");
    EXPECT_EQ(std::stod(f.readIni("system","version")),5.7);
    auto sections = f.readIni();
    EXPECT_STREQ((sections[0]).c_str(),"system")<< "maybe comment could be added to section";
    EXPECT_STREQ((sections[2]).c_str(),"Memory");
}