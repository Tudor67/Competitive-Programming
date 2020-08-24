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
    void dfs(TreeNode* node, vector<int>& cnt, int& answer){
        if(node != NULL){
            cnt[node->val] += 1;
            if(node->left == NULL && node->right == NULL){
                int odd_cnt = 0;
                for(int i = 0; i < cnt.size(); ++i){
                    odd_cnt += (cnt[i] % 2);
                }
                if(odd_cnt <= 1){
                    answer += 1;
                }
            }else{
                dfs(node->left, cnt, answer);
                dfs(node->right, cnt, answer);
            }
            cnt[node->val] -= 1;
        }
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int answer = 0;
        vector<int> cnt(10, 0);
        dfs(root, cnt, answer);
        return answer;
    }
};