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
    void dfs(TreeNode* node, int level, vector<vector<int>>& res){
        if(node != NULL){
            if((int)res.size() <= level){
                res.resize(level + 1);
            }
            res[level].push_back(node->val);
            dfs(node->left, level + 1, res);
            dfs(node->right, level + 1, res);
        }
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
};