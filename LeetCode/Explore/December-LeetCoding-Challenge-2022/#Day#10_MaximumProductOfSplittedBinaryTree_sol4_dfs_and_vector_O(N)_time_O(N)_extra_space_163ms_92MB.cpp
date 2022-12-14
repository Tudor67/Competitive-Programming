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
    long long computeSubtreeSum(TreeNode* root, vector<long long>& subtreeSums){
        long long subtreeSum = 0;
        if(root != nullptr){
            subtreeSum = root->val + computeSubtreeSum(root->left, subtreeSums) + computeSubtreeSum(root->right, subtreeSums);
            subtreeSums.push_back(subtreeSum);
        }
        return subtreeSum;
    }

public:
    int maxProduct(TreeNode* root) {
        const int MODULO = 1e9 + 7;

        vector<long long> subtreeSums;
        computeSubtreeSum(root, subtreeSums);
        long long totalSum = subtreeSums.back();

        long long maxProd = 0;
        for(long long subtreeSum: subtreeSums){
            maxProd = max(maxProd, (totalSum - subtreeSum) * subtreeSum);
        }

        return maxProd % MODULO;
    }
};