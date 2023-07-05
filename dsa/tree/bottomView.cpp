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

void levelOrderTraversal(Node* root)
{
  queue<Node*> q;

  q.push(root);
  q.push(NULL);

  while(!q.empty())
  {
    // A.
    Node* temp = q.front();

    // B.
    q.pop();

    if(temp == NULL)
    {
      cout << endl;
      if(!q.empty())
      {
        q.push(NULL);
      }
      else
      {
        // C.
        cout << temp->data << " ";

        // D.
        if(temp->left)
          q.push(temp->left);
        if(temp->right)
          q.push(temp->right);        
      }
    }


  }

}

void printBottomView(Node* root)
{
  if(root == NULL)
    return;
  
  // create a map for storing horizontal distance -> top node ka data
  map<int, int> topNode;

  // level order : store pair of node and horizontal distance
  queue< pair<Node*, int> > Q;
  Q.push(make_pair(root, 0));

  while(!Q.empty())
  {
    pair<Node*, int> temp = Q.front();

    Q.pop();

    Node* frontNode = temp.first;
    int hd = temp.second; 

      // create entry
      topNode[hd] = frontNode->data;


    if(frontNode->left)
      Q.push(make_pair(frontNode->left, hd-1));
    if(frontNode->right)
      Q.push(make_pair(frontNode->right, hd+1));    
    
    cout << "Printing ans: " << endl;


  }

    for(auto i: topNode)
    {
      cout << i.first << "->" << i.second << endl;
    } 


}

int main() {

  Node* root = buildTree();

  printBottomView(root);


}