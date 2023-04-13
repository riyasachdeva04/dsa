#include <iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node* prev;
  Node* next;

  Node()
  {
    this -> data = 0;
    this -> next = NULL;
    this -> prev = NULL;
  }

  Node(int data)
  {
    this -> data = data;
    this -> next = NULL;
    this -> prev = NULL;
  }
};

void print(Node* &head)
{
  Node* temp = head;
  while(temp != NULL)
  {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
}

int getLength(Node* &head)
{
  Node* temp = head;
  int len = 0;

  while(temp != NULL)
  {
    len++;
    temp = temp -> next;
  }
  return len;
}

void insertAthead(Node* &head, Node* &tail, int data)
{
  if(head == NULL)
  {
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }

  Node* newNode = new Node(data);
  Node* temp;
  temp = head;
  newNode -> next = temp;
  temp -> prev = newNode;
  head = newNode;

}

void insertAtTail(Node* &head, Node* &tail, int data)
{
  if(head == NULL)
  {
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
  }

  else
  {
      Node* temp = tail;
      Node* newNode = new Node(data);
      temp -> next = newNode;
      newNode -> prev = temp;
      tail = newNode;
  }
}

void insertAtPosition(int pos, Node* &head, Node* &tail, int data)
{
  if(pos == 1)
  {
    insertAthead(head, tail, data);
    return;
  }
  if(pos == getLength(head))
  {
    insertAtTail(head, tail, data);
    return;
  }

  int i = 1;
  Node* prevNode = new Node;
  Node* nextNode = new Node;
  Node* newNode = new Node(data);
  prevNode = head;
  while(i < pos-1)
  {
    prevNode = prevNode -> next;
    i++;
  }

  nextNode = prevNode -> next;
  prevNode -> next = newNode;
  newNode -> prev = prevNode;
  newNode -> next = nextNode;
  nextNode -> prev = newNode;
}



int main() {

  Node* first = new Node(10);
  Node* second = new Node(20);
  Node* third = new Node(30);
  Node* fourth = new Node(40);
  Node* fifth = new Node(50);

  first -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;

  fifth -> prev = fourth;
  fourth -> prev = third;
  third -> prev = second;
  second -> prev = first;

  Node* head = first;
  Node* tail = fifth;
  print(first);
  cout << endl;
  insertAthead(head, tail, 5);
  print(head);
  
  cout << endl;
  insertAtTail(head, tail, 55);
  print(head);

  cout << endl;
  insertAtPosition(3, head, tail, 15);
  print(head);
}