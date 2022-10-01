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
    void dfs(TreeNode* node, int sum, int targetSum, vector<int>& path, vector<vector<int>>& res){
        if(node != nullptr){
            sum += node->val;
            path.push_back(node->val);
            if(sum == targetSum && node->left == nullptr && node->right == nullptr){
                res.push_back(path);
            }
            dfs(node->left, sum, targetSum, path, res);
            dfs(node->right, sum, targetSum, path, res);
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(root, 0, targetSum, path, res);
        return res;
    }
};