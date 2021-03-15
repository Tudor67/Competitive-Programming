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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        TreeNode* virtualRoot = new TreeNode(0, root, NULL);
        queue<pair<TreeNode*, int>> q;
        q.emplace(virtualRoot, 0);
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int currentDepth = q.front().second;
            q.pop();
            
            if(currentDepth + 1 == d){
                node->left = new TreeNode(v, node->left, NULL);
                node->right = new TreeNode(v, NULL, node->right);
            }else{
                if(node->left != NULL){
                    q.emplace(node->left, currentDepth + 1);
                }
                if(node->right != NULL){
                    q.emplace(node->right, currentDepth + 1);
                }
            }
        }
        return virtualRoot->left;
    }
};