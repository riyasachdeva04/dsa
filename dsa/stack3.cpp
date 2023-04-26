#include<iostream>
using namespace std;

class Stack
{
    public:
    int* arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this -> size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        top1++;
        arr[top1] = data;
    }

    void pop1()
    {
        top1--;
    }

    void push2(int data)
    {
        top2--;
        arr[top2] = data;
    }

    void pop2()
    {
        top2++;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty1()
    {
        if(top1 == -1)
            return true;
        else
            return false;
    }

    bool isEmpty2()
    {
        if(top2 == size)
            return true;
        else
            return false;
    }

    int getTop1()
    {
        return arr[top1];
    }

    int getTop2()
    {
        return arr[top2];
    }

};


int main()
{
    Stack st(10);
    st.push1(10);
    st.push1(20);
    st.push1(30);
    st.push2(1);
    st.push2(2);
    st.push2(3);
    st.push2(4);
    st.push2(5);
    st.push2(6);
    st.push2(7);
    st.pop1();
    st.pop2();

    while(!st.isEmpty1())
    {
        cout << st.getTop1() << " ";
        st.pop1();
    }

    cout << endl;
    
     while(!st.isEmpty2())
    {
        cout << st.getTop2() << " ";
        st.pop2();
    }
}