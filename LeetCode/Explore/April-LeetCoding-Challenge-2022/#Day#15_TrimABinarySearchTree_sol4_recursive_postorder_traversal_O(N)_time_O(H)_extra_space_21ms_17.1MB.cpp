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
    void trimBST(TreeNode* parent, TreeNode* node, int low, int high){
        if(node == NULL){
            return;
        }
        
        trimBST(node, node->left, low, high);
        trimBST(node, node->right, low, high);
        
        if(node->val < low){
            if(parent->left == node){
                parent->left = node->right;
            }else{
                parent->right = node->right;
            }
            node->left = NULL;
            node->right = NULL;
        }else if(high < node->val){
            if(parent->left == node){
                parent->left = node->left;
            }else{
                parent->right = node->left;
            }
            node->left = NULL;
            node->right = NULL;
        }
    }
    
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* prevRoot = new TreeNode(INT_MIN, NULL, root);
        
        trimBST(prevRoot, root, low, high);
        
        root = prevRoot->right;
        prevRoot->right = NULL;
        delete prevRoot;
        
        return root;
    }
};