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
    size_t dfs(TreeNode* root, unordered_map<size_t, pair<TreeNode*, int>>& rootAndCountOf, hash<string>& strHashObj){
        if(root == nullptr){
            return strHashObj("$");
        }
        size_t leftCode = dfs(root->left, rootAndCountOf, strHashObj);
        size_t rightCode = dfs(root->right, rootAndCountOf, strHashObj);
        size_t code = strHashObj("l(" + to_string(leftCode) + ")" + to_string(root->val) + "r(" + to_string(rightCode) + ")");
        rootAndCountOf[code].first = root;
        rootAndCountOf[code].second += 1;
        return code;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<size_t, pair<TreeNode*, int>> rootAndCountOf;
        hash<string> strHashObj;
        dfs(root, rootAndCountOf, strHashObj);

        vector<TreeNode*> res;
        for(const pair<size_t, pair<TreeNode*, int>>& P: rootAndCountOf){
            TreeNode* codeRoot = P.second.first;
            int codeCount = P.second.second;
            if(codeCount >= 2){
                res.push_back(codeRoot);
            }
        }

        return res;
    }
};