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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans;
        if(root == NULL)
            return 0;
        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = maxDepth(root->left) + maxDepth(root->right);

        ans = max(op1, max(op2, op3));
        return ans;
    }
};