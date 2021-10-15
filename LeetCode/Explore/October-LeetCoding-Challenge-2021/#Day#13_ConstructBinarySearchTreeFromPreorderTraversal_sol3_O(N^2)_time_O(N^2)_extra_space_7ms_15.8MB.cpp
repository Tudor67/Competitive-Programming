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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()){
            return NULL;
        }
        
        int rootVal = preorder[0];
        int idx = 1;
        while(idx < (int)preorder.size() && preorder[idx] < rootVal){
            idx += 1;
        }
        
        vector<int> l(vector<int>(preorder.begin() + 1, preorder.begin() + idx));
        vector<int> r(vector<int>(preorder.begin() + idx, preorder.end()));
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = bstFromPreorder(l);
        root->right = bstFromPreorder(r);
        
        return root;
    }
};