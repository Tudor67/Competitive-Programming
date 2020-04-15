/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int dfs(int k, TreeNode* node, int& ans){
        if(node == NULL){
            return k - 1;
        }else{
            int left_depth  = dfs(k + 1, node->left, ans);
            int right_depth = dfs(k + 1, node->right, ans);
            ans = max({ans, left_depth + right_depth - 2 * k});
            return max(left_depth, right_depth);
        }
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(0, root, ans);
        return ans;
    }
};