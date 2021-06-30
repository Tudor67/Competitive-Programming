/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent, unordered_map<TreeNode*, int>& level){
        if(node != NULL){
            for(TreeNode* child: {node->left, node->right}){
                parent[child] = node;
                level[child] = 1 + level[node];
                dfs(child, parent, level);
            }
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, int> level;
        
        parent[root] = NULL;
        level[root] = 0;
        
        dfs(root, parent, level);
        
        while(level[p] != level[q]){
            if(level[p] < level[q]){
                q = parent[q];
            }else{
                p = parent[p];
            }
        }
        
        while(p != q){
            p = parent[p];
            q = parent[q];
        }
        
        return p;
    }
};