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
    int pseudoPalindromicPaths (TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if(root != nullptr){
            q.emplace(root, (1 << root->val));
        }
        
        int res = 0;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int parityMask = q.front().second;
            q.pop();
            
            if(node->left == nullptr && node->right == nullptr){
                int paritySum = __builtin_popcount((unsigned int)parityMask);
                res += (int)(paritySum <= 1);
            }
            
            if(node->left != nullptr){
                q.emplace(node->left, parityMask ^ (1 << node->left->val));
            }
            if(node->right != nullptr){
                q.emplace(node->right, parityMask ^ (1 << node->right->val));
            }
        }
        
        return res;
    }
};