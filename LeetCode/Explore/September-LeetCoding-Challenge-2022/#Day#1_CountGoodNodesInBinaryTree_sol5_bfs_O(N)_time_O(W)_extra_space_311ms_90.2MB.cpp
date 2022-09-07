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
        int goodNodesCount = 0;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, root->val);
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int prefMax = q.front().second;
            q.pop();
            
            if(prefMax <= node->val){
                goodNodesCount += 1;
            }
            
            if(node->left != nullptr){
                q.emplace(node->left, max(prefMax, node->val));
            }
            if(node->right != nullptr){
                q.emplace(node->right, max(prefMax, node->val));
            }
        }
        
        return goodNodesCount;
    }
};