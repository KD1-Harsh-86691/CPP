/*
	Name - Harsh Dixit
	Roll no - 86691
	KD1-86691-Harsh
*/


#include <iostream>
#include <typeinfo>

using namespace std;
class Person
{
    string name;

public:
    Person()
    {
        cout << "Person()" << endl;
    }
    Person(string name)
    {
        cout << "Person(string)" << endl;
        this->name = name;
    }
    virtual void accept()
    {
        cout << "Enter the name - ";
        cin >> name;
    }
    virtual void display()
    {
        cout << "Name - " << name << endl;
    }
};

class Employee : public Person
{
    int empid;
    double salary;

public:
    Employee()
    {
        cout << "Employee()" << endl;
    }
    Employee(int empid, string name, double salary) : Person(name)
    {
        cout << "Employee(int,string,double)" << endl;
        this->empid = empid;
        this->salary = salary;
        // this->name = name; // can perform  if data member is protected
    }
    int getEmpid()
    {
        return empid;
    }
    void accept()
    {
        cout << "Enter empid - ";
        cin >> empid;
        Person::accept();
        cout << "Enter Salary - ";
        cin >> salary;
    }

    void display()
    {
        cout << "Empid -  " << empid << endl;
        Person::display();
        cout << "Salary -  " << salary << endl;
    }
};

class Student : public Person
{
    int rollno;
    double marks;

public:
    Student()
    {
    }
    Student(int rollno, string name, double marks) : Person(name)
    {
        this->rollno = rollno;
        this->marks = marks;
    }
    void accept()
    {
        cout << "Enter rollno - ";
        cin >> rollno;
        Person::accept();
        cout << "Enter marks - ";
        cin >> marks;
    }
    void display()
    {
        cout << "Rollno - " << rollno << endl;
        Person::display();
        cout << "Marks - " << marks << endl;
    }
    int getrollno()
    {
        return this->rollno;
    }
};

int findEmployee(Person **ptr, int index)
{
    int id;
    cout << "Enter the empid to search the employee - ";
    cin >> id;

    for (int i = 0; i < index; i++)
    {
        if (typeid(*ptr[i]) == typeid(Employee))
        {
            Employee *eptr = (Employee *)ptr[i];
            if (id == eptr->getEmpid())
                return i;
        }
    }
    return -1;
}
int findStudent(Person **ptr, int index)
{
    int rno;
    cout << "Enter the rollno to search the Student - ";
    cin >> rno;

    for (int i = 0; i < index; i++)
    {
        if (typeid(*ptr[i]) == typeid(Student))
        {
            Student *sptr = (Student *)ptr[i];
            if (rno == sptr->getrollno())
                return i;
        }
    }
    return -1;
}

enum EMenu
{
    EXIT,
    ADD_EMPLOYEE,
    ADD_STUDENT,
    DISPLAY_EMPLOYEE,
    DISPLAY_STUDENT,
    FIND_EMPLOYEE,
    FIND_STUDENT
};

int menu()
{
    int choice;
    cout << "*******" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. Add Student" << endl;
    cout << "3. Display Employee" << endl;
    cout << "4. Display Student" << endl;
    cout << "5. Find Employee" << endl;
    cout << "6. Find Student" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout << "*******" << endl;

    return choice;
}

int main()
{
    Person *arr[5];
    int index = 0;
    int choice;
    while ((choice = menu()) != EXIT)
    {
        switch (EMenu(choice))
        {
        case ADD_EMPLOYEE:
            if (index < 5)
            {
                arr[index] = new Employee;
                arr[index]->accept();
                index++;
            }
            else
                cout << "Array is Full..." << endl;
            break;
        case ADD_STUDENT:
        {
            arr[index] = new Student;
            arr[index]->accept();
            index++;
        }
        break;
        case DISPLAY_EMPLOYEE:
            for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Employee))
                    arr[i]->display();
            break;
        case DISPLAY_STUDENT:
        {
            for (int i = 0; i < index; i++)
                if (typeid(*arr[i]) == typeid(Student))
                    arr[i]->display();
            break;
        }
        break;
        case FIND_EMPLOYEE:
        {
            int i = findEmployee(arr, index);
            if (i != -1)
                arr[i]->display();
            else
                cout << "Employee not found..." << endl;
        }
        break;
        case FIND_STUDENT:
        {
            int i = findStudent(arr, index);
            if (i != -1)
                arr[i]->display();
            else
                cout << "Student not found..." << endl;
        }
        break;
        default:
            cout << "Wrong choice ... " << endl;
            break;
        }
    }

    return 0;
}
