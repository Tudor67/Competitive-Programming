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
    void dfs(TreeNode* node, int prefMax, int& goodNodesCount){
        if(node != nullptr){
            if(prefMax <= node->val){
                goodNodesCount += 1;
            }
            dfs(node->left, max(prefMax, node->val), goodNodesCount);
            dfs(node->right, max(prefMax, node->val), goodNodesCount);
        }
    }
    
public:
    int goodNodes(TreeNode* root) {
        int goodNodesCount = 0;
        dfs(root, root->val, goodNodesCount);
        return goodNodesCount;
    }
};