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
    int oddFreq(vector<int>& digitCount){
        int oddFreq = 0;
        for(int freq: digitCount){
            oddFreq += (freq % 2);
        }
        return oddFreq;
    }
    
    void dfs(TreeNode* node, vector<int>& digitCount, int& answer){
        if(node != NULL){
            digitCount[node->val] += 1;
            if(node->left == NULL && node->right == NULL && oddFreq(digitCount) <= 1){
                answer += 1;
            }
            dfs(node->left, digitCount, answer);
            dfs(node->right, digitCount, answer);
            digitCount[node->val] -= 1;
        }
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> digitCount(10, 0);
        int answer = 0;
        dfs(root, digitCount, answer);
        return answer;
    }
};