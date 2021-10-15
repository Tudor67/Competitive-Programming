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
    TreeNode* bstFromPreorder(int l, int r, vector<int>& preorder){
        if(l > r){
            return NULL;
        }
        int rootVal = preorder[l];
        int idx = l + 1;
        while(idx <= r && preorder[idx] < rootVal){
            idx += 1;
        }
        TreeNode* root = new TreeNode(rootVal);
        root->left = bstFromPreorder(l + 1, idx - 1, preorder);
        root->right = bstFromPreorder(idx, r, preorder);
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        const int N = preorder.size();
        return bstFromPreorder(0, N - 1, preorder);
    }
};