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
    string dfs(TreeNode* root, unordered_map<string, pair<TreeNode*, int>>& rootAndCountOf){
        if(root == nullptr){
            return "$";
        }
        string leftCode = dfs(root->left, rootAndCountOf);
        string rightCode = dfs(root->right, rootAndCountOf);
        string code = "l(" + leftCode + ")" + to_string(root->val) + "r(" + rightCode + ")";
        rootAndCountOf[code].first = root;
        rootAndCountOf[code].second += 1;
        return code;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, pair<TreeNode*, int>> rootAndCountOf;
        dfs(root, rootAndCountOf);

        vector<TreeNode*> res;
        for(const pair<string, pair<TreeNode*, int>>& P: rootAndCountOf){
            TreeNode* codeRoot = P.second.first;
            int codeCount = P.second.second;
            if(codeCount >= 2){
                res.push_back(codeRoot);
            }
        }

        return res;
    }
};