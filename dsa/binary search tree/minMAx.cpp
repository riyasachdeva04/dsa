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

void inOrderTraversal(Node* root)
{
  if(root == NULL)
    return;
  inOrderTraversal(root->left);
  cout << root-> data << " ";
  inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root)
{
  if(root == NULL)
    return;

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
  
}

void PostOrderTraversal(Node* root)
{
  if(root == NULL)
    return;

  preOrderTraversal(root->left);
  preOrderTraversal(root->right); 
  cout << root->data << " ";
}

void getMin(Node*root)
{
  if((root->left == NULL) && (root->right == NULL))
    cout << "Min" << root->data << endl;
    
  if(root->left)
  {
    getMin(root->left);
  }
}

void getMax(Node*root)
{
  if((root->left == NULL) && (root->right == NULL))
    cout << "Max" << root->data << endl;
    
  if(root->right)
  {
    getMax(root->right);
  }
}

void minMax(Node* root)
{
  if(root == NULL)
  {
    return;
  }
  getMin(root);
  getMax(root);

}

int main() {
  Node* root = NULL;
  cout << "Enter datas for each node";
  takeInput(root);
  // cout << "Printing LevelOrder: " << endl;
  // levelOrderTraversal(root);

  // cout << endl << "In Order: ";
  // inOrderTraversal(root);
  // cout << endl << "Pre Order";
  // preOrderTraversal(root);
  // cout << endl << "Post Order";
  // PostOrderTraversal(root);

  // cout << endl;

  minMax(root);
  


}