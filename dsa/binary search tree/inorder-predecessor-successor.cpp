// This program works  when target isn't leaf node else store inorder and traverse the array

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
    this->left = NULL;
    this->right = NULL;
  }
};



Node* insertIntoBST(Node* root, int data)
{
   if(root == NULL) //first node insertion
   {
    root = new Node(data);
    return root;
   }

   if(root->data > data)
   {
    root->left = insertIntoBST(root->left, data);
   }
   else
   {
    root->right = insertIntoBST(root->right, data);
   }

   return root;

}

void takeInput(Node* &root)
{
  int data;
  cin >> data;
  while(data != -1)
  {
    root = insertIntoBST(root, data);
    cin >> data;
  }

}


int getMin(Node* root)
{
  if((root->left == NULL) && (root->right == NULL))
    return root->data;
    
  if(root->left)
  {
    return getMin(root->left);
  }
  return -1;
}
int getMax(Node*root)
{
  if((root->left == NULL) && (root->right == NULL))
    return root->data;

  if (root->right)
    return getMax(root->right);

  return -1;
}

void inorderPredecessor(Node* root, int target)
{
  int ans;

  if (root == NULL)
    return;

  if (root->data == target)
  {
    // predecessor find karo
    if (root->left) // left ka max
    {
      Node* left = root->left;
      ans = getMax(left);
    }
    cout << "Predecessor: " << ans << endl;
    return;
  }


  inorderPredecessor(root->left, target);
  inorderPredecessor(root->right, target);
}

void inorderSuccessor(Node* root, int target)
{
  int ans;

  if (root == NULL)
    return;

  if (root->data == target)
  {
    // predecessor find karo
    if (root->right) // left ka max
    {
      Node* right = root->right;
      ans = getMin(right);
    }
    cout << "Successor: " << ans << endl;
    return;
  }


  inorderSuccessor(root->left, target);
  inorderSuccessor(root->right, target);
}


int main() {
  Node* root = NULL;
  cout << "Enter data for each node";
  takeInput(root);

  inorderPredecessor(root, 5);
  inorderPredecessor(root, 30);
  inorderSuccessor(root, 5);
  inorderSuccessor(root, 30);

  


}