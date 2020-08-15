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
    void dfs(TreeNode* node, int cur_sum, const int& TARGET_SUM, unordered_map<int, int>& cnt, int& answer){
        if(node != NULL){
            cur_sum += node->val;
            
            if(cnt.count(cur_sum - TARGET_SUM)){
                answer += cnt[cur_sum - TARGET_SUM];
            }
            cnt[cur_sum] += 1;
            
            dfs(node->left, cur_sum, TARGET_SUM, cnt, answer);
            dfs(node->right, cur_sum, TARGET_SUM, cnt, answer);
            
            cnt[cur_sum] -= 1;
            if(cnt[cur_sum] == 0){
                cnt.erase(cur_sum);
            }
        }
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        
        int answer = 0;
        dfs(root, 0, sum, cnt, answer);
        
        return answer;
    }
};