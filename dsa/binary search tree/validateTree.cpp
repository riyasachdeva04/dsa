/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* leftPart;
        TreeNode* rightPart;

        if(root == NULL)
            return true;

        if((!root->left) && (!root->right))
            return true;

        if(root->left)
        {
            leftPart = root->left;
            if(leftPart->val >= root->val)
                return false;
        }
        
        if(root->right)
        {
            rightPart = root->right;
            if(rightPart->val <= root->val)
                return false;
        }
        
    return (isValidBST(root->left) && isValidBST(root->right));

    }  

};