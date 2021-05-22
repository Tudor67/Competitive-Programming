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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        if(root != NULL){
            q.push({root, 0});
        }
        
        vector<vector<int>> nodes;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(level >= (int)nodes.size()){
                nodes.resize(level + 1);
            }
            nodes[level].push_back(node->val);
            
            if(node->left != NULL){
                q.push({node->left, level + 1});
            }
            if(node->right != NULL){
                q.push({node->right, level + 1});
            }
        }
        
        return nodes;
    }
};