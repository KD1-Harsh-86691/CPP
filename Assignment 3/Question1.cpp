// Harsh Dixit
// Roll No - 86691
// KD1-86691-Harsh

#include <iostream>
using namespace std;

class Box 
{
    float length;
    float width;
    float height;

    public :

    Box()     // parameterless (default) const
    {
        length = 5;
        width = 5;
        height = 5;
    }

    Box(float l, float w, float h)   // parameterized(with 3 parameters)
    {
        length = l;
        width = w;
        height = h;
    }

    Box(float val)     // single paramaterized
    {
        length = val;
        width = val;
        height = val;
    }

    int displayBoxVolume()
    {
        cout<<"Volume of the box : "<< length*width*height << endl;
    }
};

int main()
{
    int choice;
    cout<< "Enter your choice" <<endl;
    cout << "0. For exit.." << endl;
    cout<< "1. Calculate Box Volume with default values " << endl;
    cout << "2. Calculate Box Volume with length,breadth and height with same value "<< endl;
    cout << "3. Calculate Box Volume with different length,breadth and height values " << endl;
    cin >> choice;
while(choice != 0)
  {  
    switch(choice)
    {
        case 1:
            {
                Box v1;
                v1.displayBoxVolume();
                break;
            }
        case 2:
            {
                int val;
                cout<<"Enter a value : "<<endl;
                cin>>val;
                Box v2(val);
                v2.displayBoxVolume();
                break;
            }
        case 3:
            {
                int val1,val2,val3;
                cout << "Enter the values for length, width and height : " << endl;
                cin >> val1 >> val2 >> val3;
                Box v3(val1,val2,val3);
                v3.displayBoxVolume();
                break;
            }
        default: 
            cout<<"Enter valid value "<<endl;
            break;
    }
}

}
