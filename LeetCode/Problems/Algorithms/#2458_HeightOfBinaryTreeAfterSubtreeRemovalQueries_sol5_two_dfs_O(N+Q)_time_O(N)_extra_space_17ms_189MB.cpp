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
    void dfsLR(TreeNode* node, int height, int& maxHeightLR, vector<int>& maxHeightWithout){
        if(node == nullptr){
            return;
        }
        if(node->val >= (int)maxHeightWithout.size()){
            maxHeightWithout.resize(node->val + 1);
        }
        maxHeightWithout[node->val] = max(maxHeightWithout[node->val], maxHeightLR);
        maxHeightLR = max(maxHeightLR, height);
        dfsLR(node->left, height + 1, maxHeightLR, maxHeightWithout);
        dfsLR(node->right, height + 1, maxHeightLR, maxHeightWithout);
    }

    void dfsRL(TreeNode* node, int height, int& maxHeightRL, vector<int>& maxHeightWithout){
        if(node == nullptr){
            return;
        }
        if(node->val >= (int)maxHeightWithout.size()){
            maxHeightWithout.resize(node->val + 1);
        }
        maxHeightWithout[node->val] = max(maxHeightWithout[node->val], maxHeightRL);
        maxHeightRL = max(maxHeightRL, height);
        dfsRL(node->right, height + 1, maxHeightRL, maxHeightWithout);
        dfsRL(node->left, height + 1, maxHeightRL, maxHeightWithout);
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> maxHeightWithout;

        int maxHeightLR = 0;
        dfsLR(root, 0, maxHeightLR, maxHeightWithout);

        int maxHeightRL = 0;
        dfsRL(root, 0, maxHeightRL, maxHeightWithout);

        const int Q = queries.size();
        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            res[i] = maxHeightWithout[queries[i]];
        }

        return res;
    }
};