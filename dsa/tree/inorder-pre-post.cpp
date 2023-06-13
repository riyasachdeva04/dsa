#include <iostream>
using namespace std;
#include<queue>

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

void inorderTraversal(Node* root)
{
  if(root == NULL)
    return;
  // LNR
  inorderTraversal(root -> left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

void preorderTraversal(Node* root)
{
  if(root == NULL)
    return;
  // NLR
  cout << root->data << " ";
  preorderTraversal(root -> left);
  preorderTraversal(root->right);
}

void postorderTraversal(Node* root)
{
  if(root == NULL)
    return;
  // LRN
  postorderTraversal(root -> left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}



int main() {

  Node* root;
  root = buildTree();

  cout << endl << "Inorder: ";
  inorderTraversal(root);
  cout << endl << "Preorder: ";
  preorderTraversal(root);
  cout << endl << "Postorder: ";
  postorderTraversal(root);

}
