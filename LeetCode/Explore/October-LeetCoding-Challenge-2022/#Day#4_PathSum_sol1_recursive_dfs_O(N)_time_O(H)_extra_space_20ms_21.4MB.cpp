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
    void dfs(TreeNode* node, int sum, int targetSum, bool& found){
        if(node != nullptr && !found){
            sum += node->val;
            if(node->left == nullptr && node->right == nullptr){
                found = found || (sum == targetSum);
            }else{
                dfs(node->left, sum, targetSum, found);
                dfs(node->right, sum, targetSum, found);
            }
        }
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found = false;
        dfs(root, 0, targetSum, found);
        return found;
    }
};