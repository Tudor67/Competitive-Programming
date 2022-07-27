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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty()){
            return NULL;
        }
        
        int rootVal = preorder[0];
        preorder.erase(preorder.begin());
        
        int inorderRootIdx = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
        vector<int> leftInorder(inorder.begin(), inorder.begin() + inorderRootIdx);
        vector<int> rightInorder(inorder.begin() + inorderRootIdx + 1, inorder.end());
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(preorder, leftInorder);
        root->right = buildTree(preorder, rightInorder);
        
        return root;
    }
};