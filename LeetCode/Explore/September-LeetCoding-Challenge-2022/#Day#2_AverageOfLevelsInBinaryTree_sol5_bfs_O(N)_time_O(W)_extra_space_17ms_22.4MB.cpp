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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            double sum = 0;
            int levelSize = q.size();
            
            for(int i = 1; i <= levelSize; ++i){
                TreeNode* node = q.front();
                q.pop();
                
                sum += node->val;
                
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            
            averages.push_back(sum / levelSize);
        }
        
        return averages;
    }
};