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
    void postorder(TreeNode* node, vector<int>& postorderValues){
        if(node != nullptr){
            postorder(node->left, postorderValues);
            postorder(node->right, postorderValues);
            postorderValues.push_back(node->val);
        }
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderValues;
        postorder(root, postorderValues);
        return postorderValues;
    }
};