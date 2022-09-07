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
    void dfs(TreeNode* node, int row, int col, map<int, vector<pair<int, int>>>& valuesAt){
        if(node != nullptr){
            valuesAt[col].emplace_back(row, node->val);
            dfs(node->left, row + 1, col - 1, valuesAt);
            dfs(node->right, row + 1, col + 1, valuesAt);
        }
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> valuesAt;
        dfs(root, 0, 0, valuesAt);
        
        const int COLS = valuesAt.size();
        vector<vector<int>> res(COLS);
        
        int i = 0;
        for(const pair<int, vector<pair<int, int>>>& P: valuesAt){
            vector<pair<int, int>> v = P.second;
            sort(v.begin(), v.end());
            res[i].resize(v.size());
            for(int j = 0; j < (int)v.size(); ++j){
                res[i][j] = v[j].second;
            }
            i += 1;
        }
        
        return res;
    }
};