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
    TreeNode* copy(TreeNode* node, int shiftVal){
        if(node == nullptr){
            return nullptr;
        }
        return new TreeNode(node->val + shiftVal, copy(node->left, shiftVal), copy(node->right, shiftVal));
    }

    void clean(TreeNode* node){
        if(node != nullptr){
            clean(node->left);
            clean(node->right);
            delete node;
        }
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        // dp[i]: BSTs with i unique values from range [1 .. i]
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0] = {nullptr};

        for(int i = 1; i <= n; ++i){
            for(int rootVal = 1; rootVal <= i; ++rootVal){
                int leftSize = rootVal - 1;
                int rightSize = i - rootVal;
                for(TreeNode* leftNode: dp[leftSize]){
                    for(TreeNode* rightNode: dp[rightSize]){
                        TreeNode* root = new TreeNode(rootVal);
                        root->left = copy(leftNode, 0);
                        root->right = copy(rightNode, rootVal);
                        dp[i].push_back(root);
                    }
                }
            }
        }

        for(int i = 0; i <= n - 1; ++i){
            for(TreeNode* node: dp[i]){
                clean(node);
            }
        }

        return dp[n];
    }
};