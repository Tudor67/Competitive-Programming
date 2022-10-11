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
    void reverseOddLevels(int level, TreeNode* root1, TreeNode* root2){
        if(root1 != nullptr){
            if(level % 2 == 1){
                swap(root1->val, root2->val);
            }
            reverseOddLevels(level + 1, root1->left, root2->right);
            reverseOddLevels(level + 1, root1->right, root2->left);
        }
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        reverseOddLevels(1, root->left, root->right);
        return root;
    }
};