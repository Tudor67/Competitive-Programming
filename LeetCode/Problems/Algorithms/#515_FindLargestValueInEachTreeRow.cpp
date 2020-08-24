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
    void dfs(TreeNode* node, int level, vector<int>& max_values){
        if(node != NULL){
            if(level >= max_values.size()){
                max_values.resize(level + 1);
                max_values.back() = node->val;
            }
            else{
                max_values[level] = max(node->val, max_values[level]);
            }
            
            dfs(node->left, level + 1, max_values);
            dfs(node->right, level + 1, max_values);
        }
    }
    
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> max_values;
        dfs(root, 0, max_values);
        return max_values;
    }
};