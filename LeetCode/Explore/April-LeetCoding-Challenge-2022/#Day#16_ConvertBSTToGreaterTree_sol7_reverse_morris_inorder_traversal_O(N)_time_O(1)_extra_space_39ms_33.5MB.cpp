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
    void updateSumAndNodeVal(TreeNode* node, int& sum){
        sum += node->val;
        node->val = sum;
    }
    
public:
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* succ = NULL;
        int sum = 0;
        while(curr != NULL){
            if(curr->right == NULL){
                updateSumAndNodeVal(curr, sum);
                curr = curr->left;
            }else{
                succ = curr->right;
                while(succ->left != NULL && succ->left != curr){
                    succ = succ->left;
                }
                if(succ->left == NULL){
                    succ->left = curr;
                    curr = curr->right;
                }else{
                    succ->left = NULL;
                    updateSumAndNodeVal(curr, sum);
                    curr = curr->left;
                }
            }
        }
        return root;
    }
};