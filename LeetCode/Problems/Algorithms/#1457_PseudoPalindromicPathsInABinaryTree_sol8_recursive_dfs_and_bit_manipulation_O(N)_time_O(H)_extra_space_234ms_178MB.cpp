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
    void dfs(TreeNode* node, int parityMask, int& res){
        if(node == nullptr){
            return;
        }

        parityMask ^= (1 << node->val);

        if(node->left == nullptr && node->right == nullptr){
            if(!(parityMask & (parityMask - 1))){
                res += 1;
            }
        }

        dfs(node->left, parityMask, res);
        dfs(node->right, parityMask, res);
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
};