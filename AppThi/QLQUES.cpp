#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include "QLQUES.h"
#include "Question.h"

using namespace std;

QLyQUES::QLyQUES()
{
    loadFile();
}
void QLyQUES::saveChoie()
{
    fstream f1("D:/BAI_TAP/AppThi/Choice_Answer.txt", ios::out);
    f1 << number_question << endl;
    for (int i = 0; i < number_question; i++)
    {
        f1 << dsQues[i].getChoiceAnswer() << endl;
    }
    f1.close();
}
void QLyQUES::loadChoice()
{
    fstream f1("D:/BAI_TAP/AppThi/Choice_Answer.txt", ios::in);
    for (int i = 0; i < number_question + 1; i++)
    {
        string choice_ans;
        f1 >> choice_ans;
        if (i > 0)
        {
            dsQues[i - 1].setChoiceAnswer(choice_ans);
        }
    }
    f1.close();
}
void QLyQUES::saveFile()
{
    fstream f1("D:/BAI_TAP/AppThi/Question.txt", ios::out);
    f1 << number_question << endl;
    for (int i = 0; i < number_question; i++)
    {
        f1 << dsQues[i].getID() << endl;
        f1 << dsQues[i].getThread() << endl;
        f1 << dsQues[i].getAnswer_A() << endl;
        f1 << dsQues[i].getAnswer_B() << endl;
        f1 << dsQues[i].getAnswer_C() << endl;
        f1 << dsQues[i].getAnswer_D() << endl;
        f1 << dsQues[i].getRightAnswer() << endl;
    }
    f1.close();
}

void QLyQUES::loadFile()
{
    fstream f1("D:/BAI_TAP/AppThi/Question.txt", ios::in);
    f1 >> number_question;
    for (int i = 0; i < number_question; i++)
    {
        string idQues;
        string question, ans_A, ans_B, ans_C, ans_D, right_ans;
        f1 >> idQues;
        f1.ignore();
        getline(f1, question);
        f1 >> ans_A;
        f1 >> ans_B;
        f1 >> ans_C;
        f1 >> ans_D;
        f1 >> right_ans;

        dsQues[i].setID(idQues);
        dsQues[i].setThread(question);
        dsQues[i].setAnswer_A(ans_A);
        dsQues[i].setAnswer_B(ans_B);
        dsQues[i].setAnswer_C(ans_C);
        dsQues[i].setAnswer_D(ans_D);
        dsQues[i].setRightAnswer(right_ans);
    }
    f1.close();
}
// int idQues = 0;

void QLyQUES::addQuestion()
{
    string question, right_ans, ans_A, ans_B, ans_C, ans_D;
    Questions ques;
    string idQues;
    
    cout << "Ma cau hoi: ";
    cin.ignore();
    getline(cin, idQues);
    ques.setID(idQues);

    cout << "De bai: ";
    cin.ignore();
    getline(cin, question);
    ques.setThread(question);

    cout << "Dap An 1: ";
    getline(cin, ans_A);
    ques.setAnswer_A(ans_A);

    cout << "Dap An 2: ";
    getline(cin, ans_B);
    ques.setAnswer_B(ans_B);

    cout << "Dap An 3: ";
    getline(cin, ans_C);
    ques.setAnswer_C(ans_C);

    cout << "Dap An 4: ";
    getline(cin, ans_D);
    ques.setAnswer_D(ans_D);

    cout << "Dap an dung(Chi duoc luu duoi dang A B C D): ";
    cin >> right_ans;
    ques.setRightAnswer(right_ans);

    dsQues[number_question] = ques;
    // dsQues[number_question].setID(number_question+1);
    // dsQues[number_question].setThread(question);
    // dsQues[number_question].setAnswer_A(ans_A);
    // dsQues[number_question].setAnswer_B(ans_B);
    // dsQues[number_question].setAnswer_C(ans_C);
    // dsQues[number_question].setAnswer_D(ans_D);
    // dsQues[number_question].setRightAnswer(right_ans);
    number_question++;
    cout << "Da them thanh cong.\n";
    saveFile();
}

void QLyQUES::listQuestion()
{
    if (number_question > 0)
    {
        for (int i = 0; i < number_question; i++)
        {
            cout << "Cau " << i + 1 << ": ";
            dsQues[i].print_Question();
            cout << "  " << endl;
            // loadFile();
        }
    }
    else
    {
        cout << "\nDanh sach sinh vien trong.\n";
    }
}

void QLyQUES::deletes()
{
    if (number_question == 0)
    {
        cout << "Danh sach cau hoi hien dang trong, vui long nhap du lieu\n";
    }
    else
    {
        cout << "Danh sach cau hoi : \n";
        for (int i = 0; i < number_question; i++)
        {
            cout << i + 1 << ". "
                 << "Ma cau hoi: ";
            cout << dsQues[i].getID() << "\n";
        }
        string del_id;
        int index = -1;

        cout << "Nhap ma cau hoi ban can xoa: ";
        cin >> del_id;
        for (int i = 0; i < number_question; i++)
        {
            if (dsQues[i].getID() == del_id)
            {
                index = i;
                // cout << dsQues[i].getID() << endl;
                // cout << index << endl;
                // cout << i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "Ma cau hoi " << del_id << " khong co trong danh sach cau hoi.\n";
        }
        for (int i = index; i < number_question - 1; i++)
        {
            dsQues[i] = dsQues[i + 1];
            cout << dsQues[i].getID();
        }
        number_question--;
        cout << setw(30) << "DONE!\n";
        saveFile();
    }
}

void QLyQUES::editQuestion()
{
    string question, right_ans, ans_A, ans_B, ans_C, ans_D;
    string chon1;
    int edit;
    cout << "Danh sach cau hoi hien co: \n";
    for (int i = 0; i < number_question; i++)
    {
        cout << (i + 1) << "."
             << "Ma cau hoi: ";
        cout << dsQues[i].getID() << "\n";
    }

    cout << "Nhap ma cau hoi: ";
    string ma;
    cin >> ma;
    for (int i = 0; i < number_question; i++)
    {
        if (dsQues[i].getID() == ma)
        {
            ma = i;
            cout << " " << endl;
            cout << "Thong tin hien tai cua cau hoi: \n";
            cout << "Ma cau: ";
            dsQues[i].print_Question();
            cout << "hihihi" << endl;

            cout << "Moi chon thong tin can sua: \n";
            cout << " 1.Sua noi dung \n";
            cout << " 2.Sua dap an \n";
            cout << " 3.Sua dap an dung \n";
            cout << "Ban chon: ";
            cin >> edit;
            switch (edit)
            {
            case 1:
                ma = i;
                cin.ignore();
                cout << "Moi nhap noi dung moi: ";
                getline(cin, question);
                dsQues[i].setThread(question);
                break;
            case 2:
                cout << "Moi nhap dan an can thay doi: \n";
                cout << " 1.Dap an A \n";
                cout << " 2.Dap an B \n";
                cout << " 3.Dap an C \n";
                cout << " 4.Dap an D \n";
                cout << "Dap an ban can sua: ";
                int chon1;
                cin >> chon1;
                if (chon1 == 1)
                {
                    ma = i;
                    cin.ignore();
                    cout << "Moi nhap Dap an moi: ";
                    getline(cin, ans_A);
                    dsQues[i].setAnswer_A(ans_A);
                }
                else if (chon1 == 2)
                {
                    ma = i;
                    cin.ignore();
                    cout << "Moi nhap Dap an moi: ";
                    getline(cin, ans_B);
                    dsQues[i].setAnswer_B(ans_B);
                }
                else if (chon1 == 3)
                {

                    ma = i;
                    cin.ignore();
                    cout << "Moi nhap Dap an moi: ";
                    getline(cin, ans_B);
                    dsQues[i].setAnswer_C(ans_B);
                }
                else if (chon1 == 4)
                {
                    ma = i;
                    cin.ignore();
                    cout << "Moi nhap Dap an moi: ";
                    getline(cin, ans_D);
                    dsQues[i].setAnswer_D(ans_D);
                }
                break;

            case 3:
                ma = i;
                cin.ignore();
                cout << "Moi nhap Dap an dung: ";
                getline(cin, right_ans);
                dsQues[i].setRightAnswer(right_ans);
                break;
            }
        }
        cout << "thanh cong \n";
        saveFile();
    }
}

char QLyQUES::getInputOneCharacter()
{
    char choice;
    choice = getchar();
    while (choice == '\n')
    {
        choice = getchar();
    }
    return choice;
}
int QLyQUES::randomNumber(int min, int max, int previousNumber)
{
    int result = (rand() % (max - min + 1)) + min;
    while (result == previousNumber)
    {
        result = (rand() % (max - min + 1)) + min;
    }
    return result;
}
void QLyQUES::test()
{
    string choice_ans;
    int score = 0, do_test;
    int index = -1;
    cout << "1: Lam bai thi toan "<<endl;
    cout << "Moi ban chon: ";
    cin >> do_test;
    if (do_test != 1)
    {
        cout << "Ban chon khong dung.";
        exit(0);
    }
    if (number_question > 0)
    {
        cin.ignore();
        int previousNumber = 0;
        for (int i = 0; i < 5; i++)
        {
            cout << " " << endl;
            cout << "Cau " << i + 1 << ": ";
            int a = randomNumber(0, 5, previousNumber);
             index = a;
            previousNumber = a;
            dsQues[i].print_Question();
            cout << "Dap an cau " << i + 1 << ": ";
            getline(cin, choice_ans);
            dsQues[i].setChoiceAnswer(choice_ans);
            if (dsQues[i].getChoiceAnswer() == dsQues[i].getRightAnswer())
            {
                score = score + 2;
            }
            //            else
            //            {
            //                cout << "ban dang o day0";
            //            }
        }
    }
    else
    {
        cout << "\nDanh sach cau hoi trong.\n";
    }
    saveChoie();

    for (int i = 0; i < 5; i++)
    {
        cout << " " << endl;
        cout << "Dap an ban chon " << i + 1 << ": ";
        dsQues[i].print_Choice();
    }
    cout << "Diem cua ban la: " << score << endl;
}

void QLyQUES::login()
{
    string admin, student;
    string pass;
    do
    {

//        cout << "Dang Nhap: ";
//        cin >> admin;
//        cout << "PassWord: ";
//        cin >> pass;
              admin = pass = "student";
        int do_test;
        if (admin == "admin" && pass == "admin")
        {
            printMenu();
        }
        else if (admin == "student" && pass == "student")
        {
            test();
            break;
        }
        else if (admin == "admin" && pass == "student")
        {
            cout << "Mat khau khong dung"<<endl;
        }
         else if (admin == "student" && pass == "admin")
        {
            cout << "Mat khau khong dung"<<endl;
        }
        else
        {
            cout << "Tai khoan khong ton tai" << endl;
            cout << "Moi nhap lai." << endl;
        }
    } while (admin != "admin" && pass != "admin" || admin != "student" && pass != "student" || admin == "admin" && pass == "student" || admin == "student" && pass == "admin");
}

void QLyQUES::printMenu()
{
LABEL1:
    cout << "\n\t\t\t+-------------------------------------------+\n";
    cout << "\t\t\t|             Quan Ly Sinh Vien               |\n";
    cout << "\t\t\t+---------------------------------------------+\n";
    cout << "\t\t\t|1. Them cau hoi      | |  2. Sua cau hoi     |\n";
    cout << "\t\t\t|3. Xoa cau hoi       | |  4.Lam de thi       |\n";
    cout << "\t\t\t|5. Xem de            | |  6.Thoat            |\n";
    cout << "\t\t\t+---------------------------------------------+\n";
    char chon;
    char select;
    cout << "Moi chon chuc nang: ";
    cin >> chon;
    // chon = getInputOneCharacter();
    while (chon <= '6' && chon > '0')
    {
        switch (chon)
        {
        case '1':
            cout << "\n\t\t|=======================================================================================|\n";
            cout << setw(64) << "THEM CAU HOI\n";
            addQuestion();
            listQuestion();
            cout << "\t\t|=======================================================================================|\n";
            break;
        case '2':
            cout << "\t\t|=======================================================================================|\n";
            cout << setw(64) << "SUA CAU HOI\n";
            editQuestion();
            cout << "\t\t|=======================================================================================|\n";
            break;
        case '3':
            cout << "\t\t|======================================================================================|\n";
            cout << setw(64) << "XOA CAU HOI\n";
            deletes();
            cout << "\n\t\t|=======================================================================================|\n";
            break;
        case '4':
            cout << "\t\t|=======================================================================================|\n";
            cout << setw(64) << "LAM DE\n";
            test();
            cout << "\t\t|=======================================================================================|\n";
            break;
        case '5':
            cout << "\t\t|=======================================================================================|\n";
            cout << setw(64) << "XOA THONG TIN SINH VIEN\n";
            listQuestion();
            cout << "\t\t========================================================================================|\n";
            break;
        case '6':
            exit(0);
            break;
        default:
            break;
        }
        cout << "\n--------------------------------------------\n";
        cout << "| Ban co muon tiep tuc ?                   |\n";
        cout << "| - Van tiep tuc (press y, Y)              |\n";
        cout << "| - Thoat chuong trinh. (press n, N        |\n";
        cout << "| - Don sach ! (press c, C)                |\n";
        cout << "--------------------------------------------";
        cout << "\nLua chon cua ban:";
        select = getInputOneCharacter();
        if (select == 'y' || select == 'Y')
        {
            goto LABEL1;
        }
        else if (select == 'n' || select == 'N')
        {
            cout << "Chuong trinh ket thuc...";
            break;
        }
        else if (select == 'c' || select == 'C')
        {
            system("@cls||clear");
            login();
        }
    }
}
