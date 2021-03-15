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
    void dfs(TreeNode* node, int currentDepth, const int& TARGET_DEPTH, const int& TARGET_VAL){
        if(node != NULL){
            if(currentDepth + 1 == TARGET_DEPTH){
                node->left = new TreeNode(TARGET_VAL, node->left, NULL);
                node->right = new TreeNode(TARGET_VAL, NULL, node->right);
            }else{
                dfs(node->left, currentDepth + 1, TARGET_DEPTH, TARGET_VAL);
                dfs(node->right, currentDepth + 1, TARGET_DEPTH, TARGET_VAL);
            }
        }
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode* virtualRoot = new TreeNode(0, root, NULL);
        dfs(virtualRoot, 0, d, v);
        return virtualRoot->left;
    }
};