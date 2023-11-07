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
    void dfs(TreeNode* node, unordered_map<int, int>& count){
        if(node != nullptr){
            count[node->val] += 1;
            dfs(node->left, count);
            dfs(node->right, count);
        }
    }

public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> count;
        dfs(root, count);

        int maxCount = 0;
        vector<int> modes;
        for(const pair<int, int>& P: count){
            int val = P.first;
            int valCount = P.second;
            if(valCount > maxCount){
                maxCount = valCount;
                modes.clear();
                modes.push_back(val);
            }else if(valCount == maxCount){
                modes.push_back(val);
            }
        }

        return modes;
    }
};