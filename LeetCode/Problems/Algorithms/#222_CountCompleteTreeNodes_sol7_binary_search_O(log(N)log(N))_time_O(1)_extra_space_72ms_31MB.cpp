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
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int maxDepth = -1;
        for(TreeNode* node = root; node != nullptr; node = node->left){
            maxDepth += 1;
        }
        
        int res = 1;
        for(int currentDepth = 0; currentDepth <= maxDepth - 1; ++currentDepth){
            int depth = currentDepth;
            for(TreeNode* node = root->right; node != nullptr; node = node->left){
                depth += 1;
            }
            if(depth == maxDepth){
                res = 2 * res + 1;
                root = root->right;
            }else{
                res = 2 * res;
                root = root->left;
            }
        }
        
        return res;
    }
};