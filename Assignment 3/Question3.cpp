/*	Name - Harsh Dixit
	Roll no - 86691
	KD1-86691-Harsh*/

#include <iostream>
using namespace std;

class Address {
	string building;
	string street;
	string city;
	int pin;
	
public:
	// This is our default constructor
	Address()
	{
		building = "";
		street = "";
		city = "";
		pin = 0;
	}
	// This is our parameterized constructor
	Address(string b,string s,string c,int p)
	{
		building = b;
		street = s;
		city = c;
		pin = p;
	}
	// // This is our getters
    string getBuilding() const 
	{
        return building;
    }

    string getStreet() const 
	{
        return street;
    }

    string getCity() const 
	{
        return city;
    }

    int getPin() const 
	{
        return pin;
    }
	
	// This is our setters
    void setBuilding(const string& b) {
        building = b;
    }

    void setStreet(const string& s) {
        street = s;
    }

    void setCity(const string& c) {
        city = c;
    }

    void setPin(int p) {
        pin = p;
    }
	
	void accept()
	{
		cout << "Enter building: ";
        getline(cin, building);
        cout << "Enter street: ";
        getline(cin, street);
        cout << "Enter city: ";
        getline(cin, city);
        cout << "Enter pin: ";
        cin >> pin;
	}
	
	void display()
	{
		cout << "Building = " << building << endl;
		cout << "Steet = " << street << endl;
		cout << "City = " << city << endl;
		cout << "PIN = " << pin << endl;
	}
};

int main()
{
	// this is the object i create for parameterless/default constructor
	Address a1;
	a1.display();
	cout << endl;
	
	// This is the object i create for accept member function
	Address a2;
	a2.accept();
	cout << endl;
	a2.display();
	cout << endl;
	
	// this is the object i create for parameterized constructor
	Address a3("Burj Khalifa","XYZ Street","Dubai",562583);
    a3.display();
    cout << endl;
    
    // Now i update address using setter(mutators)
    a3.setBuilding("Twin Towers");
    a3.setStreet("Abc Street");
    a3.setCity("Singapore");
    a3.setPin(548752);
    a3.display();
    cout << endl;
    return 0;

}
