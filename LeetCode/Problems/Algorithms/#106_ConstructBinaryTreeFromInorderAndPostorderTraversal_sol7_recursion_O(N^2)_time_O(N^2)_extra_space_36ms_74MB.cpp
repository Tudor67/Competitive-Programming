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
            return nullptr;
        }

        int rootVal = postorder.back();
        int rootInorderIndex = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();

        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootInorderIndex);
        vector<int> rightInorder(inorder.begin() + rootInorderIndex + 1, inorder.end());
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + rootInorderIndex);
        vector<int> rightPostorder(postorder.begin() + rootInorderIndex, postorder.end() - 1);

        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};