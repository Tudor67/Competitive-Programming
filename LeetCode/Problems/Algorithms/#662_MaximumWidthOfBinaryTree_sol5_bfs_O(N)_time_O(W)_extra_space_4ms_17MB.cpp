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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            long long levelFirstIndex = q.front().second;
            long long levelLastIndex = q.back().second;
            
            maxWidth = max(maxWidth, levelLastIndex - levelFirstIndex + 1);

            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front().first;
                long long index = q.front().second;
                q.pop();

                if(node->left != nullptr){
                    q.push({node->left, 2 * (index - levelFirstIndex) + 1});
                }
                if(node->right != nullptr){
                    q.push({node->right, 2 * (index - levelFirstIndex) + 2});
                }
            }
        }

        return maxWidth;
    }
};