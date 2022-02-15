#ifndef QLSV_H //if not define
#define QLSV_H

#include <iostream>
#include <string>
#include <fstream>
#include "Question.h"

using namespace std;

class QLyQUES
{
private:
    Questions dsQues[300];
    int number_studetns = 0;

public:
    QLyQUES();
    void saveFile();
    void loadFile();
    void addQuestion();
    void listQuestion();
    void deletes();
    void editQuestion();
    void test();
    void printMenu();
    char getInputOneCharacter();
};

#endif


