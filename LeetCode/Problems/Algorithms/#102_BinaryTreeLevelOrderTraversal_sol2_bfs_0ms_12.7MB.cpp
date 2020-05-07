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
        vector<vector<int>> nodes;
        queue<pair<TreeNode*, int>> q;
        
        if(root != NULL){
            q.push({root, 0});
            while(!q.empty()){
                TreeNode* node = q.front().first;
                int dist = q.front().second;
                q.pop();
                
                if(dist >= nodes.size()){
                    nodes.resize(dist + 1);
                }
                nodes[dist].push_back(node->val);
                
                if(node->left != NULL){
                    q.push({node->left, dist + 1});
                }
                if(node->right != NULL){
                    q.push({node->right, dist + 1});
                }
            }
        }
        
        return nodes;
    }
};