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
    void dfs(TreeNode* node, int currentDepth, int targetDepth, int val){
        if(node != nullptr){
            if(currentDepth == targetDepth){
                TreeNode* oldLeftChild = node->left;
                TreeNode* oldRightChild = node->right;
                node->left = new TreeNode(val);
                node->right = new TreeNode(val);
                node->left->left = oldLeftChild;
                node->right->right = oldRightChild;
            }else{
                dfs(node->left, currentDepth + 1, targetDepth, val);
                dfs(node->right, currentDepth + 1, targetDepth, val);
            }
        }
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Special case
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        // DFS
        dfs(root, 1, depth - 1, val);
        
        return root;
    }
};