/*
	Name - Harsh Dixit
	Rollno - 86691
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
    
    int getDay()
    {
        return this->day;
    }
    
    int getMonth()
    {
        return this->month;
    }
    
    int getYear()
    {
        return this->year;
    }

    void display()
    {
        cout << "D.O.B : " << getDay() << "/" << getMonth() << "/" << getYear() << endl;
    }
    
    void accept()
    {
        cout << "Enter day : " << endl;
        int day;
        cin >> day;
        setDay(day);
        cout << "Enter month : " << endl;
        int month;
        cin >> month;
        setMonth(month);
        cout << "Enter year " << endl;
        int year;
        cin >> year;
        setYear(year);
    }
};

class Person
{
    string name;
    string address;
    Date dob;

public:
    Person()
    {
        this->name = "";
        this->address = "";

        Date dob;
        this->dob = dob;
    }
    
    Person(string name, string address, int day, int month, int year)
    {
        Date dob(day, month, year);
        this->dob = dob;
        this->name = name;
        this->address = address;
    }
    
    void display()
    {
        cout << "The person details are as follows :- \n";
        cout << "Name : " << getName() << endl;
        cout << "Address : " << getAddress() << endl;
        this->dob.display();
    }
    
    string getName()
    {
        return this->name;
    }
    
    string getAddress()
    {
        return this->address;
    }
    
    void accept()
    {

        cout << "Please enter the name of the person:\n";
        string name;
        getline(cin, name);
        setName(name);
        cout << "Please enter the address of the person. \n";
        string address;
        getline(cin, address);
        setAddress(address);
        cout << "Please enter the date of birth. \n";
        this->dob.accept();
        cout << "Details Saved successfully.\n";
    }
    
    void setName(string name)
    {
        this->name = name;
    }
    
    void setAddress(string address)
    {
        this->address = address;
    }
};

int main()
{

    cout << "\n\nIntializing the person 1 with default values" << endl;
    Person p1;
    p1.display();

    cout << "\n\nInitializing the person 2 details with parameterized constructor  :- \n";
    Person p2("Mayank Choudhary", "Sunbeam Karad", 27, 1, 1999);
    p2.display();

    cout << "\n\nTaking input from user for the person 3 details" << endl;
    Person p3;
    p3.accept();
    p3.display();
    
    return 0;
}
