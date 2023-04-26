#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        this -> data = 0;
        this -> next = NULL;
        this -> prev =NULL;
    }

    Node(int data)
    {
        this ->data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node()
    {
        cout << "Node with value " << this->data << " deleted" << endl;
    }

};


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

void print(Node* &head)
{
  Node* temp = head;
  while(temp != NULL)
  {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
}


void deleteNode(int pos, Node* &head, Node* &tail)
{
  


    if(pos == 1)
    {
    
        Node* nextNode = new Node;
        Node* temp = head;
        nextNode = temp -> next;
        head = nextNode;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;
    }

    if(pos == getLength(head))
    {
        Node* temp = new Node;
        Node* prevNode = new Node;
        temp = tail;
        prevNode = tail -> prev;
        prevNode -> next = NULL;
        temp -> prev = NULL;
        tail = prevNode;
        delete temp;
        return;
    }

    Node* temp = new Node;
    Node* nextNode = new Node;
    Node* prevNode = new Node;

    int i = 1;
    prevNode = head;
    while(i < pos-1)
    {
        prevNode = prevNode -> next;
        i++;
    }

    temp = prevNode -> next;
    nextNode = temp ->next;
    temp -> prev = NULL;
    temp -> next = NULL;
    nextNode = prevNode -> next;
    prevNode = nextNode -> prev;
    delete temp;
}

int main()
{
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

    Node* head = new Node;
    Node* tail = new Node;
    head = first;
    tail = fifth;

    print(head);
    cout << endl;
    deleteNode(5, head, tail);
    print(head);

}