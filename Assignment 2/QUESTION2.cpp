// Harsh Dixit
// Roll no - 86691
// KD1-96691-Harsh


#include <iostream>
using namespace std;

int menu()
{
    int choice;
    cout<<"0 : Exit "<<endl;
    cout<<"1 : Enter student details "<<endl;
    cin>>choice;
    return choice; 
}


class Student
{
    int roll_no;
    string name;
    int marks;

public:
    void initStudent()
    {
        roll_no = 0;
        name = "";
        marks = 0;
    }


    void printStudentOnConsole()
    {
        cout << "Roll Number " << roll_no << endl;
        cout << "Name : "  << name << endl;
        cout << "Marks = " << marks << endl; 
    }


    void acceptStudentFromConsole()
    {
        int c = menu();
        if(c == 1){
            cout<<"Enter rollno , name , marks : "<<endl;
            cin >> roll_no >> name >> marks;
        }
        else
        {
            exit;
        }
    }
};

int main()
{
    Student s1;
    s1.initStudent();
    s1.acceptStudentFromConsole();
    s1.printStudentOnConsole();
    return 0;

}