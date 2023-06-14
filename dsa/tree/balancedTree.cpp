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

    int maxDepth(TreeNode* root)
    {
        int height;
        
        if(root == NULL)
            return 0;

        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);

        height = max(maxLeft, maxRight) + 1;

        return height;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return 1;
            
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);

        int diff = abs(maxLeft - maxRight);
        bool ans1 = (diff<=1);
        
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(ans1 && left && right)
            return 1;
        else
            return 0;
    }
};