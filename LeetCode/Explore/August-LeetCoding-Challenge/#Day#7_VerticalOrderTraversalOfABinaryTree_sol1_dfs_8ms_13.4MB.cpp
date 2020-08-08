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
    void dfs1(TreeNode* node, int x, int& min_x){
        if(node != NULL){
            min_x = min(x, min_x);
            dfs1(node->left, x - 1, min_x);
            dfs1(node->right, x + 1, min_x);
        }
    }
    
    void dfs2(TreeNode* node, int depth, int x, const int& MIN_X, vector<vector<pair<int, int>>>& nodes){
        if(node != NULL){
            if(x - MIN_X >= nodes.size()){
                nodes.resize(x - MIN_X + 1);
            }
            nodes[x - MIN_X].push_back({depth, node->val});
            dfs2(node->left, depth + 1, x - 1, MIN_X, nodes);
            dfs2(node->right, depth + 1, x + 1, MIN_X, nodes);
        }
    }
    
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int min_x = 0;
        dfs1(root, 0, min_x);
        
        vector<vector<pair<int, int>>> nodes;
        dfs2(root, 0, 0, min_x, nodes);
        
        vector<vector<int>> answer(nodes.size());
        for(int i = 0; i < answer.size(); ++i){
            sort(nodes[i].begin(), nodes[i].end());
            for(pair<int, int> p: nodes[i]){
                answer[i].push_back(p.second);
            }
        }
        
        return answer;
    }
};