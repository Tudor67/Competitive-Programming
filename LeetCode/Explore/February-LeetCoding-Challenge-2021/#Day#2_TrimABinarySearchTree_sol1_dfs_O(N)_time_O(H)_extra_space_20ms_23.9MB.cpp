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
    void dfs(TreeNode* pred, TreeNode* cur, int low, int high){
        if(cur != NULL){
            if(cur->val < low){
                pred->left = cur->right;
                dfs(pred, cur->right, low, high);
            }else if(cur->val > high){
                if(pred->left == cur){
                    pred->left = cur->left;
                }else{
                    pred->right = cur->left;
                }
                dfs(pred, cur->left, low, high);
            }else{
                dfs(cur, cur->left, low, high);
                dfs(cur, cur->right, low, high);
            }
        }
    }
    
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* virtualRoot = new TreeNode(INT_MAX, root, NULL);
        dfs(virtualRoot, root, low, high);
        return virtualRoot->left;
    }
};