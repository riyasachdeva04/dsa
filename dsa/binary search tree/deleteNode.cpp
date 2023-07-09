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

Node* findNodeInBST(Node* root, int target)
{
  // base case
  if(root == NULL)
    return NULL;

  if(root->data == target)
    return root;

  if(target > root->data)
  {
    // right search
    return findNodeInBST(root->right, target);
  }
  else
  {
    return findNodeInBST(root->left, target);
  }
}


Node* deleteNodeInBST(Node* root, int target)
{
  // base case
  if(root == NULL)
    return root;

  // step 1
  Node* temp = findNodeInBST(root, target);

  // cases for deletion
  if(temp->left == NULL && temp->right == NULL)
  {
    delete temp;
    return NULL;
  }
  else if(temp->left == NULL)
  {
    Node* child = temp->right;
    delete temp;
    return child;
  }
  else if(temp->right == NULL)
  {
    Node* child = temp->left;
    delete temp;
    return child;
  }
  else
  {
    // dono child exist karte 
    // finding predecessor inorder of left subtree
    int inOrderPre = getMax(temp->left);
    temp->data = inOrderPre;
    temp-> left = deleteNodeInBST(temp->left, inOrderPre); 
    return root;
  }
}


int main() {
  Node* root = NULL;
  cout << "Enter data for each node";
  takeInput(root);

  levelOrderTraversal(root);
  deleteNodeInBST(root, 150);
  levelOrderTraversal(root);

}