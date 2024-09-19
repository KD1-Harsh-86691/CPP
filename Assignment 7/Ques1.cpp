/*
	Name - Harsh Dixit
	Rollno - 86691
	KD1-86691-Harsh
*/

#include <iostream>
#include <typeinfo>
using namespace std;
int flag = 0;


//-------------------------CLASS PRODUCT------------------------
class Product
{
    int id;
    string title;
    double price;

public:
    Product() : id(0), title(" "), price(0) {}

    Product(int id, string title, double price)
    {
        this->id = id;
        this->title = title;
        this->price = price;
    }

    // getters
    int getId()
    {
        return id;
    }

    string getTitle()
    {
        return title;
    }

    double getPrice()
    {
        return price;
    }

    virtual void accept()
    {
        cout << "Enter id : ";
        cin >> id;
        cout << "Enter title : ";
        cin >> title;
        cout << "Enter price : ";
        cin >> price;
    }

    virtual void display()
    {
        cout << "id = " << id << endl;
        cout << "title = " << title << endl;
        cout << "price = " << price << endl;
    }
};
//-----------------CLASS BOOK-----------------------------------------
class Book : public Product
{
    string author;

public:
    Book() : author(" ") {}

    Book(int id, string title, double price, string author) : Product(id, title, price)
    {
        this->author = author;
    }

    void accept()
    {
        Product::accept();
        acceptAuthor();
    }

    void display()
    {
        Product::display();
        displayAuthor();
    }

protected:
    void acceptAuthor()
    {
        cout << "Enter author name : ";
        cin >> author;
        cout << endl;
    }

    void displayAuthor()
    {
        cout << "Author name is = " << author << endl;
    }
};
//-----------------CLASS TAPE--------------------------------------------------------
class Tape : public Product
{
    string artist;

public:
    Tape() : artist(" ") {}
    Tape(int id, string title, double price, string artist) : Product(id, title, price)
    {
        this->artist = artist;
    }

    void accept()
    {
        Product::accept();
        acceptArtistDetails();
    }

    void display()
    {
        Product::display();
        displayArtistDetails();
    }

protected:
    void acceptArtistDetails()
    {
        cout << "Enter artist name : ";
        cin >> artist;
        cout << endl;

    }
    void displayArtistDetails()
    {
        cout << "Artist = " << artist;
    }
};

//--------------------------------MENU------------------------------------------------------
int menu()
{
    int choice;
    cout << "=================================" << endl;
    cout << "1.Add Book" << endl;
    cout << "2.Add Tape" << endl;
    cout << "3.Display Final Bill" << endl;
    cout << "0.Exit" << endl;
    cout << "Enter Your choice : ";
    cin >> choice;
    cout << "=================================\n";
    return choice;
}

void displayFinalBill(Product **p, int size)
{
    int totalPrice = 0;
    int discountAmt = 0;
    if(flag != 1){
            cout << "Zero products added. can't display product list...\n";
            return;
    }
    cout << "Id\tTitle\tPrice\tDiscount %\tTotal price\n";
    for (int i = 0; i < size; i++)
    {

        if (typeid(*p[i]) == typeid(Book))
        {

            discountAmt = (p[i]->getPrice()*10) / 100;

            cout<<p[i]->getId()<<"\t"<<p[i]->getTitle()<<"\t"<< p[i]->getPrice() << "\t 10%"<< "\t\t  " << p[i]->getPrice() - discountAmt << endl;

            totalPrice = totalPrice + (p[i]->getPrice() - discountAmt);
            flag = 1;
        }
        else if(typeid(*p[i]) == typeid(Tape))
        {
            discountAmt = (p[i]->getPrice()*5) / 100;

            cout<<p[i]->getId()<<"\t"<<p[i]->getTitle()<<"\t" << p[i]->getPrice() << "\t 5%"<< "\t\t  " << p[i]->getPrice() - discountAmt << endl;

            totalPrice = totalPrice + (p[i]->getPrice() - discountAmt);
            flag = 1;

        }
        


    }
        cout << "\nTotal Bill = " << totalPrice <<" Rs.\n"<< endl;
}

int main()
{
    Product *arr[3];
    int choice;
    int index = 0;

    while((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
            if(index < 3){
            arr[index] = new Book;
            arr[index]->accept();
            index++;
            flag = 1;
            }else
                cout << "Product array is full..\n";
        }
        break;
        case 2:
        {
            if(index < 3){
            arr[index] = new Tape;
            arr[index]->accept();
            index++;
            flag = 1;
            }else
                cout << "Product array is full..\n";
        }
        break;
        case 3:
        {
            displayFinalBill(arr,index);
        }
        break;
        
        case 0:
        {
            cout << "Exit....\n";
            break;
        }
        default:
        {
            cout << "Invalid choice ....\n";
            break;
        }
        }

    } 

    return 0;
}
