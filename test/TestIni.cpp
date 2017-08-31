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

TEST_F(TestIniSuite, TestPath) {
    ASSERT_STREQ((file.getPathFIle()).c_str(),"prova.ini")<< "path different from the one set in the suit";
    file.setPathFIle("file.ini");
    ASSERT_STREQ((file.getPathFIle()).c_str(),"file.ini")<< "problems with setting path function";
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
    EXPECT_EQ(std::stof(file.readIni("Sezione3","speed")),16/3);
    EXPECT_EQ(std::stod(file.readIni("Sezione3","strength")),18.9);
    EXPECT_EQ(file.readIni("Sezione3","name"),"player3");

    auto sections = file.readIni();
    EXPECT_STREQ((sections[1]).c_str(),"Sezione2");
    auto keys = file.readIni(sections[2]);
    EXPECT_EQ(keys[1],"speed");
    EXPECT_EQ(keys.size(),4);
    EXPECT_TRUE(std::stoi(file.readIni("Sezione3",keys[3])));

    file.writeIni("Sezione2","defense",58683.561);
    file.writeIni("Sezione1","fortune",-34.56);
    EXPECT_EQ(std::stod(file.readIni("Sezione2","defense")),58683.561);
    EXPECT_EQ(std::stod(file.readIni("Sezione1","fortune")),-34.56);
}