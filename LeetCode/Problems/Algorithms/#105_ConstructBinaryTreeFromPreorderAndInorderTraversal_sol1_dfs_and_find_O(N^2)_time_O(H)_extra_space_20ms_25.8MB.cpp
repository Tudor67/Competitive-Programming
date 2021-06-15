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
    TreeNode* buildTree(vector<int>& preorder, int& preorderIdx,
                        vector<int>& inorder, int inorderLeftIdx, int inorderRightIdx){
        if(inorderLeftIdx > inorderRightIdx){
            return NULL;
        }
        int rootVal = preorder[preorderIdx];
        int rootIdx = find(inorder.begin() + inorderLeftIdx, inorder.begin() + inorderRightIdx + 1, rootVal) - inorder.begin();
        TreeNode* root = new TreeNode(rootVal);
        preorderIdx += 1;
        root->left = buildTree(preorder, preorderIdx, inorder, inorderLeftIdx, rootIdx - 1);
        root->right = buildTree(preorder, preorderIdx, inorder, rootIdx + 1, inorderRightIdx);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIdx = 0;
        int inorderLeftIdx = 0;
        int inorderRightIdx = (int)inorder.size() - 1;
        return buildTree(preorder, preorderIdx, inorder, inorderLeftIdx, inorderRightIdx);
    }
};