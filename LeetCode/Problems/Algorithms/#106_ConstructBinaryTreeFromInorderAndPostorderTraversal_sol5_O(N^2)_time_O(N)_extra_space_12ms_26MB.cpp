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
    TreeNode* buildTree(vector<int>& inorder, int inL, int inR, vector<int>& postorder, int postL, int postR) {
        if(inL > inR){
            return NULL;
        }
        
        int rootVal = postorder[postR];
        TreeNode* root = new TreeNode(rootVal);
        
        if(inorder[inL] != rootVal){
            int rootIdx = find(inorder.begin() + inL, inorder.begin() + inR + 1, rootVal) - inorder.begin();
            int size = rootIdx - inL;
            root->left = buildTree(inorder, inL, inL + size - 1, postorder, postL, postL + size - 1);
        }
        
        if(inorder[inR] != rootVal){
            int rootIdx = find(inorder.begin() + inL, inorder.begin() + inR + 1, rootVal) - inorder.begin();
            int size = inR - rootIdx;
            root->right = buildTree(inorder, inR - size + 1, inR, postorder, postR - size, postR - 1);
        }
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int N = inorder.size();
        return buildTree(inorder, 0, N - 1, postorder, 0, N - 1);
    }
};