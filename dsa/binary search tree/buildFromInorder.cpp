#include <iostream>
#include <queue>
using namespace std;

class Node
{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data)
  {
    this->left = NULL;
    this->right = NULL;
    this->data = data;
  }
};

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

Node* buildFromInorder(vector<int> arr, int s, int e)
{
  
  int mid = (s+e)/2;
  int element = arr[mid];
  Node* temp = new Node(element);

  if(s > e)
    return NULL;
  else{
    temp->left = buildFromInorder(arr, s, mid-1);
    temp->right = buildFromInorder(arr, mid+1, e);
  }
  
  return temp;
}


int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  Node* root;
  root = buildFromInorder(arr, 0, 6);
  levelOrderTraversal(root);
}