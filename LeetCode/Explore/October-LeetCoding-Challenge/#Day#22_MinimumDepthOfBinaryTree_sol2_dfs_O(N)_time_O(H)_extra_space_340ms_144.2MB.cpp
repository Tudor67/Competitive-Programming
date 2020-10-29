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
    void dfs(TreeNode* node, int level, int& minimumDepth){
        if(level >= minimumDepth){
            return;
        }
        if(node->left == NULL && node->right == NULL){
            minimumDepth = level;
            return;
        }
        if(node->left != NULL){
            dfs(node->left, level + 1, minimumDepth);
        }
        if(node->right != NULL){
            dfs(node->right, level + 1, minimumDepth);
        }
    }
    
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int minimumDepth = INT_MAX;
        dfs(root, 1, minimumDepth);
        return minimumDepth;
    }
};