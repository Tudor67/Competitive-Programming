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
    int maxDepth(TreeNode* root) {
        int res = 0;

        queue<pair<TreeNode*, int>> q;
        if(root != nullptr){
            q.push({root, 1});
        }

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();

            res = max(res, depth);

            if(node->left != nullptr){
                q.push({node->left, depth + 1});
            }
            if(node->right != nullptr){
                q.push({node->right, depth + 1});
            }
        }

        return res;
    }
};