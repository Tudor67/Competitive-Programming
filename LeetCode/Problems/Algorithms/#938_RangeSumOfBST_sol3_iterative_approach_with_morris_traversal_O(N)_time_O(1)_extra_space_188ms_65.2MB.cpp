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
    void updateSum(int& sum, int val, int low, int high){
        if(low <= val && val <= high){
            sum += val;
        }
    }
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        TreeNode* cur = root;
        TreeNode* pred = NULL;
        while(cur != NULL){
            if(cur->left == NULL){
                updateSum(sum, cur->val, low, high);
                cur = cur->right;
            }else{
                pred = cur->left;
                while(pred->right != NULL && pred->right != cur){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    updateSum(sum, cur->val, low, high);
                    pred->right = cur;
                    cur = cur->left;
                }else{
                    pred->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return sum;
    }
};