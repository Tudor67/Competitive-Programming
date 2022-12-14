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
    void computeSubtreeSum(TreeNode* root, unordered_map<TreeNode*, long long>& subtreeSum){
        if(root == nullptr){
            subtreeSum[nullptr] = 0;
        }else{
            computeSubtreeSum(root->left, subtreeSum);
            computeSubtreeSum(root->right, subtreeSum);
            subtreeSum[root] = root->val + subtreeSum[root->left] + subtreeSum[root->right];
        }
    }

    void computeMaxProduct(TreeNode* root, unordered_map<TreeNode*, long long>& subtreeSum, long long totalSum, long long& maxProd){
        if(root != nullptr){
            computeMaxProduct(root->left, subtreeSum, totalSum, maxProd);
            computeMaxProduct(root->right, subtreeSum, totalSum, maxProd);
            maxProd = max(maxProd, (totalSum - subtreeSum[root]) * subtreeSum[root]);
        }
    }

public:
    int maxProduct(TreeNode* root) {
        const int MODULO = 1e9 + 7;

        unordered_map<TreeNode*, long long> subtreeSum;
        computeSubtreeSum(root, subtreeSum);

        long long maxProd = 0;
        computeMaxProduct(root, subtreeSum, subtreeSum[root], maxProd);

        return maxProd % MODULO;
    }
};