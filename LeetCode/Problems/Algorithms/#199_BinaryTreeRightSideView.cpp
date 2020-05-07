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
    void dfs(TreeNode* node, int level, vector<int>& nodes){
        if(node != NULL){
            if(level >= nodes.size()){
                nodes.resize(level + 1);
            }
            nodes[level] = node->val;
            dfs(node->left, level + 1, nodes);
            dfs(node->right, level + 1, nodes);
        }
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> nodes;
        dfs(root, 0, nodes);
        return nodes;
    }
};