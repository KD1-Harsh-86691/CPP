// Name - Harsh Dixit
// Roll no - 86691
// KD1-86691-Harsh

#include <iostream>
using namespace std;

int menu()
{
    int choice;
    cout<<"0 : Exit "<<endl;
    cout<<"1 : Enter date "<<endl;
    cin>>choice;
    return choice; 
}

struct date
{
    int day;
    int month;
    int year;

    void initDate()          // initializing date
    {
        day=1;
        month=1;
        year=1900;
    }

    bool isLeapYear()           // is a leap year or not
    {
        if((year%4==0 && year%100 !=0) || (year%400==0 && year%400==0)){
            return true;
        }else{
            return false;
        }
    }

    void printDateOnConsole()                   // printing date
    {
        cout<<"Date :- "<<day<<"-"<<month<<"-"<<year<<endl;
        if(isLeapYear()){
            cout<<"It's a Leap year"<<endl;
        }else{
            cout<<"It's not a Leap year"<<endl;
        }
    }

    void acceptDateFromConsole()
    {
        int c = menu();
        if(c == 1){
            cout<<"Enter date in dd-mm-yyyy format : "<<endl;
            cin>>day>>month>>year;
        }
        else
        {
            exit;
        }
    }
};

int main()
{
    int choice;
    struct date t1;
    t1.initDate();
    t1.acceptDateFromConsole();
    t1.printDateOnConsole();
    return 0;
}
