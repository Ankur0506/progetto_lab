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


TEST_F(TestIniSuite, TestReading) {
    std::string  s= file.readIni("Sezione2","versione");
    const char * c = s.c_str();
    //std::cout<<file.readIni("Sezione2","versione")<<std::endl;
    ASSERT_STREQ((file.readIni("Sezione2","versione")).c_str(),"error")<< "";

}

