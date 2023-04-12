#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node()
    {
        this->next = NULL;
        this->data = 0;
    }

    Node(int data)
    {
        this->next = NULL;
        this->data = data;
    }

    
};

void print(Node* &head)
{
    Node* temp;
    temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int findlength(Node* &head)
{
    Node* temp;
    temp = head;
    int len = 0;

    while(temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void deleteNode(Node* &head, Node* &tail, int pos)
{
    if(pos == 1)
    {
        Node* temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findlength(head);

    if(pos == len)
    {
        Node* prev;
        prev = head;

        int i = 1;
        while(i<pos-1)
        {
            prev = prev->next;
            i++;
        }

        Node* temp;
        temp = tail;
        prev->next = NULL;
        delete temp;
        return;
    }

    Node* curr;
    Node* prev;
    Node* currnext;
    prev = head;
    int i=1;
    while(i<pos-1)
    {
        prev = prev->next;
        i++;
    }

    curr = prev->next;
    currnext = curr->next;

    prev-> next = currnext;
    curr->next = NULL;
    delete curr;
}


int main()
{

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    Node* head = first;
    Node* tail = fifth;

    first->next = second;
    second->next = third;
    third->next=fourth;
    fourth->next=fifth;

    deleteNode(head, tail, 3);
    print(head);

}