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
    void dfs(TreeNode* node, int depth, vector<int>& res){
        if(node != nullptr){
            if((int)res.size() <= depth){
                res.resize(depth + 1, INT_MIN);
            }
            res[depth] = max(res[depth], node->val);
            dfs(node->left, depth + 1, res);
            dfs(node->right, depth + 1, res);
        }
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};