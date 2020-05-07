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
    bool is_mirror(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL){
            return true;
        }
        if(t1 == NULL || t2 == NULL){
            return false;
        }
        return (t1->val == t2->val &&
                is_mirror(t1->left, t2->right) &&
                is_mirror(t1->right, t2->left));
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        return is_mirror(root, root);
    }
};