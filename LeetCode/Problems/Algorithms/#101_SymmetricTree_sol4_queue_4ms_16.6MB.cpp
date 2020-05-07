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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        
        bool is_symmetric = true;
        while(!q.empty()){
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();
            
            if(t1 == NULL && t2 == NULL){
                continue;
            }
            if(t1 == NULL || t2 == NULL){
                is_symmetric = false;
                break;
            }
            if(t1->val != t2->val){
                is_symmetric = false;
                break;
            }
            
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        
        return is_symmetric;
    }
};