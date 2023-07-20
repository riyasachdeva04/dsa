Geek-O-Lympics
Events
POTD

Refresh

Time (IST)	Status	Lang	Test Cases	Code
2023-07-20 19:54:53	Correct	cpp	11020 / 11020	View
C++ (g++ 5.4)



        


 

Custom Input
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution
{
public:

    vector<int> inorderTraversal(Node* root, vector<int>& ans)
    {

        if(root == NULL)
        {
            return ans;
        }
        

        inorderTraversal(root->left, ans);
        ans.push_back(root->data);
        inorderTraversal(root->right, ans);
        
        return ans;
    }
    
        Node* searchBST(Node* root, int data) {

        if(root == NULL)
        {
            return NULL;
        }

        if(root->data == data)
            return root;
        
        if(data < root->data)
        {
            return searchBST(root->left, data);
        }
        if(data > root->data)
        {
            return searchBST(root->right, data);
        }
        
        return root;
    }

    void populateNext(Node *root)
    {
        //code here
        
        vector<int> ans;
        ans = inorderTraversal(root, ans);
        int size = ans.size();
        
        Node* Node2 = NULL;
        Node* Node1 = searchBST(root, ans[0]);
        
        for(int i=0; i<size-1; i++)
        {
            Node2 = searchBST(root, ans[i+1]);
            
            Node1->next = Node2;
            
            Node1 = Node2;
            
        }
        
        
    }
};