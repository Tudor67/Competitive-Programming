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
    void dfs(TreeNode* root, int val){
        if(root->val > val){
            if(root->left == NULL){
                root->left = new TreeNode(val);
            }else{
                dfs(root->left, val);
            }
        }else{
            if(root->right == NULL){
                root->right = new TreeNode(val);
            }else{
                dfs(root->right, val);
            }
        }
    }
    
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            root = new TreeNode(val);
        }else{
            dfs(root, val);
        }
        return root;
    }
};