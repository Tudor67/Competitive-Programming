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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minVal = min(p->val, q->val);
        int maxVal = max(p->val, q->val);
        
        TreeNode* lca = root;
        while(lca->val < minVal || maxVal < lca->val){
            if(lca->val < minVal){
                lca = lca->right;
            }else{
                lca = lca->left;
            }
        }
        
        return lca;
    }
};