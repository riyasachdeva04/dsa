#include <iostream>
using namespace std;
#include<vector>

class Queue
{
  int front;
  int rear;
  int size;
  int* arr;

  public:
  Queue(int size)
  {
    front = 0;
    rear = 0;
    this->size = size;
    arr = new int[size];
  }

  void push(int data)
  {
    if(rear == size)
    {
      cout << "Queue is full";
      return;
    }

    if(front == rear)
    {
      front = 0;
      rear = 0;
    }
    arr[rear] = data;
    rear++;

  }

  void pop()
  {
    if(isEmpty())
    {
      cout << "Queue is already empty";
    }
    else
    {
      arr[front] = -1;
      front++;
    }
  }

  bool isEmpty()
  {
    if(front == rear)
      return true;
    else
      return false;
  }

  int getFront()
  {
    return arr[front];
  }
};

int main() {
  Queue q(5);
  q.push(5);
  q.push(10);
  q.push(15);
  q.push(20);
  q.push(25);
  q.pop();
  cout << q.getFront() << endl;
  if(q.isEmpty())
  {
    cout << "Queue is empty!";
  }
  else
    cout << "Queue is not empty!!";
}