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
    TreeNode* createParentMapping(TreeNode* root, int target, unordered_map<TreeNode*, TreeNode*> & nodeToParent)
    {
        TreeNode* res = NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front->val == target){
                res = front;
            }

            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    int infectTime(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodeToParent){
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*>q;
        q.push(root);
        visited[root] = true;

        int ans = 0;
        while(!q.empty()){
            bool flag = 0;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode*front = q.front();
                q.pop();

                // push left right and parent node to queue
                if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = true;
                }

                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                if(nodeToParent[front]&&!visited[nodeToParent[front]]){
                    flag=1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=true;
                }
            }
            if(flag == 1)
                ans++;
            
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode = createParentMapping(root, start, nodeToParent);
        return infectTime(targetNode, nodeToParent);
    }
};