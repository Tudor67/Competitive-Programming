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
    void inorderTraversal(TreeNode* node, vector<int>& inorderValues){
        if(node != nullptr){
            inorderTraversal(node->left, inorderValues);
            inorderValues.push_back(node->val);
            inorderTraversal(node->right, inorderValues);
        }
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderValues;
        inorderTraversal(root, inorderValues);
        return inorderValues;
    }
};