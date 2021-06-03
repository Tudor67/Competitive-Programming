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
private:
    pair<int, int> max_sum(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        
        if(root->left == NULL && root->right == NULL){
            return {root->val, 0};
        }
        
        pair<int, int> left_sum = max_sum(root->left);
        pair<int, int> right_sum = max_sum(root->right);
        
        int left_sum_with_root = left_sum.first;
        int left_sum_without_root = left_sum.second;
        int right_sum_with_root = right_sum.first;
        int right_sum_without_root = right_sum.second;
        
        int current_sum_with_root = root->val + left_sum_without_root + right_sum_without_root;
        int current_sum_without_root = max(left_sum_with_root, left_sum_without_root) +
                                       max(right_sum_with_root, right_sum_without_root);
        
        return {current_sum_with_root, current_sum_without_root};
    }
    
public:
    int rob(TreeNode* root) {
        pair<int, int> sum = max_sum(root);
        return max(sum.first, sum.second);
    }
};