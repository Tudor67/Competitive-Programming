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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.emplace(original, cloned);
        
        while(!q.empty()){
            TreeNode* originalNode = q.front().first;
            TreeNode* clonedNode = q.front().second;
            q.pop();
            
            if(originalNode == target){
                return clonedNode;
            }
            
            if(originalNode->left != NULL){
                q.emplace(originalNode->left, clonedNode->left);
            }
            if(originalNode->right != NULL){
                q.emplace(originalNode->right, clonedNode->right);
            }
        }
        
        return NULL;
    }
};