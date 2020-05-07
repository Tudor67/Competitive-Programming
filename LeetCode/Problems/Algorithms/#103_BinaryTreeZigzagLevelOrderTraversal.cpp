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
    void dfs(TreeNode* node, int level, vector<vector<int>>& nodes){
        if(node != NULL){
            if(level >= nodes.size()){
                nodes.resize(level + 1);
            }
            nodes[level].push_back(node->val);
            dfs(node->left, level + 1, nodes);
            dfs(node->right, level + 1, nodes);
        }
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        dfs(root, 0, nodes);
        for(int i = 1; i < nodes.size(); i += 2){
            reverse(nodes[i].begin(), nodes[i].end());
        }
        return nodes;
    }
};