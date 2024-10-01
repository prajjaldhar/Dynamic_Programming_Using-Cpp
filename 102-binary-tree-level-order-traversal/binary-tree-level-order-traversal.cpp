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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL)
            return result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int>currentLevel;
            for(int i=0;i<levelSize;i++)
            {
                TreeNode * node = q.front();
                q.pop();
                currentLevel.push_back(node->val);
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            result.push_back(currentLevel);
        }
         return result;
    }
   
};