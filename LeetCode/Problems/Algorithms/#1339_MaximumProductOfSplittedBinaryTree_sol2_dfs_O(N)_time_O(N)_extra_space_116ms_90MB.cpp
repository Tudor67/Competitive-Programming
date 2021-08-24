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
    long long computeSum(TreeNode* root, vector<long long>& subtreeSums){
        if(root == NULL){
            return 0;
        }
        long long subtreeSum = (long long)root->val + computeSum(root->left, subtreeSums) + computeSum(root->right, subtreeSums);
        subtreeSums.push_back(subtreeSum);
        return subtreeSum;
    }
    
public:
    int maxProduct(TreeNode* root) {
        vector<long long> subtreeSums;
        computeSum(root, subtreeSums);
        
        const long long MODULO = 1e9 + 7;
        const long long TOTAL_SUM = subtreeSums.back();
        long long maxProd = 0;
        for(long long subtreeSum: subtreeSums){
            maxProd = max(maxProd, subtreeSum * (TOTAL_SUM - subtreeSum));
        }
        
        return (maxProd % MODULO);
    }
};