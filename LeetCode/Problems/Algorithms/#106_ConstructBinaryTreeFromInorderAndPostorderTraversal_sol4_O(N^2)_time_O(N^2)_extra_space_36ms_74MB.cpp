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
        
        int rootVal = postorder.back();
        TreeNode* root = new TreeNode(rootVal);
        
        if(inorder.front() != rootVal){
            int size = find(inorder.begin(), inorder.end(), rootVal) - inorder.begin();
            vector<int> inorderL(inorder.begin(), inorder.begin() + size);
            vector<int> postorderL(postorder.begin(), postorder.begin() + size);
            root->left = buildTree(inorderL, postorderL);
        }
        
        if(inorder.back() != rootVal){
            int size = inorder.end() - find(inorder.begin(), inorder.end(), rootVal) - 1;
            vector<int> inorderR(inorder.end() - size, inorder.end());
            vector<int> postorderR(postorder.end() - size - 1, postorder.end() - 1);
            root->right = buildTree(inorderR, postorderR);
        }
        
        return root;
    }
};