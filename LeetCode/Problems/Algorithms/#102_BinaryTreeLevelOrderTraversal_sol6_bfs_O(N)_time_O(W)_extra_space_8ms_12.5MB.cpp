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
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
        }
        
        while(!q.empty()){
            res.push_back({});
            res.back().reserve(q.size());
            for(int i = (int)q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();
                
                res.back().push_back(node->val);
                
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
        }
        
        return res;
    }
};