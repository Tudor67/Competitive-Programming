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
    bool containsOne(TreeNode* root){
        if(root == NULL){
            return false;
        }
        bool leftContainsOne = containsOne(root->left);
        bool rightContainsOne = containsOne(root->right);
        if(!leftContainsOne){
            root->left = NULL;
        }
        if(!rightContainsOne){
            root->right = NULL;
        }
        return (root->val == 1 || leftContainsOne || rightContainsOne);
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(!containsOne(root)){
            return NULL;
        }
        return root;
    }
};