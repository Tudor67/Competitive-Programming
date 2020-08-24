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
    void dfs(TreeNode* node, vector<int>& answer){
        if(node != NULL){
            dfs(node->left, answer);
            answer.push_back(node->val);
            dfs(node->right, answer);
        }
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        dfs(root, answer);
        return answer;
    }
};