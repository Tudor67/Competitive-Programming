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
    void dfs(TreeNode* parent, TreeNode* node, int level,
             unordered_map<TreeNode*, int>& levelOf, unordered_map<TreeNode*, TreeNode*>& parentOf){
        if(node != NULL){
            levelOf[node] = level;
            parentOf[node] = parent;
            dfs(node, node->left, level + 1, levelOf, parentOf);
            dfs(node, node->right, level + 1, levelOf, parentOf);
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, int> levelOf;
        unordered_map<TreeNode*, TreeNode*> parentOf;
        dfs(NULL, root, 0, levelOf, parentOf);
        
        while(p != q){
            if(levelOf[p] < levelOf[q]){
                q = parentOf[q];
            }else if(levelOf[p] > levelOf[q]){
                p = parentOf[p];
            }else{
                p = parentOf[p];
                q = parentOf[q];
            }
        }
        
        return p;
    }
};