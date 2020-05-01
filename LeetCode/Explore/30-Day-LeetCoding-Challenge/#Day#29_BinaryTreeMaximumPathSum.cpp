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
    int solve(TreeNode* node, int& answer){
        if(node == NULL){
            return 0;
        }
        
        int best_left = solve(node->left, answer);
        int best_right = solve(node->right, answer);
        
        // local_answer: root->val alone or combined with best 
        //               1.) left subtree or 2.) right subtree or 3.) left + right subtrees
        int local_answer = node->val + max({0, best_left, best_right, best_left + best_right});
        answer = max(local_answer, answer);
        
        // return the root->val or combine it with the best 1.) left subtree or 2.) right subtree
        return node->val + max({0, best_left, best_right});
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int answer = root->val;
        solve(root, answer);
        return answer;
    }
};