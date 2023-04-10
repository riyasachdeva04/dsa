#include <iostream>
using namespace std;

class node
{
  public:
  int data;
  node* next;

  node()
  {
    this->data = 0;
    this->next = NULL;
  }

  node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
  
  
  };
  
  void printer(node* &head)
  {
    node* temp;
    temp = head;
    while(temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;

    }
  
  }

  void insertAtHead(node* &head, int data)
  {
    if(head == NULL)
    {
      node* newNode = new node(data);
      head = newNode->next;

    }
    else
    {
    node* newNode  = new node(data);
    newNode -> next = head;
    head = newNode;
    }
  }  

  void insertAtTail(node* &tail, int data)
  {
    node* newNode = new node(data);
    tail -> next = newNode;
    tail = newNode;
  }  

  void insertAtPosition(node* &previous, node* &next, int data)
  {
    
    {
    node* newNode = new node();
    newNode -> data = data;
    previous -> next = newNode;
    newNode -> next = next;
    }
  }

  void insertingAtPos(node* &head, node* &tail, int pos, int data)
  {
    node* current = new node(data);
    int i=1;
    pos = pos-1;
    node* prev = head;
    node* nextnode;
    if(head == NULL)
    {
      head -> next = current;
      tail->next = current;
    }
    else
    {
      while( i< pos)
      {
        prev = prev->next;
        i++;
      }
      nextnode = prev ->next;
      prev->next = current;
      current->next = nextnode;
      
    }
  }


int main() {
  node* first = new node(10);
  node* second = new node(20);
  node* third = new node();
  node* fourth = new node(30);
  node* fifth = new node(40);

  first->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = NULL;

  cout << "Printing LL: " << endl;
  printer(first);
  cout << endl;
  insertAtHead(first, 45);
  printer(first);
  cout << endl;
  insertAtTail(fifth, 70);
  printer(first);
  cout << endl;
  insertAtPosition(first, second, 50);
  printer(first);
  cout << endl;
  insertingAtPos(first, fifth, 3, 29);
  printer(first);
}