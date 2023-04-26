#include<iostream>
using namespace std;

class Stack{
    public:

    int* arr;
    int top;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this -> size = size;
        top = -1;

    }
    // functions

    void push(int data)
    {
        if(top < size - 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stach Overflow";
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow, can't delete";
        }
        else
        {
            top--;
        }
    }

    int getTop()
    {   
        if(top == -1)
        {
            cout << "Stack is empty";
        }
        else
        {
          return arr[top];
        }
        return -1;
    }
    int getSize()
    {
        return top+1;
    }
    bool isEmpty()
    {
        if(top == -1)
            return true;
        else
            return false;
    }
};

int main()
{
    Stack s(10);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while(!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }

    cout << "Size of stack " << s.getSize() << endl;
}