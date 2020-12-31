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
    void dfs(TreeNode* node, int freqParityMask, int& answer){
        if(node != NULL){
            answer += (node->left == NULL && node->right == NULL && __builtin_popcount(freqParityMask ^ (1 << node->val)) <= 1);
            dfs(node->left, freqParityMask ^ (1 << node->val), answer);
            dfs(node->right, freqParityMask ^ (1 << node->val), answer);
        }
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int freqParityMask = 0;
        int answer = 0;
        dfs(root, freqParityMask, answer);
        return answer;
    }
};