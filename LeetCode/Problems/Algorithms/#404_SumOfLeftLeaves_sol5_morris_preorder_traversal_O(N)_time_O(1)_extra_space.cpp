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
    int sumOfLeftLeaves(TreeNode* root) {
        int leftLeavesSum = 0;
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                cur = cur->right;
            }else{
                TreeNode* pred = cur->left;
                while(pred->right != NULL && pred->right != cur){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = cur;
                    cur = cur->left;
                }else{
                    if(cur->left == pred && pred->left == NULL){
                        leftLeavesSum += pred->val;
                    }
                    pred->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return leftLeavesSum;
    }
};