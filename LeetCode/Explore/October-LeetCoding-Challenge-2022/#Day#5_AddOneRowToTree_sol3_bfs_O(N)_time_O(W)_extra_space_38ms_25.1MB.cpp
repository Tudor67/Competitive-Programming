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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Special case
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        // BFS
        queue<TreeNode*> q;
        q.push(root);
        for(int step = 1; step <= depth - 2; ++step){
            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
        }
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            TreeNode* oldLeftChild = node->left;
            TreeNode* oldRightChild = node->right;
            
            node->left = new TreeNode(val);
            node->right = new TreeNode(val);
            node->left->left = oldLeftChild;
            node->right->right = oldRightChild;
        }
        
        return root;
    }
};