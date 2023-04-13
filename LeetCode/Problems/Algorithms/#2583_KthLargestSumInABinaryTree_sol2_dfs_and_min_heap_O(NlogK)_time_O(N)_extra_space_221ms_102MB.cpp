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
    void dfs(TreeNode* root, int level, vector<long long>& sums){
        if(root == nullptr){
            return;
        }
        if(level >= (int)sums.size()){
            sums.resize(level + 1);
        }
        sums[level] += root->val;
        dfs(root->left, level + 1, sums);
        dfs(root->right, level + 1, sums);
    }
    
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        dfs(root, 0, sums);

        if(k > (int)sums.size()){
            return -1;
        }

        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        for(long long sum: sums){
            minHeap.push(sum);
            if((int)minHeap.size() == k + 1){
                minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
};