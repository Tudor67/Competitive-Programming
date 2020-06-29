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
    void dfs(TreeNode* root, int path_num, int& sum){
        if(root != NULL){
            path_num = 10 * path_num + root->val;
            if(root->left == NULL && root->right == NULL){
                sum += path_num;
            }
            dfs(root->left, path_num, sum);
            dfs(root->right, path_num, sum);
        }
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
};