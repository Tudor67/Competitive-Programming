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
    void dfs(TreeNode* node, int level, vector<vector<TreeNode*>>& nodes){
        if(level >= nodes.size()){
            nodes.resize(level + 1);
        }
        nodes[level].push_back(node);
        
        if(node != NULL){
            dfs(node->left, level + 1, nodes);
            dfs(node->right, level + 1, nodes);
        }
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        vector<vector<TreeNode*>> nodes;
        dfs(root, 0, nodes);
        
        bool is_symmetric = true;
        for(const vector<TreeNode*>& level_nodes: nodes){
            for(int i = 0, j = (int)level_nodes.size() - 1; i < j; ++i, --j){
                bool ok1 = (level_nodes[i] == NULL && level_nodes[j] == NULL);
                bool ok2 = (level_nodes[i] != NULL && level_nodes[j] != NULL &&
                            level_nodes[i]->val == level_nodes[j]->val);
                if(!(ok1 || ok2)){
                    is_symmetric = false;
                }
            }
        }
        
        return is_symmetric;
    }
};