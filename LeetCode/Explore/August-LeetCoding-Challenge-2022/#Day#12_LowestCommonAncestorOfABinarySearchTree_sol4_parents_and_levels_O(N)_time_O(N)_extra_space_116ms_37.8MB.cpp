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
    void dfs(int level, TreeNode* parent, TreeNode* node,
             unordered_map<TreeNode*, TreeNode*>& parentOf, unordered_map<TreeNode*, int>& levelOf){
        if(node != nullptr){
            levelOf[node] = level;
            parentOf[node] = parent;
            dfs(level + 1, node, node->left, parentOf, levelOf);
            dfs(level + 1, node, node->right, parentOf, levelOf);
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> parentOf;
        unordered_map<TreeNode*, int> levelOf;
        dfs(0, nullptr, root, parentOf, levelOf);
        
        while(p != q){
            if(levelOf[p] > levelOf[q]){
                p = parentOf[p];
            }else{
                q = parentOf[q];
            }
        }
        
        return p;
    }
};