/*
	Name - Harsh Dixit
	Roll no - 86691
	KD1-86691-Harsh
*/

#include <iostream>
using namespace std;

class Employee{

    int id;
    double salary;

public:

    Employee(){
        id = 0;
        salary = 0;
    }    

    Employee(int id, double salary){
        this-> id = id;
        this-> salary = salary;
    }

    void setId(int id){
        this->id = id;
    }

     void setSalary(double salary){
        this->salary = salary;
    }

    int getId(){
        return id;
    }

    double getSalary(){
        return salary;
    }

    void accept(){
        cout<<"Enter Id : "<<endl;
        cin>>id;
        cout<<"Enter Salary : "<<endl;
        cin>>salary;
    }

    void display(){
        cout<<"Id : "<<id<<endl;
        cout<<"Salary : "<<salary<<endl;
    }
};

class Manager : virtual public Employee{

    double bonus;

protected:

    void acceptManager(){
        cout<<"Enter bonus : "<<endl;
        cin>>bonus;
    }    

    void displayManager(){
        cout<<"Bonus is : "<<bonus<<endl;
    }

public:

    Manager(){
        bonus = 0;
    }    

    Manager(int id, double salary, double bonus): Employee(id,salary)
	{
       this->bonus = bonus;
    }

    void setBonus(double bonus)
	{
        this->bonus = bonus;
    }

    double getBonus(){
        return bonus;
    }

    void accept()
	{
        Employee::accept();
        acceptManager();
    }

    void display()
	{
        Employee::display();
        displayManager();
    }

};

class Salesman : virtual public Employee{

    double commision;

protected:

    void acceptSalesman(){
        cout<<"Enter Commision : "<<endl;
        cin>>commision;
    }    

    void displaySalesman(){
        cout<<"Commision is : "<<commision<<endl;
    }

public:

    Salesman(){
        commision = 0;
    }    

    Salesman(int id, double salary, double commision): Employee(id,salary)
	{
       this->commision=commision;
    }

    void setCommission(double commision)
	{
        this->commision=commision;
    }

    double getCommision()
	{
        return commision;
    }

    void accept()
	{
        Employee::accept();
        acceptSalesman();
    }

    void display()
	{
        Employee::display();
        displaySalesman();
    }

};

class SalesManager : public Manager, public Salesman{

public:
    SalesManager()
	{
    }

    SalesManager(int id, double sal, double bonus, double commision):Employee(id,sal)
	{
        setBonus(bonus);
        setCommission(commision);
    }

    void accept(){
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }

    void display(){
        Employee::display();
        displayManager();
        displaySalesman();
    }

};


int main(){
    SalesManager s1;
    s1.accept();
    s1.display();

    SalesManager s2(2,20000,5000,6000);
    s2.display();
	return 0;
}
