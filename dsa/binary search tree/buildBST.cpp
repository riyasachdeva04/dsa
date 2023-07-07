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

void levelOrderTraversal(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
		
		
	}
}


int main() {
  Node* root = NULL;
  cout << "Enter datas for each node";
  takeInput(root);
  cout << "Printing: " << endl;
  levelOrderTraversal(root);
}