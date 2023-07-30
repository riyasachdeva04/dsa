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

    void inorderTraversal(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL)
            return;

        inorderTraversal(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal(root->right, ans);

    }

    bool getAns(vector<int>& ans, int s, int e, int k)
    {

        if(s>=e)
            return false;
    
        int sum = ans[s] + ans[e];

        if(sum == k)
            return true;
        else if(sum > k)
            return getAns(ans, s, e-1, k);
        else
            return getAns(ans, s+1, e, k);

        return false;
    }

    bool findTarget(TreeNode* root, int k) {

        vector<int> ans;
        inorderTraversal(root, ans);

        int s = 0;
        int e = (ans.size()) - 1;

        return getAns(ans, s, e, k);
    }
};