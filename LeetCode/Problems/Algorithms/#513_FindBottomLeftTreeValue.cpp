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
    void dfs(TreeNode* node, int k, int& max_depth, int& bottom_left_value){
        if(node != NULL){
            if(k > max_depth){
                max_depth = k;
                bottom_left_value = node->val;
            }
            dfs(node->left, k + 1, max_depth, bottom_left_value);
            dfs(node->right, k + 1, max_depth, bottom_left_value);
        }
    }
    
public:
    int findBottomLeftValue(TreeNode* root) {
        int max_depth = -1;
        int bottom_left_value = -1;
        dfs(root, 0, max_depth, bottom_left_value);
        return bottom_left_value;
    }
};