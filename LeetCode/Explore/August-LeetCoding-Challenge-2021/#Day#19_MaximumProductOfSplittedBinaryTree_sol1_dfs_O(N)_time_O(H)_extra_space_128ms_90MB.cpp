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
    long long computeSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return (long long)root->val + computeSum(root->left) + computeSum(root->right);
    }
    
    long long dfs(TreeNode* root, const long long& TOTAL_SUM, long long& maxProd){
        if(root == NULL){
            return 0;
        }
        long long leftSum = dfs(root->left, TOTAL_SUM, maxProd);
        long long rightSum = dfs(root->right, TOTAL_SUM, maxProd);
        long long leftProd = leftSum * (TOTAL_SUM - leftSum);
        long long rightProd = rightSum * (TOTAL_SUM - rightSum);
        maxProd = max({maxProd, leftProd, rightProd});
        return (long long)root->val + leftSum + rightSum;
    }
    
public:
    int maxProduct(TreeNode* root) {
        const long long MODULO = 1e9 + 7;
        const long long TOTAL_SUM = computeSum(root);
        
        long long maxProd = 0;
        dfs(root, TOTAL_SUM, maxProd);
        
        return (maxProd % MODULO);
    }
};