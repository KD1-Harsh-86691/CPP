/*
	Name - Harsh Dixit
	Rollno - 86691
	KD1-86691-Harsh
*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    string gender;
    const int roll_no;
    static int auto_generated_number;
    int marks[3];

public:
    Student() : roll_no(auto_generated_number++)
    {
        name = "";
        gender = "";
        for (int i = 0; i < 3; i++)
        {
            marks[i] = 0;
        }
    }

    Student(string name, string gender, int marks[3]) : roll_no(auto_generated_number++)
    {
        this->name = name;
        this->gender = gender;
        for (int i = 0; i < 3; i++)
        {
            this->marks[i] = marks[i];
        }
    }

    void accept()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter gender: ";
        cin >> gender;
        cout << "Enter marks for three subjects: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void display() const
    {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Roll Number: " << roll_no << endl;
        cout << "Marks: ";
        for (int i = 0; i < 3; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << "Percentage: " << calculatePercentage() << "%" << endl;
    }

    int getRollNo() const
    {
        return roll_no;
    }

    float calculatePercentage() const
    {
        int totalMarks = 0;
        for (int i = 0; i < 3; i++)
        {
            totalMarks += marks[i];
        }
        return (totalMarks / 3.0);
    }
};

int Student::auto_generated_number = 1000;

int searchStudent(Student *arr[], int size, int rollNo)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i]->getRollNo() == rollNo)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Student *students[5];
    int choice;

    do
    {
        cout << "\nStudent Management System\n";
        cout << "1. Accept Student Details\n";
        cout << "2. Display Student Details\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < 5; i++)
            {
                students[i] = new Student();
                cout << "\nEnter details for Student " << i + 1 << ": " << endl;
                students[i]->accept();
            }
            break;

        case 2:
            for (int i = 0; i < 5; i++)
            {
                cout << "\nDetails of Student " << i + 1 << ": " << endl;
                students[i]->display();
            }
            break;

        case 3:
        {
            int rollNo;
            cout << "Enter roll number to search: ";
            cin >> rollNo;
            int index = searchStudent(students, 5, rollNo);
            if (index != -1)
            {
                cout << "Student found at index: " << index << endl;
                students[index]->display();
            }
            else
            {
                cout << "Student not found." << endl;
            }
            break;
        }

        case 4:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    for (int i = 0; i < 5; i++)
    {
        delete students[i];
    }

    return 0;
}

