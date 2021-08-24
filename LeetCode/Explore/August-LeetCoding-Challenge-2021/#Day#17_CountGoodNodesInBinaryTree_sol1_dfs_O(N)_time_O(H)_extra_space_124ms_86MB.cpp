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
    void dfs(TreeNode* root, int maxVal, int& goodNodes){
        if(root != NULL){
            if(maxVal <= root->val){
                goodNodes += 1;
            }
            dfs(root->left, max(root->val, maxVal), goodNodes);
            dfs(root->right, max(root->val, maxVal), goodNodes);
        }
    }
    
public:
    int goodNodes(TreeNode* root) {
        int goodNodes = 0;
        dfs(root, INT_MIN, goodNodes);
        return goodNodes;
    }
};