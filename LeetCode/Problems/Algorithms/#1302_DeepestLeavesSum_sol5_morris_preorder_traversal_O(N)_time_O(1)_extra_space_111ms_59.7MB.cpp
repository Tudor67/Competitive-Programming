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
    void updateSum(TreeNode* curr, int depth, int& maxDepth, int& sum){
        if(depth == maxDepth){
            sum += curr->val;
        }else if(depth > maxDepth){
            maxDepth = depth;
            sum = curr->val;
        }
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = 0;
        int maxDepth = -1;
        int sum = 0;
        
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                updateSum(curr, depth, maxDepth, sum);
                curr = curr->right;
                depth += 1;
            }else{
                TreeNode* pred = curr->left;
                int delta = 1;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                    delta += 1;
                }
                if(pred->right == NULL){
                    updateSum(curr, depth, maxDepth, sum);
                    pred->right = curr;
                    curr = curr->left;
                    depth += 1;
                }else{
                    pred->right = NULL;
                    curr = curr->right;
                    depth -= delta;
                }
            }
        }
        
        return sum;
    }
};