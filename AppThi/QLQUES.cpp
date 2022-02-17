#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
#include "QLQUES.h"
#include "Question.h"

using namespace std;

QLyQUES::QLyQUES()
{
    loadFile();
}
void QLyQUES::saveFile()
{
    fstream f1("D:/BAI_TAP/AppThi/Question.txt", ios::out);
    f1 << number_studetns << endl;
    for (int i = 0; i < number_studetns; i++)
    {
        f1 << dsQues[i].getID()<<endl;
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
    f1 >> number_studetns;
    for (int i = 0; i < number_studetns; i++)
    {
      int idQues;
        string question, ans_A, ans_B, ans_C, ans_D, right_ans;
        f1 >> idQues;
        f1.ignore();
        getline(f1, question);
        f1 >> ans_A;
        f1 >> ans_B;  
        f1 >> ans_C;
        f1 >> ans_D;  
        f1>>right_ans;
        // getline(f1, ans_A);
        // f1.ignore();
        // getline(f1, ans_B);
        // f1.ignore();
        // getline(f1, ans_C);
        //  f1.ignore();
        // getline(f1, ans_D);
        //    f1 >> ans_A;
        //    f1 >> ans_B;
        //    f1 >> ans_C;
        //    f1 >> ans_D;
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
    int idQues ;
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

    dsQues[number_studetns] = ques;
    number_studetns++;
    cout << "Da them thanh cong.\n";
    saveFile();
}

void QLyQUES::listQuestion()
{
    if (number_studetns > 0)
    {
        for (int i = 0; i < number_studetns; i++)
        {
        	cout<<"Cau "<<i+1<<": ";
            dsQues[i].print_Question();
            loadFile();
        }
    }
    else
    {
        cout << "\nDanh sach sinh vien trong.\n";
    }
}

// void QLyQUES::deletes()
//{
//     if (number_studetns == 0)
//     {
//         cout << "Danh sach sinh vien hien dang trong, vui long nhap du lieu\n";
//     }
//     else
//     {
//         string del_id, del_name;
//         int index = -1, choice;
//         cout << setw(40) << "1. Xoa ma sinh vien " << setw(30) << " 2. Xoa ten sinh vien" << endl;
//         cout << "Chon chuc nang ma ban muon: ";
//         cin >> choice;
//         if (choice == 1)
//         {
//             cout << "Nhap ma sinh vien ban can xoa: ";
//             cin >> del_id;
//             for (int i = 0; i < number_studetns; i++)
//             {
//                 if (dsSV[i].getID() == del_id)
//                 {
//                     index = i;
//                     break;
//                 }
//             }
//             if (index == -1)
//             {
//                 cout << "Ma sinh vien " << del_id << " khong co trong danh sach sinh vien.\n";
//                 return;
//             }
//         }
//         else
//         {
//             cout << "Nhap ten sinh vien ban can xoa: ";
//             cin.ignore();
//             getline(cin, del_name);
//             for (int i = 0; i < number_studetns; i++)
//             {
//
//                 if (dsSV[i].getName() == del_name)
//                 {
//                     index = i;
//                     break;
//                 }
//             }
//             if (index == -1)
//             {
//                 cout << "Ten sinh vien " << del_name << " khong co trong danh sach sinh vien.\n";
//                 return;
//             }
//         }
//         for (int i = 0; i < number_studetns; i++)
//         {
//             dsSV[i] = dsSV[i + 1];
//         }
//         number_studetns -= 1;
//         cout << setw(30) << "DONE!\n";
//         saveFile();
//     }
// }

// void QLyQUES::search()
// {
//     if (number_studetns == 0)
//     {
//         cout << "Danh sach sinh vien hien dang trong, vui long nhap du lieu\n";
//     }
//     else
//     {
//         string search;
//         cout << "Nhap tu khoa: ";
//         cin.ignore();
//         getline(cin, search);
//         cout << setw(16) << "Ma Sinh Vien" << setw(16) << "Ho va ten" << setw(20) << "Gioi Tinh" << setw(17) << "Ngay Sinh" << setw(17) << "Que Quan\n";
//         for (int i = 0; i < number_studetns; i++)
//         {
//             if (dsSV[i].check(search) == true)
//             {
//                 dsSV[i].print_Student();
//             }
//             if (dsSV[i].check(search) == false)
//             {
//                 cout << "Khong co ket qua";
//             }
//         }
//     }
// }

void QLyQUES::editQuestion()
{
//        int edit = 0;
//        if (number_studetns > 0)
//        {
//            int choice_1;
////          Date dateStu;
//            string idSv, nameSv, addSv, genSV;
//            string edit;
//            cout << "Nhap ten hoac ma sinh vien can sua: ";
//            cin.ignore();
//            getline(cin, edit);
//            if (number_studetns > 0){
    //            cout << "\n\t1.Sua ma sinh vien" << setw(29) << "2.Sua ten sinh vien\n";
    //            cout << "\t3.Sua ngay sinh sinh vien" << setw(28) << "4.Sua gioi tinh sinh vien\n";
    //            cout << "\t5.Sua que quan sinh vien" << setw(11) << "6.Thoat\n";
    //            cout << "\t\tMoi chon chuc nang: ";
    //            cin >> choice_1;
    //            switch (choice_1)
    //            {
    //            case 1://chinh sau ma
    //                cout << "\n"
    //                     << setw(16) << "Ma Sinh Vien" << setw(16) << "Ho va ten" << setw(20) << "Gioi Tinh" << setw(17) << "Ngay Sinh" << setw(17) << "Que Quan\n";
    //                for (int i = 0; i < number_studetns; i++)
    //                {
    //                    if (edit == dsSV[i].getName() || edit == dsSV[i].getID())
    //                    {
    //                        edit = i;
    //                        dsSV[i].print_Student();
    //                        cout << "Sua ma sinh vien: ";
    //                        cin.ignore();
    //                        getline(cin, idSv);
    //                        dsSV[i].setID(idSv);
    //                        cout << setw(60) << "\nSau khi sua\n";
    //                        cout << setw(16) << "Ma Sinh Vien" << setw(16) << "Ho va ten" << setw(20) << "Gioi Tinh" << setw(17) << "Ngay Sinh" << setw(17) << "Que Quan\n";
    //                        dsSV[i].print_Student();
    //                    }
    //                }
    //                break;
    //            cout << "Done...";
    //            saveFile();
    //        }
    //    }
    //    else
    //    {
    //        cout << "\nHien danh sach dang trong, vui long chon 1 de them sinh vien.\n";
    //    }
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

void QLyQUES::test()
{
 if (number_studetns > 0)
    {
        for (int i = 0; i < 5; i++)
        {
        	cout<<"Cau "<<i+1<<": ";
            dsQues[i].print_Question();
            loadFile();
        }
    }
    else
    {
        cout << "\nDanh sach sinh vien trong.\n";
    }
}
//    cout << "hhhssh";
    // loadFile();
    //    switch (choice)
    //    {
    //    case 'A'
    //
    //        break;
    //    case 'B'
    //        break;
    //    case 'C'
    //        break;
    //    case 'D'
    //        break;
    //    case ''
    //        break;
    //    default:
    //        break;
    //    }

void QLyQUES::login()
{
    string admin, student;
    string pass;
    cout << "Dang Nhap: ";
    cin >> admin;
    cout << "PassWord: ";
    cin >> pass;
    if (admin == "admin" && pass == "admin")
    {
        printMenu();
    }
    else if(admin == "student" && pass == "student"){
        test();
    }
    else
    {
        cout << "Tai khoan khong ton tai";
    }
}
void QLyQUES::printMenu()
{
LABEL1:
    cout << "\n\t\t\t+-------------------------------------------+\n";
    cout << "\t\t\t|             Quan Ly Sinh Vien               |\n";
    cout << "\t\t\t+---------------------------------------------+\n";
    cout << "\t\t\t|1. Them cau hoi      | |  2. Sua cau hoi     |\n";
    cout << "\t\t\t|3. Xoa cau hoi       | |  4.Lam de thi       |\n";
    cout << "\t\t\t|5. Xem de            | |                     |\n";
    cout << "\t\t\t+---------------------------------------------+\n";
    int chon;
    char select;
    cout << "Moi chon chuc nang: ";
    cin >> chon;
    //   chon = getInputOneCharacter();
    cout << "haha";
    while (chon <= 6 && chon > 0)
    {
        switch (chon)
        {
        case 1:
            cout << "\n\t\t|=======================================================================================|\n";
            cout << setw(64) << "THEM CAU HOI\n";
            addQuestion();
            listQuestion();
            cout << "\t\t|=======================================================================================|\n";
            break;
        case 2:
            cout << "\t\t|=======================================================================================|\n";
            cout << setw(64) << "SUA CAU HOI\n";
            //               listStudent();
            cout << "\t\t|=======================================================================================|\n";
            break;
        case 3:
            cout << "\t\t|======================================================================================|\n";
            cout << setw(64) << "XOA CAU HOI\n";

            cout << "\n\t\t|=======================================================================================|\n";
            break;
        case 4:
            cout << "\t\t|=======================================================================================|\n";
            cout << setw(64) << "LAM DE\n";
            test();
            cout << "\t\t|=======================================================================================|\n";
            break;
        case 5:
            cout << "\t\t|=======================================================================================|\n";
            cout << setw(64) << "XOA THONG TIN SINH VIEN\n";
            listQuestion();
            cout << "\t\t========================================================================================|\n";
            break;
        case 6:
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
        }
    }
}

// void QLyQUES::test(){
//
// }
