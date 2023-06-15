#include<iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

bool kthAncestor(Node* root, int k, int p)
{
    if(root == NULL)
        return false;
    
    if(root->data == p)
        return true;
    

    bool leftans = kthAncestor(root->left, k, p);
    bool rightans = kthAncestor(root->right, k, p);

    if(leftans || rightans)
        k--;
    
    if(k==0)
    {
        cout << root->data;
        k = -1;
    }
    return leftans || rightans;
}

Node* buildTree()
{
  int data;
  cout << "Enter root data" << endl;
  cin >> data;
  if(data == -1)
    return NULL;

  // step A, B & C
  Node* root = new Node(data);

  cout << "Enter data for left part of " << data << endl;
  root->left = buildTree();

  cout << "Enter data for right part of " << data << endl;
  root->right = buildTree();

  return root;
  
}


int main()
{
    Node* root;

    root = buildTree();
    cout << kthAncestor(root, 2, 4);
}