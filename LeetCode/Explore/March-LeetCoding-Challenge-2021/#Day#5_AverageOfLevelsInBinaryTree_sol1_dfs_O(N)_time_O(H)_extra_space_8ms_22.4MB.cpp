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
private:
    void dfs(TreeNode* root, int level, vector<long long>& sum, vector<int>& count){
        if(root != NULL){
            if(level >= (int)sum.size()){
                sum.resize(level + 1);
                count.resize(level + 1);
            }
            sum[level] += root->val;
            count[level] += 1;
            dfs(root->left, level + 1, sum, count);
            dfs(root->right, level + 1, sum, count);
        }
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<long long> sum;
        vector<int> count;
        dfs(root, 0, sum, count);
        
        vector<double> averages;
        for(int i = 0; i < (int)sum.size(); ++i){
            averages.push_back((double)sum[i] / (double)count[i]);
        }
        
        return averages;
    }
};