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
        int maxWidth = 0;
        
        queue<pair<TreeNode*, long long>> q;
        q.emplace(root, 0);
        while(!q.empty()){
            long long leftmostPos = q.front().second;
            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front().first;
                long long pos = q.front().second;
                q.pop();
                
                int width = pos - leftmostPos + 1;
                maxWidth = max(maxWidth, width);
                
                if(node->left != NULL){
                    q.emplace(node->left, 2 * (pos - leftmostPos) + 1);
                }
                if(node->right != NULL){
                    q.emplace(node->right, 2 * (pos - leftmostPos) + 2);
                }
            }
        }
        
        return maxWidth;
    }
};