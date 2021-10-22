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
    void dfs(TreeNode* node, int parent, int depth, unordered_map<int, int>& p, unordered_map<int, int>& d){
        if(node != NULL){
            p[node->val] = parent;
            d[node->val] = depth;
            dfs(node->left, node->val, depth + 1, p, d);
            dfs(node->right, node->val, depth + 1, p, d);
        }
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, int> p;
        unordered_map<int, int> d;
        dfs(root, -1, 0, p, d);
        return (p[x] != p[y] && d[x] == d[y]);
    }
};