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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL){
            return 0;
        }
        
        int val = 0;
        if(low <= root->val && root->val <= high){
            val = root->val;
        }
        
        if(root->val > low){
            val += rangeSumBST(root->left, low, high);
        }
        
        if(root->val < high){
            val += rangeSumBST(root->right, low, high);
        }
        
        return val;
    }
};