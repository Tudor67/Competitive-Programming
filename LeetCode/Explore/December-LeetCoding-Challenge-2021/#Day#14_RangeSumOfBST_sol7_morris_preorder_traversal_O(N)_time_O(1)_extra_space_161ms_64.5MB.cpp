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
    void updateSum(TreeNode*& node, int& sum, int low, int high){
        if(low <= node->val && node->val <= high){
            sum += node->val;
        }
    }
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left == NULL || cur->val <= low){
                updateSum(cur, sum, low, high);
                cur = cur->right;
            }else{
                TreeNode* pred = cur->left;
                while(pred->right != NULL && pred->right != cur){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    updateSum(cur, sum, low, high);
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