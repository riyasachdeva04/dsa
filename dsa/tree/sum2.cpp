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
    void solve(TreeNode* root, int targetSum, int currSum, vector<int>& path, vector<vector<int>>& ans) {
        if (root == nullptr)
            return;

        currSum += root->val;
        path.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            if (currSum == targetSum)
                ans.push_back(path);
        } else {
            solve(root->left, targetSum, currSum, path, ans);
            solve(root->right, targetSum, currSum, path, ans);
        }

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, targetSum, 0, path, ans);
        return ans;
    }
};