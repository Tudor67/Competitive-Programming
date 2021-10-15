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
    TreeNode* bstFromPreorder(int& idx, int minVal, int maxVal, vector<int>& preorder){
        if(idx + 1 == (int)preorder.size()){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[++idx]);
        if(idx + 1 < (int)preorder.size() && minVal <= preorder[idx + 1] && preorder[idx + 1] <= root->val){
            root->left = bstFromPreorder(idx, minVal, root->val, preorder);
        }
        if(idx + 1 < (int)preorder.size() && root->val <= preorder[idx + 1] && preorder[idx + 1] <= maxVal){
            root->right = bstFromPreorder(idx, root->val, maxVal, preorder);
        }
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = -1;
        return bstFromPreorder(idx, INT_MIN, INT_MAX, preorder);
    }
};