/*
    Name - Harsh Dixit
    Rollno - 86691
    KD1-86691-Harsh
*/

#include <iostream>
using namespace std;
//-----------------------------CUSTOM EXCEPTION CLASS--------------------------

class InSufficientFundsException
{
    int accno;
    double currentbalance;
    string message;

public:
    InSufficientFundsException()
    {
        message = "SomeThing Went Wrong";
    }

    InSufficientFundsException(int accno,double currentbalance, string messages)
    {
        this->accno = accno;
        this->currentbalance = currentbalance;
        this->message = message;
    }

    void display()
    {
        cout << "==================================" << endl;
        cout << "Exception : InSufficientFundsException" << endl;
        cout << "Account No : " << accno << endl;
        cout << "Current Balance : " << currentbalance << endl;
        cout << "Message : " << message << endl;
        cout << "==================================" << endl;

    }
};


//-----------------------------ENUM--------------------------------------------
enum EAccountType
{
    SAVING = 1,
    CURRENT,
    DMAT
};

//----------------------------ACCOUNT CLASS-------------------------------------
class Account
{
    int accno;
    EAccountType e;
    double balance;

public:
    Account() 
    {
        accno = 1000;
        balance = 0;
    }

    Account(int accno , EAccountType etype , double balance)
    {
        this->accno = accno;
        this->balance = balance;
        this->e = etype;
    }

    void accept()
    {
        cout << "Enter accno - " ;
        cin >> accno;

        int choice;
        cout << "Choose your account type : " << endl;
        cout << "1 -> SAVING" << endl;
        cout << "2 -> CURRENT" << endl;
        cout << "3 -> DMAT" << endl;
        cin >> choice;

        e = EAccountType(choice);
        cout << "Enter balance : ";
        cin >> balance;
    }

    void display()
    {
        cout << "-------------------------" << endl;
        cout << "Account number = " << accno << endl;
        cout << "Account Balance = " << balance << endl;

        switch(e)
        {
            case SAVING:
                cout << "Account type - savings " << endl;
                break;
            case CURRENT:
                cout << "Account Type - Current " << endl;
                break;
            case DMAT:
                cout << "Account Type - Dmat " << endl;
                break;
        }
    }

    void deposit(int amt)
    {
        if(amt < 0)
            throw InSufficientFundsException(accno,balance,"You can't enter negative number..");
        else{
            balance = balance + amt;
            cout << "New balance = " << balance << endl;
        }
    }

    void withdraw(int amt)
    {
        if(amt > balance)
            throw InSufficientFundsException(accno,balance,"Your amount is greater than your balance. You can't withdraw.");
        else
        {
            balance = balance - amt;
            cout << "New balance = " << balance << endl;
        }
    }

};
    int getDepositAmount()
    {
        int amt;
        cout << "\nEnter amount to deposite : ";
        cin >> amt;
        return amt;
    }

    int getWithdrawAmount()
    {
        int amt;
        cout << "\nEnter amount to withdraw : ";
        cin >> amt;
        return amt;
    }

int main()
{
    Account *acc[5];
    int index = 0;

    while(index != 5)
    {
        if(index < 5)
        {
            acc[index] = new Account;
            acc[index]->accept();
            acc[index]->display();
            try
            {
                acc[index]->deposit(getDepositAmount());
            }
            catch(InSufficientFundsException e)
            {
                e.display();
            }

            try
            {
                acc[index]->withdraw(getWithdrawAmount());
            }
            catch(InSufficientFundsException e)
            {
                e.display();
            }
            index++;  
        }
        else
            cout << "Account array is full..";
    }
    return 0;
}



