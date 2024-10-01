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
 void solve(vector<int>&vec, TreeNode* root){
        if(root == NULL){
            return;
        }
      
        solve(vec,root->left);
        solve(vec,root->right);
        vec.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
          vector<int>vec;
          solve(vec,root);
          return vec;
    }
};