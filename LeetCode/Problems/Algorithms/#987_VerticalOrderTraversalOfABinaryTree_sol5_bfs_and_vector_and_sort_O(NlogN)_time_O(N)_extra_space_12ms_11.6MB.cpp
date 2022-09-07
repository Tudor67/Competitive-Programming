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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> colRowVals;
        queue<tuple<TreeNode*, int, int>> q;
        
        q.emplace(root, 0, 0);
        while(!q.empty()){
            TreeNode* node;
            int row, col;
            tie(node, row, col) = q.front();
            q.pop();
            
            colRowVals.emplace_back(col, row, node->val);
            
            if(node->left != nullptr){
                q.emplace(node->left, row + 1, col - 1);
            }
            if(node->right != nullptr){
                q.emplace(node->right, row + 1, col + 1);
            }
        }
        
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