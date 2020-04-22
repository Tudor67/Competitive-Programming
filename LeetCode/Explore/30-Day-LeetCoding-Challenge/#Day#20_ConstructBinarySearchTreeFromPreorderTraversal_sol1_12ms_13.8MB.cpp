/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Case 1: preorder.size() == 0
        if(preorder.size() == 0){
            return NULL;
        }
        
        // Case 2: preorder.size() == 1
        if(preorder.size() == 1){
            return new TreeNode(preorder[0]);
        }
        
        // Case 3: preorder.size() >= 2
        int n = preorder.size();
        int first_max_pos = 0;
        for(int i = 1; i < n; ++i){
            if(preorder[i] > preorder[0]){
                first_max_pos = i;
                break;
            }
        }
        if(first_max_pos == 0){
            first_max_pos = n;
        }
        
        vector<int> L(preorder.begin() + 1, preorder.begin() + first_max_pos);
        vector<int> R(preorder.begin() + first_max_pos, preorder.begin() + n);
        
        TreeNode* root = new TreeNode(preorder[0]);
        root->left  = bstFromPreorder(L);
        root->right = bstFromPreorder(R);
        return root;
    }
};