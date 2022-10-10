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
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*, int>> q;
        if(root != nullptr){
            q.emplace(root, root->val);
        }
        
        bool found = false;
        while(!q.empty() && !found){
            TreeNode* node = q.front().first;
            int sum = q.front().second;
            q.pop();
            
            if(node->left == nullptr && node->right == nullptr){
                found = found || (sum == targetSum);
            }
            
            if(node->left != nullptr){
                q.emplace(node->left, sum + node->left->val);
            }
            if(node->right != nullptr){
                q.emplace(node->right, sum + node->right->val);
            }
        }
        
        return found;
    }
};