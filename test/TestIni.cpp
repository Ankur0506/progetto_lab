//
// Created by Ankur Meozzi on 20/08/2017.
//

#include "gtest/gtest.h"
#include "../ReadWriteIni.h"
#include "../"


class TestIniSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        file.setPathFIle("prova.ini");
        file.writeIni("Sezione1","versione","1");
        file.writeIni("Sezione2","versione","2");
    }

    ReadWriteIni file;
};


TEST_F(TestIniSuite, TestReading) {
    ASSERT_EQ("prova.ini",file.getPathFIle()) << "functions setPathFIle and/or getPathFIle doesn't set or read file path";
    ASSERT_NE(nullptr,file.readIni("Sezione1","versione", nullptr)) << "impossible to access Key";
}

