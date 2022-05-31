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
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& res){
        if(original == NULL || res != NULL){
            return;
        }else if(original == target){
            res = cloned;
        }else{
            dfs(original->left, cloned->left, target, res);
            dfs(original->right, cloned->right, target, res);
        }
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res = NULL;
        dfs(original, cloned, target, res);
        return res;
    }
};