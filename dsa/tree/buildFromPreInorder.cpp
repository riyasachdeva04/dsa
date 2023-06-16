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

int findPosition(int inorder[], int size, int element)
{
  for(int i = 0; i< size; i++)
    {
      if(inorder[i] == element)
        return i;
    }
  return -1;
}

Node* buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{
  //base case
  if(preIndex >= size || inorderStart > inorderEnd)
    return NULL;

  // step A:
  int element = preorder[preIndex++];
  Node* root = new Node(element);
  int pos = findPosition(inorder, size, element);

  // Step B: root left solve
  root->left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos-1);

  // step C: solve root -> right
  root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos+1, inorderEnd);

  return root;
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

        int inorder[] = {40,20,50,10,60,30,70};
        int preorder[] = {10,20,40,50,30,60,70};
        int size = 7;
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = size-1;

        cout << "Building Tree: " << endl;
        Node* root = buildTreeFromPreOrderInOrder(inorder, preorder,size, preIndex, inorderStart, inorderEnd );

        cout<< endl << "Printing level order traversal " << endl;
        levelOrderTraversal(root);

}