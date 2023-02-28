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
    const int SHIFT_VAL = 205;
    const int BITS_FOR_TREE_ID = 15;

    int dfs(TreeNode* root, unordered_map<int, pair<TreeNode*, int>>& rootAndCountOf, unordered_map<size_t, int>& treeID){
        if(root == nullptr){
            treeID[0] = 0;
            return treeID[0];
        }
        size_t leftID = dfs(root->left, rootAndCountOf, treeID);
        size_t rightID = dfs(root->right, rootAndCountOf, treeID);
        size_t code = (leftID << (2 * BITS_FOR_TREE_ID)) | (rightID << BITS_FOR_TREE_ID) | (root->val + SHIFT_VAL);
        if(!treeID.count(code)){
            int currentTreeID = treeID.size();
            treeID[code] = currentTreeID;
        }
        rootAndCountOf[treeID[code]].first = root;
        rootAndCountOf[treeID[code]].second += 1;
        return treeID[code];
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<int, pair<TreeNode*, int>> rootAndCountOf;
        unordered_map<size_t, int> treeID;
        dfs(root, rootAndCountOf, treeID);

        vector<TreeNode*> res;
        for(const pair<int, pair<TreeNode*, int>>& P: rootAndCountOf){
            TreeNode* codeRoot = P.second.first;
            int codeCount = P.second.second;
            if(codeCount >= 2){
                res.push_back(codeRoot);
            }
        }

        return res;
    }
};