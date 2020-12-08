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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = root;
        while(newRoot != NULL && newRoot->left != NULL){
            newRoot = newRoot->left;
        }
        
        TreeNode* prev = NULL; // previous node
        TreeNode* cur = root;  // current node
        TreeNode* pred;        // inorder predecessor (the rightmost/max node of left subtree)
        bool isRightSubtree = false;
        while(cur != NULL){
            if(cur->left == NULL){
                prev = cur;
                cur = cur->right;
                isRightSubtree = true;
            }else{
                pred = cur->left;
                while(pred->right != NULL){
                    pred = pred->right;
                }
                pred->right = cur;
                cur = cur->left;
                pred->right->left = NULL;
                if(isRightSubtree){
                    prev->right = cur;
                }
            }
        }
        
        return newRoot;
    }
};