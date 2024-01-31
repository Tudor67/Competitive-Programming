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
    void dfs(TreeNode* node, vector<int>& freq, int& res){
        if(node == nullptr){
            return;
        }
        
        freq[node->val] += 1;

        if(node->left == nullptr && node->right == nullptr){
            int oddFreqs = 0;
            for(int digit = 0; digit < (int)freq.size(); ++digit){
                oddFreqs += (freq[digit] % 2);
            }
            if(oddFreqs <= 1){
                res += 1;
            }
        }

        dfs(node->left, freq, res);
        dfs(node->right, freq, res);

        freq[node->val] -= 1;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        vector<int> freq(10);
        dfs(root, freq, res);
        return res;
    }
};