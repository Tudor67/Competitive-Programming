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
    TreeNode* clone(TreeNode* node){
        if(node == nullptr){
            return nullptr;
        }
        return new TreeNode(node->val, clone(node->left), clone(node->right));
    }

    void clean(TreeNode* node){
        if(node != nullptr){
            clean(node->left);
            clean(node->right);
            delete node;
        }
    }

public:
    vector<TreeNode*> allPossibleFBT(int N) {
        vector<vector<TreeNode*>> dp(N + 1);
        dp[0] = {nullptr};
        dp[1] = {new TreeNode()};

        for(int i = 3; i <= N; ++i){
            for(int j = 1; j <= i - 2; ++j){
                int leftSize = j;
                int rightSize = i - 1 - j;
                for(TreeNode* leftNode: dp[leftSize]){
                    for(TreeNode* rightNode: dp[rightSize]){
                        TreeNode* root = new TreeNode();
                        root->left = clone(leftNode);
                        root->right = clone(rightNode);
                        dp[i].push_back(root);
                    }
                }
            }
        }

        for(int i = 0; i <= N - 1; ++i){
            for(TreeNode* node: dp[i]){
                clean(node);
            }
        }

        return dp[N];
    }
};