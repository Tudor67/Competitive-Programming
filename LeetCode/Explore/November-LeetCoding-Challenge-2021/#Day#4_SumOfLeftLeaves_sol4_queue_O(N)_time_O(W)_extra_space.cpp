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
    int sumOfLeftLeaves(TreeNode* root) {
        int leftLeavesSum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, false});
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            bool isLeftChild = q.front().second;
            q.pop();
            
            if(node->left == NULL && node->right == NULL && isLeftChild){
                leftLeavesSum += node->val;
            }
            
            if(node->left != NULL){
                q.push({node->left, true});
            }
            if(node->right != NULL){
                q.push({node->right, false});
            }
        }
        
        return leftLeavesSum;
    }
};