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
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()){
            return NULL;
        }
        
        int idx = find(inorder.begin(), inorder.end(), postorder.back()) - inorder.begin();
        
        vector<int> left_inorder(inorder.begin(), inorder.begin() + idx);
        vector<int> left_postorder(postorder.begin(), postorder.begin() + idx);
        vector<int> right_inorder(inorder.begin() + idx + 1, inorder.end());
        vector<int> right_postorder(postorder.begin() + idx, postorder.end() - 1);
        
        TreeNode* root = new TreeNode(postorder.back());
        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);
        
        return root;
    }
};