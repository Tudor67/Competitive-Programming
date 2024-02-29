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
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = -1;
        int leftmostValue = 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(maxLevel < level){
                maxLevel = level;
                leftmostValue = node->val;
            }

            if(node->left != nullptr){
                q.push({node->left, level + 1});
            }
            if(node->right != nullptr){
                q.push({node->right, level + 1});
            }
        }

        return leftmostValue;
    }
};