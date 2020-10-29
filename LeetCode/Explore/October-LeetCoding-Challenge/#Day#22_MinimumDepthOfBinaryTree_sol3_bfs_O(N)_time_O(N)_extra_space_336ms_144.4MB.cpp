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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int answer = -1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if(node->left == NULL && node->right == NULL){
                answer = dist;
                break;
            }
            if(node->left != NULL){
                q.push({node->left, dist + 1});
            }
            if(node->right != NULL){
                q.push({node->right, dist + 1});
            }
        }
        
        return answer;
    }
};