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
    void dfs(TreeNode* node, int height, int& maxHeight, vector<int>& maxHeightWithout, bool isLR){
        if(node == nullptr){
            return;
        }
        if(node->val >= (int)maxHeightWithout.size()){
            maxHeightWithout.resize(node->val + 1);
        }
        maxHeightWithout[node->val] = max(maxHeightWithout[node->val], maxHeight);
        maxHeight = max(maxHeight, height);
        if(isLR){
            dfs(node->left, height + 1, maxHeight, maxHeightWithout, isLR);
            dfs(node->right, height + 1, maxHeight, maxHeightWithout, isLR);
        }else{
            dfs(node->right, height + 1, maxHeight, maxHeightWithout, isLR);
            dfs(node->left, height + 1, maxHeight, maxHeightWithout, isLR);
        }
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> maxHeightWithout;

        int maxHeight = 0;
        dfs(root, 0, maxHeight, maxHeightWithout, true);
        maxHeight = 0;
        dfs(root, 0, maxHeight, maxHeightWithout, false);

        const int Q = queries.size();
        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            res[i] = maxHeightWithout[queries[i]];
        }

        return res;
    }
};