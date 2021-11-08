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
    int sumNumbers(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int sum = 0;
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int num = q.front().second;
            q.pop();
            
            if(node->left == NULL && node->right == NULL){
                sum += num;
            }else{
                if(node->left != NULL){
                    q.push({node->left, 10 * num + node->left->val});
                }
                if(node->right != NULL){
                    q.push({node->right, 10 * num + node->right->val});
                }
            }
        }
        
        return sum;
    }
};