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
    void dfs(TreeNode* node, int& idx, const int& k, int& answer){
        if(node != NULL){
            dfs(node->left, idx, k, answer);
            ++idx;
            if(idx == k){
                answer = node->val;
            }
            dfs(node->right, idx, k, answer);
        }
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int answer = -1;
        int idx = 0;
        dfs(root, idx, k, answer);
        return answer;
    }
};