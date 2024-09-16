/*
	Name - Harsh Dixit
	Rollno - 86691
	KD1-86691-Harsh
*/

#include <iostream>
using namespace std;


class Stack{

 int* arr;
 int top;
 int size;

public:
Stack(){

}
Stack(int arrSize=5){
    
    arr=new int[arrSize];
    top=-1;
    size=arrSize;
}

void push(int x){
    if (isFull())
    {
        cout<<"Stack is full"<<endl;
        return ;
    }
    
    arr[++top]=x;
    cout<<x<<" pushed into stack"<<endl;

}

int pop(){
    if (isEmpty())
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    cout<<arr[top]<<" poped from stack"<<endl;
    return arr[top--];
}

int peek(){
    if (isEmpty())
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return arr[top];
}

bool isEmpty(){

    return top == -1;
}

bool isFull(){

    return top == size - 1;


}

void printStack(){
     if (isEmpty())
    {
        cout<<"Stack is empty"<<endl;
        return;
    }
    cout<<"__"<<endl;
    for (int i = top; i >=0; i--)
    {
        cout<<"| "<<arr[i]<<endl;

    }
    cout<<"__"<<endl;


}


};

int main(){


	int choice;
	int sizeOfStack;
	cout<<"Enter size of stack"<<endl;
	cin>>sizeOfStack;
	Stack s(sizeOfStack);
 


while (1)
{


        cout << "Enter your choice" << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Print stack" << endl;
        cout << "5.EXIT" << endl;
        cin>>choice;

        switch (choice)
        {
        case 1:{
            
            int x;
            cout<<"Enter element to push."<<endl;
            cin>>x;
            s.push(x);
            break;
        }
        case 2:{
            
            s.pop();
            break;
        }
        case 3:{
           
            cout<<s.peek()<<" is top element of stack"<<endl;
            break;
        }
        case 4:{
           
            s.printStack();
            break;
        }
        case 5:{
            return 0;
            break;
        }
        
        default:
            cout<<"Wrong choice"<<endl;
            break;
        }
}


    return 0;
}
