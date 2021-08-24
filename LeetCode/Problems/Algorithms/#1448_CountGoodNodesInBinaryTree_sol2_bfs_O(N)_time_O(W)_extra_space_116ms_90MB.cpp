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
    int goodNodes(TreeNode* root) {
        int goodNodes = 0;
        
        queue<pair<TreeNode*, int>> q;
        if(root != NULL){
            q.push({root, root->val});
            goodNodes += 1;
        }
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int maxVal = q.front().second;
            q.pop();
            
            for(TreeNode* nextNode: {node->left, node->right}){
                if(nextNode != NULL){
                    if(maxVal <= nextNode->val){
                        goodNodes += 1;
                    }
                    q.push({nextNode, max(nextNode->val, maxVal)});
                }
            }
        }
        
        return goodNodes;
    }
};