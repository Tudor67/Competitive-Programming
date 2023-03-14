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
    int sumNumbers(TreeNode* root) {
        int sum = 0;

        queue<pair<TreeNode*, int>> q;
        if(root != nullptr){
            q.push({root, 0});
        }

        while(!q.empty()){
            TreeNode* node = q.front().first;
            int num = q.front().second;
            q.pop();

            num = num * 10 + node->val;

            if(node->left == nullptr && node->right == nullptr){
                sum += num;
            }

            if(node->left != nullptr){
                q.push({node->left, num});
            }
            if(node->right != nullptr){
                q.push({node->right, num});
            }
        }

        return sum;
    }
};