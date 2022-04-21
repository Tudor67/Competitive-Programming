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
    void updateResult(TreeNode* curr, TreeNode*& newRoot, TreeNode*& resTail){
        if(newRoot == NULL){
            newRoot = curr;
        }
        if(resTail != NULL){
            curr->left = NULL;
            resTail->right = curr;
        }
        resTail = curr;
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* newRoot = NULL;
        TreeNode* resTail = NULL;
        
        TreeNode* curr = root;
        TreeNode* pred = NULL;
        while(curr != NULL){
            if(curr->left == NULL){
                updateResult(curr, newRoot, resTail);
                curr = curr->right;
            }else{
                pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = NULL;
                    updateResult(curr, newRoot, resTail);
                    curr = curr->right;
                }
            }
        }
        
        return newRoot;
    }
};