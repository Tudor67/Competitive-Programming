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
private:
    TreeNode* bstFromPreorder(const vector<int>& preorder, const int& first_pos, const int& last_pos) {
        // Case 1: range size == 0
        if(first_pos > last_pos){
            return NULL;
        }
        
        // Case 2: range size == 1
        if(first_pos == last_pos){
            return new TreeNode(preorder[first_pos]);
        }
        
        // Case 3: range size >= 2
        int first_max_pos = first_pos;
        for(int i = first_pos + 1; i <= last_pos; ++i){
            if(preorder[first_pos] < preorder[i]){
                first_max_pos = i;
                break;
            }
        }
        if(first_max_pos == first_pos){
            first_max_pos = last_pos + 1;
        }
        
        TreeNode* root = new TreeNode(preorder[first_pos]);
        root->left  = bstFromPreorder(preorder, first_pos + 1, first_max_pos - 1);
        root->right = bstFromPreorder(preorder, first_max_pos, last_pos);
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorder(preorder, 0, (int)preorder.size() - 1);
    }
};