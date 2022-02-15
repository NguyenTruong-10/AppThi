#include <iostream>
#include <string>
#include <iomanip>
#include "Question.h"

using namespace std;

Questions::Question()
{
}
Questions::Question(int Id, string thread, string answer_A, string answer_B, string answer_C, string answer_D, string choice_answer, string right_answer)
{
    this->Id = Id;
    this->thread = thread;
    this->answer_A = answer_A;
    this->answer_B = answer_B;
    this->answer_C = answer_C;
    this->answer_D = answer_D;
    this->choice_answer = choice_answer;
    this->right_answer = right_answer;
}

void Questions::setID(int ID)
{
    this->Id = Id;
}
int Questions::getID()
{
    return Id;
}

void Questions::setThread(string thread)
{
    this->thread = thread;
}
string Questions::getThread()
{
    return thread;
}

// dap an a
void Questions::setAnswer_A(string answer_A)
{
    this->answer_A = answer_A;
}
string Questions::getAnswer_A()
{
    return answer_A;
}

// dap an b
void Questions::setAnswer_B(string answer_B)
{
    this->answer_B = answer_B;
}
string Questions::getAnswer_B()
{
    return answer_B;
}

// dap an c
void Questions::setAnswer_C(string answer_C)
{
    this->answer_C = answer_C;
}
string Questions::getAnswer_C()
{
    return answer_C;
}

// dap an d
void Questions::setAnswer_D(string answer_D)
{
    this->answer_D = answer_D;
}
string Questions::getAnswer_D()
{
    return answer_D;
}
// Lua chon dap an
void Questions::setChoiceAnswer(string choice_answer)
{
    this->choice_answer = choice_answer;
}
string Questions::getChoiceAnswer()
{
    return choice_answer;
}

//dap an dung
void Questions::setRightAnswer(string right_answer)
{
    this->right_answer = right_answer;
}
string Questions::getRightAnswer()
{
    return right_answer;
}

void Questions::print_Question(){
    cout<<getThread()<<endl;
    cout<<getAnswer_A()<<setw(7)<<getAnswer_B()<<setw(7)<<getAnswer_C()<<setw(7)<<getAnswer_D()<<getRightAnswer()<<endl;
}
// void Questions::setDate(Date ngaySinh)
// {
//     this->ngaySinh = ngaySinh;
// }
// Date Questions::getDate()
// {
//     return ngaySinh;
// }

// void Questions::print_Student()
// {
//     cout << setw(12) << getID() << setw(26) << getName() << setw(12) << getGender() << setw(13) << getDate() << setw(17) << getAdd() << endl;
// }
// bool Questions::check(string key){
//     size_t found = ID.find(key);
//     if(found != string::npos){
//         return true;
//     }
//      found = name.find(key);
//     if(found != string::npos){
//         return true;
//     }
//     found = address.find(key);
//     if(found != string::npos){
//         return true;
//     }
//      found = gender.find(key);
//     if(found != string::npos){
//         return true;
//     }
//      found = ngaySinh.ToString().find(key);
//     if(found != string::npos){
//         return true;
//     }
//     return false;

