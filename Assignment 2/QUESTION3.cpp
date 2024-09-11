
// Harsh Dixit
// Roll no - 86691
// KD1-96691-Harsh

#include <iostream>
using namespace std;

int menu()
{
    int choice;
    cout<<"0 : Exit "<<endl;
    cout<<"1 : Enter Details of student "<<endl;
    cin>>choice;
    return choice; 
}

namespace NStudent
{
    class student
    {

    public:
        int rollno;
        string name;
        int marks;

        void initStudent(int a=0,string s="",int c=0)          // initializing data
        {
            rollno = 0;
            name = "";
            marks = 0;
        }

        void printStudentOnConsole()                   // printing data
        {
            cout<<"Name : "<<name<<endl;
            cout<<"Rollno : "<<rollno<<endl;
            cout<<"Marks : "<<marks<<endl;
        }

        void acceptStudentFromConsole()
        {
            int c = menu();
            if(c == 1){
                cout<<"Enter name, rollno & marks : "<<endl;
                cin>>name>>rollno>>marks;
            }
            else
            {
                exit;
            }
        }
    };
}

int main()
{
    NStudent::student d1;
    d1.initStudent();
    d1.acceptStudentFromConsole();
    d1.printStudentOnConsole();

    return 0;
}