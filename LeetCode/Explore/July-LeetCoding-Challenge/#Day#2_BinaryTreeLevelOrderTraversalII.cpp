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
    void dfs(TreeNode* node, int level, vector<vector<int>>& answer){
        if(node != NULL){
            if(level >= answer.size()){
                answer.resize(level + 1);
            }
            answer[level].push_back(node->val);
            dfs(node->left, level + 1, answer);
            dfs(node->right, level + 1, answer);
        }
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;
        dfs(root, 0, answer);
        reverse(answer.begin(), answer.end());
        return answer;
    }
};