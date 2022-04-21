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
    void inorder(TreeNode* node, int& k, int& res){
        if(node == NULL || k == 0){
            return;
        }
        inorder(node->left, k, res);
        if(k == 1){
            res = node->val;
        }
        k -= 1;
        inorder(node->right, k, res);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        inorder(root, k, res);
        return res;
    }
};