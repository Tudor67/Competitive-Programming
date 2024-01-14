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
    pair<int, bool> dfs(TreeNode* node, int start, int& maxTime){
        if(node == nullptr){
            return {-1, false};
        }

        pair<int, bool> l = dfs(node->left, start, maxTime);
        pair<int, bool> r = dfs(node->right, start, maxTime);

        if(node->val == start){
            maxTime = max(maxTime, 1 + max(l.first, r.first));
            return {0, true};
        }else if(l.second){
            maxTime = max(maxTime, l.first + 2 + r.first);
            return {1 + l.first, true};
        }else if(r.second){
            maxTime = max(maxTime, l.first + 2 + r.first);
            return {1 + r.first, true};
        }

        return {1 + max(l.first, r.first), false};
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        int maxTime = 0;
        dfs(root, start, maxTime);
        return maxTime;
    }
};