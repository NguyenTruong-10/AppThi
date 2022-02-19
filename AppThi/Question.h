#ifndef SINHVIEN_H // if not define
#define SINHVIEN_H

#include <iostream>
#include <string>

using namespace std;

class Questions
{
private:
  string Id;
  string thread;
  string answer_A, answer_B, answer_C, answer_D, choice_answer,right_answer;
  // Date ngaySinh;

public:
  Questions();
  Questions(string, string, string, string, string,string,string,string);
  void setID(string);
  string getID();
  void setThread(string);
  string getThread();

  void setAnswer_A(string);
  string getAnswer_A();
  
  void setAnswer_B(string);
  string getAnswer_B();
  
  void setAnswer_C(string);
  string getAnswer_C();
  
  void setAnswer_D(string);
  string getAnswer_D();
  
  void setChoiceAnswer(string);
  string getChoiceAnswer();
  
  void setRightAnswer(string);
  string getRightAnswer();
  
  void print_Question();
  void print_Choice();
};

#endif
