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
    pair<int, bool> dfs(TreeNode* node, int depth, int start, int& startDepth, int& maxTime){
        if(node == nullptr){
            return {depth - 1, false};
        }

        pair<int, bool> l = dfs(node->left, depth + 1, start, startDepth, maxTime);
        pair<int, bool> r = dfs(node->right, depth + 1, start, startDepth, maxTime);

        if(node->val == start){
            startDepth = depth;
            maxTime = max(maxTime, max(l.first, r.first) - startDepth);
        }else if(l.second){
            maxTime = max(maxTime, startDepth - depth + r.first - depth);
        }else if(r.second){
            maxTime = max(maxTime, startDepth - depth + l.first - depth);
        }

        return {max(l.first, r.first),
                (node->val == start) || l.second || r.second};
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        int startDepth = 0;
        int maxTime = 0;
        dfs(root, 0, start, startDepth, maxTime);
        return maxTime;
    }
};