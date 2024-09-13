/*	Name - Harsh Dixit
	Roll no - 86691
	KD1-86691-Harsh*/

#include <iostream>
using namespace std;

class tollbooth
{
    int no_of_Cars;
    float money;

    public:

    static int paying_cars;
    static int not_paying_cars;

    tollbooth()         // constructor
    {
        no_of_Cars = 0;
        money = 0;
    }

    void payingCar()
    {
        no_of_Cars++;
        paying_cars++;
        money = money + 0.50;
    }

    void nopayCar()
    {
        no_of_Cars++;
        not_paying_cars++;
    }

    void printOnConsole()
    {
        cout << "Amount Collected : " << money << endl;
        cout << "Total cars : " << no_of_Cars << endl;
        cout << "Paying Cars : " << paying_cars << endl;
        cout << "Not Paying cars : " << not_paying_cars << endl;
    }
};

int tollbooth::paying_cars=0;
int tollbooth::not_paying_cars=0;

int main()
{
    int v=1;

    tollbooth t1;
    while(v != 0)
    {

        int choice;
        cout << "0. Exit and show result " << endl;
        cout << "Enter your choice " << endl;
        cout << "1. Car paid toll " << endl;
        cout << "2. Car not paid toll "<< endl;

        cin >> choice;

        switch(choice)
        {
            case 1:
                t1.payingCar();
                break;
            case 2:
                t1.nopayCar();
                break;
            default:
                v = 0; 
                exit;
        }
    }
    t1.printOnConsole();
    
}
