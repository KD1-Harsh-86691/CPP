/*
	Name - Harsh Dixit
	Rollno - 86691
	KD1-86691-Harsh
*/

#include <iostream>
#include <typeinfo>
using namespace std;
const int size = 6; // fixed to Emp size

//-------------------------CLASS EMPLOYEE-------------------------------------------

class Employee
{
    int id;
    double salary;

public:
    // parameter less constructor
    Employee()
    {
        id = 0;
        salary = 0;
    }

    // parameterized constructor
    Employee(int id, double sal)
    {
        this->id = id;
        this->salary = sal;
    }

    // This is our setters below
    void setId(int id)
    {
        this->id = id;
    }

    void setSalary(double sal)
    {
        this->salary = sal;
    }

    // This is our getters below
    int getId()
    {
        return id;
    }

    double getSalary()
    {
        return salary;
    }

    virtual void accept()
    {
        cout << "Enter id : ";
        cin >> id;
        cout << "Enter salary : ";
        cin >> salary;
    }

    virtual void display()
    {
        cout << "\nid : " << id << endl;
        cout << "salary : " << salary << endl;
    }
};

//-------------------------CLASS MANAGER-------------------------------------------
class Manager : virtual public Employee
{
    double bonus;

public:
    // constructors
    Manager()
    {
        bonus = 0;
    }

    Manager(int id, double sal, double bonus) : Employee(id, sal)
    {
        this->bonus = bonus;
    }

    // This is our setters below
    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    // This is our getters below
    double getBonus()
    {
        return bonus;
    }

    void accept()
    {
        Employee::accept();
        this->acceptManagerDetails();
    }

    void display()
    {
        Employee::display();
        this->displayManagerDetails();
        cout << endl;
    }

protected:
    void acceptManagerDetails()
    {
        cout << "Enter bonus : ";
        cin >> bonus;
    }

    void displayManagerDetails()
    {
        cout << "Bonus : " << bonus;
    }
};

//-------------------------CLASS SALESMAN-------------------------------------------
class Salesman : virtual public Employee
{
    double commission;

public:
    // parameterless constructors
    Salesman()
    {
        commission = 0;
    }
	
	//parameterized constructor
    Salesman(int id, double sal, double commission) : Employee(id, sal)
    {
        this->commission = commission;
    }

    // This is our setters below
    void setCommission(double comm)
    {
        this->commission = comm;
    }

    // This is our getters below
    double getCommission()
    {
        return commission;
    }

    void accept()
    {
        Employee::accept();
        this->acceptSalesmanDetails();
    }

    void display()
    {
        Employee::display();
        this->displaySalesmanDetails();
    }

protected:
    void acceptSalesmanDetails()
    {
        cout << "Enter commition : ";
        cin >> commission;
    }

    void displaySalesmanDetails()
    {
        cout << "commition : " << commission<<endl;
    }
};

//------------------------------------------------------------------------------------
class SalesManager : public Manager, public Salesman
{

public:
    SalesManager()
    {
        // cout << "SalesManager()" << endl;
    }

    SalesManager(int id, double sal, double bonus, double comm) : Employee(id, sal)
    {
        this->setId(id);
        this->setSalary(sal);
    }

    void accept()
    {
        Employee::accept();
        this->acceptManagerDetails();
        this->acceptSalesmanDetails();
        cout << endl;
    }
    void display()
    {
        Employee::display();
        this->displayManagerDetails();
        cout << endl;
        this->displaySalesmanDetails();
    }
};

int addEmployee()
{
    int ch;
    cout << "\n1.Manager" << endl;
    cout << "2.Salesman" << endl;
    cout << "3.SalesManager" << endl;
    cout << "0. for exit from accept employee"<<endl;
    cout << "Enter your choice : ";
    cin >> ch;

    return ch;
}

int displayMenu()
{
    int choice;
    cout << "\n----------------------------------\n";
    cout << "1.Accept Employee" << endl;
    cout << "2.Display count of all Emps" << endl;
    cout << "3.Display All Managers" << endl;
    cout << "4.Display All Salesman" << endl;
    cout << "5.Display All SalesManagers" << endl;
    cout << "0.Exit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

void countTotalEmps(Employee **emps, int totalEmps)
{
    int mCount = 0, sCount = 0, smCount = 0;
    for (int i = 0; i < totalEmps; i++)
    {
        if (typeid(*emps[i]) == (typeid(Manager)))
            mCount++;
        else if (typeid(*emps[i]) == (typeid(Salesman)))
            sCount++;
        else
            smCount++;
    }

    cout << "\nTotal employee = " << totalEmps << endl;
    cout << "Total Manager = " << mCount << endl;
    cout << "Total Salesman = " << sCount << endl;
    cout << "Total SalesManager = " << smCount << endl;
}
//----------------------Main Function--------------------------------------

int main()
{
    Employee *e[size];
    int choice;
    int index = 0;

    while ((choice = displayMenu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            int ch;

            while ((ch = addEmployee()) != 0)
            {
                switch (ch)
                {
                case 1:
                {
                    if (index < size)
                    {
                        e[index] = new Manager();
                        e[index]->accept();
                        index++;
                    }
                    else
                        cout << "Emp array is full..\n";
                }
                break;
                case 2:
                {
                    if (index < size)
                    {
                        e[index] = new Salesman();
                        e[index]->accept();
                        index++;
                    }
                    else
                        cout << "Emp array is full..\n";
                }
                break;
                case 3:
                {
                    if (index < size)
                    {
                        e[index] = new SalesManager();
                        e[index]->accept();
                        index++;
                    }
                    else
                        cout << "Emp array is full..\n";
                }
                break;
                case 0:
                    cout << "Exit from Employees.." << endl;
                    break;

                default:
                {
                    cout << "Invalide choice...\n";
                }
                break;
                }
            }
        }
        break;
        case 2:
        {
            countTotalEmps(e, index);
        }
        break;
        case 3:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e[i]) == typeid(Manager))
                    e[i]->display();
            }
        }
        break;
        case 4:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e[i]) == typeid(Salesman))
                    e[i]->display();
            }
        }
        break;
        case 5:
        {
            for (int i = 0; i < index; i++)
            {
                if (typeid(*e[i]) == typeid(SalesManager))
                    e[i]->display();
            }
        }
        break;

        case 0:
            cout << "Thank you.. Please visit again...\n";
        break;

        default:
            cout << "Invalide choice...";
        break;
        }
    }

    return 0;
}

