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
    pair<int, int> dfs(TreeNode* node, int& res){
        if(node == nullptr){
            return {0, 0};
        }

        pair<int, int> l = dfs(node->left, res);
        pair<int, int> r = dfs(node->right, res);

        int sum = l.first + node->val + r.first;
        int count = l.second + 1 + r.second;

        if(sum / count == node->val){
            res += 1;
        }
        
        return {sum, count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};