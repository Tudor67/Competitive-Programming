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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr){
                continue;
            }

            if(low <= node->val && node->val <= high){
                sum += node->val;
                q.push(node->left);
                q.push(node->right);
            }else if(node->val < low){
                q.push(node->right);
            }else if(high < node->val){
                q.push(node->left);
            }
        }

        return sum;
    }
};