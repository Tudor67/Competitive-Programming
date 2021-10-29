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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
        }
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            swap(node->left, node->right);
            for(TreeNode* child: {node->left, node->right}){
                if(child != NULL){
                    q.push(child);
                }
            }
        }
        return root;
    }
};