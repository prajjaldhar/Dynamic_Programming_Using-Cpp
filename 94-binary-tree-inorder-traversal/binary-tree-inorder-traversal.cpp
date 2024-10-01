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
   vector<int> inorderTraversal(TreeNode* root) {
        vector<int> path;
        

        RecursiveTraversal(path, root);
        return path;
    }

    void RecursiveTraversal(vector<int>& path, TreeNode* node){
        if (node == NULL){
            return;
        }

        RecursiveTraversal(path, node->left);// Go down the full left side of tree

        path.push_back(node->val); // once at the furthest left push back val

        RecursiveTraversal(path, node->right);
    }
};