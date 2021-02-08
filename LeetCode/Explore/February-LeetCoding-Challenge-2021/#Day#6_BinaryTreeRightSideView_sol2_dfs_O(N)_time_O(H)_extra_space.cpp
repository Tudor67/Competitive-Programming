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
    void dfs(TreeNode* root, int level, vector<int>& answer){
        if(root != NULL){
            if(level >= answer.size()){
                answer.resize(level + 1);
            }
            answer[level] = root->val;
            dfs(root->left, level + 1, answer);
            dfs(root->right, level + 1, answer);
        }
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answer;
        dfs(root, 0, answer);
        return answer;
    }
};