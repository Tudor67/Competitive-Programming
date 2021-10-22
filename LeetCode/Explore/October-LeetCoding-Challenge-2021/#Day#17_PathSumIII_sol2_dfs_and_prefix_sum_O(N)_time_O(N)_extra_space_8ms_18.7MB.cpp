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
    void dfs(TreeNode* root, long long sum, int targetSum, unordered_map<long long, int>& count, int& paths){
        if(root != NULL){
            sum += root->val;
            if(count.count(sum - targetSum)){
                paths += count[sum - targetSum];
            }
            count[sum] += 1;
            dfs(root->left, sum, targetSum, count, paths);
            dfs(root->right, sum, targetSum, count, paths);
            count[sum] -= 1;
            sum -= root->val;
        }
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> count;
        count[0] = 1;
        int paths = 0;
        dfs(root, 0, targetSum, count, paths);
        return paths;
    }
};