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
    void dfs(TreeNode* node, int depth, int parent,
             const int& x, int& x_depth, int& x_parent){
        if(node != NULL){
            if(node->val == x){
                x_depth = depth;
                x_parent = parent;
            }
            dfs(node->left, depth + 1, node->val, x, x_depth, x_parent);
            dfs(node->right, depth + 1, node->val, x, x_depth, x_parent);
        }
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int x_depth = -1;
        int x_parent = -1;
        dfs(root, 0, -1, x, x_depth, x_parent);
        
        int y_depth = -1;
        int y_parent = -1;
        dfs(root, 0, -1, y, y_depth, y_parent);
        
        return (x_depth == y_depth && x_parent != y_parent);
    }
};