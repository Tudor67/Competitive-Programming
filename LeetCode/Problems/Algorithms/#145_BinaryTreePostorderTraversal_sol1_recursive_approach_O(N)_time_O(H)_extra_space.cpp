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
    void dfs(TreeNode* root, vector<int>& postorderNodes){
        if(root != NULL){
            dfs(root->left, postorderNodes);
            dfs(root->right, postorderNodes);
            postorderNodes.push_back(root->val);
        }
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderNodes;
        dfs(root, postorderNodes);
        return postorderNodes;
    }
};