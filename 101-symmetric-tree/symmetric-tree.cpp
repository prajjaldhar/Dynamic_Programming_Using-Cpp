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
   bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true; // An empty tree is symmetric.
        }
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true; // Both nodes are NULL, they are symmetric.
        }
        if (!p || !q) {
            return false; // One node is NULL and the other is not, they are not symmetric.
        }
        return (p->val == q->val)
         && isMirror(p->left, q->right) 
         && isMirror(p->right,  q->left);
    }
};