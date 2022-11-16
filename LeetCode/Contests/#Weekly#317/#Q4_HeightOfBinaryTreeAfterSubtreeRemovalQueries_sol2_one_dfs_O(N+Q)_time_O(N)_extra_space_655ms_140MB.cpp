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
    void dfs(TreeNode* root, int level, vector<int>& levelOf,
             vector<int>& valToSubtreeMaxLevel, vector<pair<int, int>>& levelToSubtreeMaxLevel){
        if(root != nullptr){
            if(root->val >= (int)valToSubtreeMaxLevel.size()){
                levelOf.resize(root->val + 1);
                valToSubtreeMaxLevel.resize(root->val + 1);
            }
            if(level >= (int)levelToSubtreeMaxLevel.size()){
                levelToSubtreeMaxLevel.resize(level + 1);
            }
            
            dfs(root->left, level + 1, levelOf, valToSubtreeMaxLevel, levelToSubtreeMaxLevel);
            dfs(root->right, level + 1, levelOf, valToSubtreeMaxLevel, levelToSubtreeMaxLevel);
            
            levelOf[root->val] = level;
            valToSubtreeMaxLevel[root->val] = level;
            for(TreeNode* child: {root->left, root->right}){
                if(child != nullptr){
                    valToSubtreeMaxLevel[root->val] = max(valToSubtreeMaxLevel[root->val], valToSubtreeMaxLevel[child->val]);
                }
            }
            
            if(valToSubtreeMaxLevel[root->val] > levelToSubtreeMaxLevel[level].first){
                levelToSubtreeMaxLevel[level].second = levelToSubtreeMaxLevel[level].first;
                levelToSubtreeMaxLevel[level].first = valToSubtreeMaxLevel[root->val];
            }else if(valToSubtreeMaxLevel[root->val] > levelToSubtreeMaxLevel[level].second){
                levelToSubtreeMaxLevel[level].second = valToSubtreeMaxLevel[root->val];
            }
        }
    }
    
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> levelOf;
        vector<int> valToSubtreeMaxLevel;
        vector<pair<int, int>> levelToSubtreeMaxLevel;
        dfs(root, 0, levelOf, valToSubtreeMaxLevel, levelToSubtreeMaxLevel);
        
        const int Q = queries.size();
        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int level = levelOf[queries[i]];
            if(valToSubtreeMaxLevel[queries[i]] == levelToSubtreeMaxLevel[level].first){
                res[i] = max(level - 1, levelToSubtreeMaxLevel[level].second);
            }else{
                res[i] = max(level - 1, levelToSubtreeMaxLevel[level].first);
            }
        }
        
        return res;
    }
};