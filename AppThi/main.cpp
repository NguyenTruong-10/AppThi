#include <iostream>
#include <string>
#include <fstream>
#include "Question.h"
#include "QLQUES.h"

using namespace std;
// void load(){
//     fstream f1("D:/BAI_TAP/AppThi/Question.txt", ios::in);
//     int number_question;
//     f1 >>number_question;
//     Questions::lastId = number_question;
//     f1.close();
// }
int main()
{
    // load();
    QLyQUES quanLy;
    quanLy.login();
	
    return 0;
}

