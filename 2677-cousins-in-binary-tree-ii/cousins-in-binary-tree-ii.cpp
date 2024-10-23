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
    TreeNode* replaceValueInTree(TreeNode* root) {
         if (!root) return nullptr;

        // BFS to traverse the tree level by level
        queue<TreeNode*> q;
        q.push(root);
        
        root->val = 0; // root has no cousins, so we set it to 0 initially
        
        while (!q.empty()) {
            int levelSize = q.size();
            int levelSum = 0;
            
            // Store the current level's nodes in a temporary vector
            vector<TreeNode*> levelNodes;
            
            // Traverse the current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                levelNodes.push_back(node);
                
                // Sum all node values at this level
                if (node->left) {
                    levelSum += node->left->val;
                    q.push(node->left);
                }
                if (node->right) {
                    levelSum += node->right->val;
                    q.push(node->right);
                }
            }
            
            // Now, for each node in this level, replace its value with the cousin sum
            for (TreeNode* node : levelNodes) {
                int sumOfCousins = levelSum;
                
                // Subtract the sibling's value if they exist (siblings are not cousins)
                if (node->left) sumOfCousins -= node->left->val;
                if (node->right) sumOfCousins -= node->right->val;
                
                // Assign new values to children
                if (node->left) node->left->val = sumOfCousins;
                if (node->right) node->right->val = sumOfCousins;
            }
        }
        
        return root;
    }
};