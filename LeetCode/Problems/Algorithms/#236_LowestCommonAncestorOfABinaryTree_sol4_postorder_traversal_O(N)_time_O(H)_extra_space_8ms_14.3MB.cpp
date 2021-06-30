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
    int postorder(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& lca){
        if(root == NULL){
            return NULL;
        }
        int leftCount = postorder(root->left, p, q, lca);
        int rightCount = postorder(root->right, p, q, lca);
        int midCount = (root == p || root == q);
        if(lca == NULL){
            if(leftCount + rightCount + midCount == 2){
                lca = root;
            }
        }
        return leftCount + rightCount + midCount;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca = NULL;
        postorder(root, p, q, lca);
        return lca;
    }
};