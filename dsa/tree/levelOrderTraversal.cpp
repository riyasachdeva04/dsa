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

void levelOrderTraversal(Node* root)
{
  queue<Node*> Q;
  Q.push(root);

  Q.push(NULL);

  while(!Q.empty())
    {
      // A temp
      Node* temp = Q.front();

      // B pop
      Q.pop();
      
      if(temp == NULL)
      {
        cout << endl ;

        if(!Q.empty())
          Q.push(NULL);
      }

      else
      {

  
        // C print
        cout << temp->data << " ";
  
        // D print
        if(temp->left)
        {
          Q.push(temp->left);
        }
        if(temp->right)
        {
          Q.push(temp->right);
        }
      }


    }
  
}



int main() {

  Node* root;
  root = buildTree();
  levelOrderTraversal(root);
  
}