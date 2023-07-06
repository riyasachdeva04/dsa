#include <iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

Node* buildTree()
{
  int data;
  cout << "Enter the data" << endl;
  cin >> data;

  if(data == -1)
    return NULL;
  
  Node* root = new Node(data);
  
  cout << "Enter data for left part of" << data << endl;
  root->left = buildTree();

  cout << "Enter data for right part of" << data << endl;
  root->right = buildTree();

  return root;
}


void printLeftTraversal(Node* root)
{
  if(root == NULL)
    return;

  if((root->left == NULL) && (root->right == NULL))
    return;

  cout << root->data << " ";

  printLeftTraversal(root->left);
}

void printRightTraversal(Node* root)
{
  if(root == NULL)
    return;

  else
  {
    printRightTraversal(root->right);
  }
  
  if((root->left == NULL) && (root->right == NULL))
    return;
  
  cout << root->data << " ";  
}

void printLeafTraversal(Node* root)
{

  if(root == NULL)
    return;
  if(!((root->left == NULL) && (root->right == NULL)))
  {
    printLeafTraversal(root->left);
    printLeafTraversal(root->right);
  }
  else
  {
    cout << root->data << " ";
    return;
  }
  
}

void printBoundaryTraversal(Node* root)
{
  printLeftTraversal(root);
  printLeafTraversal(root);
  printRightTraversal(root);

}



int main() {

  Node* root = buildTree();

  printBoundaryTraversal(root);

}