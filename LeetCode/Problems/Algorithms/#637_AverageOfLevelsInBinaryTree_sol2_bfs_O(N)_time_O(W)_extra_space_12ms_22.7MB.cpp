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
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int prevLevel = 0;
        long long sum = 0;
        int count = 0;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(prevLevel == level){
                sum += node->val;
                count += 1;
            }else{
                averages.push_back((double)sum / (double)count);
                sum = node->val;
                count = 1;
                prevLevel = level;
            }
            
            if(node->left != NULL){
                q.push({node->left, level + 1});
            }
            if(node->right != NULL){
                q.push({node->right, level + 1});
            }
        }
        
        averages.push_back((double)sum / (double)count);
        
        return averages;
    }
};