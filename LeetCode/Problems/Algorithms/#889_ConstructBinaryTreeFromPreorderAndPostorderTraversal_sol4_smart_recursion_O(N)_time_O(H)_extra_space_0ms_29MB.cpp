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
    TreeNode* construct(vector<int>& preorder, int& preIndex, vector<int>& postorder, int& postIndex){
        if(preIndex >= (int)preorder.size()){
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preIndex]);
        preIndex += 1;

        if(root->val != postorder[postIndex]){
            root->left = construct(preorder, preIndex, postorder, postIndex);
        }

        if(root->val != postorder[postIndex]){
            root->right = construct(preorder, preIndex, postorder, postIndex);
        }

        postIndex += 1;

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0;
        int postIndex = 0;
        return construct(preorder, preIndex, postorder, postIndex);
    }
};