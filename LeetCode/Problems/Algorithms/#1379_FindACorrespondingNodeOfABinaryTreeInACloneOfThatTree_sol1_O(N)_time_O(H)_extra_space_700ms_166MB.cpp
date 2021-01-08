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
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode*& answer) {
        if(original == target){
            answer = cloned;
        }else if(original != NULL){
            dfs(original->left, cloned->left, target, answer);
            dfs(original->right, cloned->right, target, answer);
        }
    }
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* answer = NULL;
        dfs(original, cloned, target, answer);
        return answer;
    }
};