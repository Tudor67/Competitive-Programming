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
    void dfs(TreeNode* root, int level, vector<vector<int>>& nodes){
        if(root != NULL){
            if(level >= nodes.size()){
                nodes.resize(level + 1);
            }
            nodes[level].push_back(root->val);
            dfs(root->left, level + 1, nodes);
            dfs(root->right, level + 1, nodes);
        }
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        dfs(root, 0, nodes);
        for(int level = 1; level < nodes.size(); level += 2){
            reverse(nodes[level].begin(), nodes[level].end());
        }
        return nodes;
    }
};