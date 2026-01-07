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
    long long dfs(TreeNode* node, long long& maxProduct, const long long TOTAL_SUM){
        if(node == nullptr){
            return 0;
        }
        
        long long subtreeSum = node->val + dfs(node->left, maxProduct, TOTAL_SUM)
                                         + dfs(node->right, maxProduct, TOTAL_SUM);
        maxProduct = max(maxProduct, subtreeSum * (TOTAL_SUM - subtreeSum));
        
        return subtreeSum;
    }

public:
    int maxProduct(TreeNode* root) {
        long long maxProduct = 0;
        long long totalSum = dfs(root, maxProduct, 0);

        dfs(root, maxProduct, totalSum);

        return maxProduct % 1'000'000'007;
    }
};