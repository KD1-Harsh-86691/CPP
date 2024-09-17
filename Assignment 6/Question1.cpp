/*
	Name - Harsh Dixit
	Roll no - 86691
	KD1-86691-Harsh
*/

#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    
    void setDay(int day)
    {
        this->day = day;
    }
    
    void setMonth(int month)
    {
        this->month = month;
    }
    
    void setYear(int year)
    {
        this->year = year;
    }

    void display()
    {
        cout << "Date  : " << this->day << "/" << this->month << "/" << this->year << endl;
    }
    
    void accept()
    {
        cout << "Enter the day " << endl;
        cin >> this->day;
        cout << "Enter the month" << endl;
        cin >> this->month;
        cout << "Enter the year" << endl;
        cin >> this->year;
    }
    
};

class Person
{
    string name;
    string address;
    Date birthdate;

public:
    Person()
    {
        this->name = "";
        this->address = "";
    }
    
    Person(string name, string address, int day, int month, int year)
    {
        this->name = name;
        this->address = address;
        this->birthdate.setDay(day);
        this->birthdate.setMonth(month);
        this->birthdate.setYear(year);
    }
    
    void display()
    {
        cout << "Name : " << this->name << endl;
        cout << "Address : " << this->address << endl;
        cout << "Birth ";
        this->birthdate.display();
    }
    
    void accept()
    {
        cout << "Enter the name " << endl;
        cin.ignore();
        getline(cin, this->name);
        cout << "Enter the address" << endl;
        cin.ignore();
        getline(cin, this->address);
        cout << "Enter the birth date : " << endl;
        this->birthdate.accept();
    }
};

    // Inheritance - Single level
class Employee : public Person
{
    int id;
    int sal;
    string dept;
    // Association - Composition
    Date joining_date;

public:
    Employee() : Person()
    {
        this->id = 0;
        this->sal = 0;
        this->dept = "";
    }
    
    Employee(int id, int sal, string dept, int joining_date_day, int joining_date_month, int joining_date_year, string name, string address, int day, int month, int year) : Person(name, address, day, month, year)
    {
        this->id = id;
        this->sal = sal;
        this->dept = dept;
        this->joining_date.setDay(joining_date_day);
        this->joining_date.setMonth(joining_date_month);
        this->joining_date.setYear(joining_date_year);
    }
    
    void accept()
    {
        cout << "Enter the id of employee : " << endl;
        cin >> this->id;
        cout << "Enter the salary of employee : " << endl;
        cin >> this->sal;
        cout << "Enter the department name : " << endl;
        cin.ignore();
        getline(cin, this->dept);
        cout << "Enter the Joining date : " << endl;
        this->joining_date.accept();
        Person::accept();
    }
    
    void display()
    {
        cout << "The id of employee is " << this->id << endl;
        cout << "The salary of employee is " << this->sal << endl;
        cout << "The department name of employee is " << this->dept << endl;
        cout << "Joining ";
        this->joining_date.display();
        Person::display();
    }
};


int main()
{
    cout << "\n\n-----------------------------------------\n\n";
    cout << "Created employee object with default parameterless contructor " << endl;
    Employee employee;
    cout << "Displaying employee object using the employee display member function. " << endl;
    employee.display();
    cout << "\n\n-----------------------------------------\n\n";

    cout << "Created employee object with parameterized constructor " << endl;
    Employee employee1(78, 100000, "Sales", 01, 01, 2025, "Harsh", "Sunbeam Karad", 01, 10, 2000);
    cout << "Displaying employee object created using the parameterized contructor " << endl;
    employee1.display();
    cout << "\n\n-----------------------------------------\n\n";

    cout << "Creating the employee object while taking the input from the user " << endl;
    Employee employee2;
    employee2.accept();
    employee2.display();
    
    return 0;
}
