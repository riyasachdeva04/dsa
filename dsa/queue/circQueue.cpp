#include <iostream>
using namespace std;

class CircQueue
{
  int front;
  int rear;
  int size;
  int *arr;

  public:
  CircQueue(int size)
  {
    this->size = size;
    arr = new int[size];
    front = -1;
    rear = -1;
  }

  void push(int data)
  {
    if(rear == size-1 && front ==0)
    {
      cout << " Queue is filled";
    }
    else if(front == rear && rear == -1)
    {
      front = 0;
      rear = 0;
      arr[rear] = data;
    }
    else if(rear == size-1 && front!=0)
    {
      rear = 0;
      arr[rear] = data;
    }
    else{
      rear++;
      arr[rear] = data;
    }
  }

  void pop()
  {
    if(front == rear && rear == -1)
    {
      cout << " Queue empty";
    }

    else if(front == rear )
    {
      arr[front] = -1;
      front = -1;
      rear = -1;
    }
    else if(front == size-1)
    {
      arr[front] = -1;
      front = -1;
      rear = -1;
    }
    else
    {
      arr[front] = -1;
      front++;
    }
  }

  void print()
  {
    for(int i=0; i<size; i++)
      {
        cout << arr[i] << " ";
      }
  }

};

int main() {
  CircQueue Q(5);
  Q.push(1);
  Q.push(2);
  Q.push(3);
  Q.push(4);
  Q.push(5);

  Q.pop();
  Q.push(6);
  Q.print();
}