/*
	Name - Harsh Dixit
	roll no - 86691
	KD1-86691-Harsh
*/
#include<iostream>
using namespace std;

class Time
{
	int hour;
	int minute;
	int second;
public:
	// Default constructor
	Time()
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
	// Parameterized constructor
	Time(int hour,int minute,int second)
	{
		this->hour = hour;
		this->minute = minute;
		this->second = second;	
	}
	// getters
	getHour()
	{
		return hour;
	}
	
	getMinute() 
	{
		return minute;;
	}
	
	getSecond()
	{
		return second;
	} 
	//setters
	setHour(int h)
	{
		hour = h;
	} 
	
	setMinute(int m)
	{
		minute = m;
	} 
	
	setSeconds(int s)
	{
		second = s;
	} 
	
	displayTime()
	{
		cout << hour << " : " << minute << " : " << second << endl;
	}
};

int main()
{
    Time *time_obj = new Time[5];

    for (int i = 0; i < 5; i++) 
	{
        int h, m, s;
        cout << "Enter hour for Time object " << i + 1 << " : ";
        cin >> h;
        cout << "Enter minute for Time object " << i + 1 << " : ";
        cin >> m;
        cout << "Enter second for Time object " << i + 1 << " : ";
        cin >> s;
        time_obj[i] = Time(h, m, s);
    }

    for (int i = 0; i < 5; i++) 
	{
        cout << "Time object " << i + 1 << ":" << endl;
        time_obj[i].displayTime();
    }
	return 0;
}
