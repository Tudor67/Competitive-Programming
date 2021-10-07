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
    void dfs(TreeNode* root, vector<int>& preorderNodes){
        if(root != NULL){
            preorderNodes.push_back(root->val);
            dfs(root->left, preorderNodes);
            dfs(root->right, preorderNodes);
        }
    }
    
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderNodes;
        dfs(root, preorderNodes);
        return preorderNodes;
    }
};