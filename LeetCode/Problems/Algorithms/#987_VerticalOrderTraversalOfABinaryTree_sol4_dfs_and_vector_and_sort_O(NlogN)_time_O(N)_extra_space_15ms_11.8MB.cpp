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
    void dfs(TreeNode* node, int row, int col, vector<tuple<int, int, int>>& colRowVals){
        if(node != nullptr){
            colRowVals.emplace_back(col, row, node->val);
            dfs(node->left, row + 1, col - 1, colRowVals);
            dfs(node->right, row + 1, col + 1, colRowVals);
        }
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> colRowVals;
        dfs(root, 0, 0, colRowVals);
        
        const int N = colRowVals.size();
        sort(colRowVals.begin(), colRowVals.end());
        
        vector<vector<int>> res;
        int p1 = 0;
        for(int p2 = 0; p2 < N; ++p2){
            if(p2 == N - 1 || get<0>(colRowVals[p1]) != get<0>(colRowVals[p2 + 1])){
                res.push_back(vector<int>(p2 - p1 + 1));
                for(int i = 0; i < p2 - p1 + 1; ++i){
                    res.back()[i] = get<2>(colRowVals[i + p1]);
                }
                p1 = p2 + 1;
            }
        }
        
        return res;
    }
};