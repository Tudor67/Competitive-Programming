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
    pair<long long, long long> computeSubtreeSumAndMaxProduct(TreeNode* root, long long totalSum){
        if(root == nullptr){
            return {0, 0};
        }
        pair<long long, long long> leftP = computeSubtreeSumAndMaxProduct(root->left, totalSum);
        pair<long long, long long> rightP = computeSubtreeSumAndMaxProduct(root->right, totalSum);
        long long subtreeSum = root->val + leftP.first + rightP.first;
        long long maxProd = max({(totalSum - subtreeSum) * subtreeSum, leftP.second, rightP.second});
        return {subtreeSum, maxProd};
    }

public:
    int maxProduct(TreeNode* root) {
        const int MODULO = 1e9 + 7;
        long long totalSum = computeSubtreeSumAndMaxProduct(root, 0).first;
        long long maxProd = computeSubtreeSumAndMaxProduct(root, totalSum).second;
        return maxProd % MODULO;
    }
};