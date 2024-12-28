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
    void dfs(int level, TreeNode* node, vector<int>& levelMax){
        if(node == nullptr){
            return;
        }
        if(level < (int)levelMax.size()){
            levelMax[level] = max(levelMax[level], node->val);
        }else{
            levelMax.push_back(node->val);
        }
        dfs(level + 1, node->left, levelMax);
        dfs(level + 1, node->right, levelMax);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> levelMax;
        dfs(0, root, levelMax);
        return levelMax;
    }
};