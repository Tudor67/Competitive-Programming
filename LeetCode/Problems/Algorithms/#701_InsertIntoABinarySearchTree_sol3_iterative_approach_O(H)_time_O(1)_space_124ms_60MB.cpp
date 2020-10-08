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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode(val);
        }
        
        TreeNode* prevNode = root;
        TreeNode* node = root;
        while(node != NULL){
            prevNode = node;
            if(node->val > val){
                node = node->left;
            }else{
                node = node->right;
            }
        }
        
        if(prevNode->val > val){
            prevNode->left = new TreeNode(val);
        }else{
            prevNode->right = new TreeNode(val);
        }
        
        return root;
    }
};