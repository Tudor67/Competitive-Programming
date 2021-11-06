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
        if(preorder.empty()){
            return NULL;
        }
        
        vector<int> L;
        vector<int> R;
        for(int i = 1; i < preorder.size(); ++i){
            if(preorder[i] < preorder[0]){
                L.push_back(preorder[i]);
            }else{
                R.push_back(preorder[i]);
            }
        }
        
        TreeNode* node = new TreeNode(preorder[0]);
        node->left  = bstFromPreorder(L);
        node->right = bstFromPreorder(R);
        
        return node;
    }
};