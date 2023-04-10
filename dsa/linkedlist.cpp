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
  
  
  friend void printer(node* &head);
  friend void insertAtHead(node* &head, int data);
  
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
    node* newNode  = new node(data);
    newNode -> next = head;
    head = newNode;
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

  return 0;
}