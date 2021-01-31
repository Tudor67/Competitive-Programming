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
    void dfs(TreeNode* root, int x, int& minX){
        if(root != NULL){
            minX = min(x, minX);
            dfs(root->left, x - 1, minX);
            dfs(root->right, x + 1, minX);
        }
    }
    
    void verticalTraversal(TreeNode* root, int x, int y, int minX, vector<vector<pair<int, int>>>& verticalTraversalPairs){
        if(root != NULL){
            int idx = x - minX;
            if(idx >= verticalTraversalPairs.size()){
                verticalTraversalPairs.resize(idx + 1);
            }
            verticalTraversalPairs[idx].push_back({y, root->val});
            verticalTraversal(root->left, x - 1, y + 1, minX, verticalTraversalPairs);
            verticalTraversal(root->right, x + 1, y + 1, minX, verticalTraversalPairs);
        }
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int minX = 0;
        dfs(root, 0, minX);
        
        vector<vector<pair<int, int>>> verticalTraversalPairs;
        verticalTraversal(root, 0, 0, minX, verticalTraversalPairs);
        
        vector<vector<int>> answer(verticalTraversalPairs.size());
        for(int i = 0; i < (int)verticalTraversalPairs.size(); ++i){
            vector<pair<int, int>>& vp = verticalTraversalPairs[i];
            sort(vp.begin(), vp.end());
            for(int j = 0; j < (int)vp.size(); ++j){
                answer[i].push_back(vp[j].second);
            }
        }
        
        return answer;
    }
};