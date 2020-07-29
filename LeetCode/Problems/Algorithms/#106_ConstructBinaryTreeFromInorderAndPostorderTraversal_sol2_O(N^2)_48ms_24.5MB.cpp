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
    TreeNode* buildTree(const vector<int>& INORDER, int in_start, int in_end,
                        const vector<int>& POSTORDER, int post_start, int post_end){
        if(in_start > in_end){
            return NULL;
        }
        
        vector<int>::const_iterator it = find(INORDER.begin() + in_start, INORDER.begin() + in_end + 1, POSTORDER[post_end]);
        int idx = it - (INORDER.begin() + in_start);

        TreeNode* root = new TreeNode(POSTORDER[post_end]);
        root->left = buildTree(INORDER, in_start, in_start + idx - 1, POSTORDER, post_start, post_start + idx - 1);
        root->right = buildTree(INORDER, in_start + idx + 1, in_end, POSTORDER, post_start + idx, post_end - 1);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int N = inorder.size();
        return buildTree(inorder, 0, N - 1, postorder, 0, N - 1);
    }
};