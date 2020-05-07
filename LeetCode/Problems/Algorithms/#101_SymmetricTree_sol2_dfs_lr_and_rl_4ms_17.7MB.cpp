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
    void dfs_lr(TreeNode* node, vector<TreeNode*>& nodes_lr){
        nodes_lr.push_back(node);
        if(node != NULL){
            dfs_lr(node->left, nodes_lr);
            dfs_lr(node->right, nodes_lr);
        }
    }
    
    void dfs_rl(TreeNode* node, vector<TreeNode*>& nodes_rl){
        nodes_rl.push_back(node);
        if(node != NULL){
            dfs_rl(node->right, nodes_rl);
            dfs_rl(node->left, nodes_rl);
        }
    }
    
    bool equal(TreeNode* node1, TreeNode* node2){
        return (node1 == node2 || (node1 && node2 && node1->val == node2->val));
    }

public:
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> nodes_lr;
        vector<TreeNode*> nodes_rl;
        
        dfs_lr(root, nodes_lr);
        dfs_rl(root, nodes_rl);
        
        bool is_symmetric = true;
        for(int i = 0; i < nodes_lr.size(); ++i){
            if(!equal(nodes_lr[i], nodes_rl[i])){
                is_symmetric = false;
            }
        }
        
        return is_symmetric;
    }
};