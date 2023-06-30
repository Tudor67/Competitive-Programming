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
    void dfs(TreeNode* node, int level, vector<int>& sumAt){
        if(node != nullptr){
            if(level >= (int)sumAt.size()){
                sumAt.resize(level + 1);
            }
            sumAt[level] += node->val;
            dfs(node->left, level + 1, sumAt);
            dfs(node->right, level + 1, sumAt);
        }
    }

public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sumAt;
        dfs(root, 1, sumAt);
        return max_element(sumAt.begin() + 1, sumAt.end()) - sumAt.begin();
    }
};