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
    int getMaxVal(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return max(root->val, max(getMaxVal(root->left), getMaxVal(root->right)));
    }
    
    void dfsLR(TreeNode* root, int level, int& maxLevel, vector<int>& maxLevelLR){
        if(root != nullptr){
            maxLevelLR[root->val] = maxLevel;
            maxLevel = max(maxLevel, level);
            dfsLR(root->left, level + 1, maxLevel, maxLevelLR);
            dfsLR(root->right, level + 1, maxLevel, maxLevelLR);
        }
    }
    
    void dfsRL(TreeNode* root, int level, int& maxLevel, vector<int>& maxLevelRL){
        if(root != nullptr){
            maxLevelRL[root->val] = maxLevel;
            maxLevel = max(maxLevel, level);
            dfsRL(root->right, level + 1, maxLevel, maxLevelRL);
            dfsRL(root->left, level + 1, maxLevel, maxLevelRL);
        }
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int maxVal = getMaxVal(root);
        
        int maxLevel = 0;
        vector<int> maxLevelLR(maxVal + 1);
        dfsLR(root, 0, maxLevel, maxLevelLR);
        
        maxLevel = 0;
        vector<int> maxLevelRL(maxVal + 1);
        dfsRL(root, 0, maxLevel, maxLevelRL);
        
        const int Q = queries.size();
        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            res[i] = max(maxLevelLR[queries[i]], maxLevelRL[queries[i]]);
        }
        
        return res;
    }
};