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
    void dfs(TreeNode* root, vector<int>& leafValues){
        if(root != nullptr){
            if(root->left == nullptr && root->right == nullptr){
                leafValues.push_back(root->val);
            }
            dfs(root->left, leafValues);
            dfs(root->right, leafValues);
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValues1;
        dfs(root1, leafValues1);

        vector<int> leafValues2;
        dfs(root2, leafValues2);

        return (leafValues1 == leafValues2);
    }
};