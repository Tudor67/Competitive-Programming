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
    void dfs(int level, TreeNode* node, vector<int>& prevVal, bool& isValid){
        if(node != nullptr && isValid){
            if(node->val % 2 == level % 2){
                isValid = false;
            }

            if((int)prevVal.size() <= level){
                prevVal.resize(level + 1);
            }else if((level % 2 == 0 && prevVal[level] >= node->val) ||
                     (level % 2 == 1 && prevVal[level] <= node->val)){
                isValid = false;
            }
            prevVal[level] = node->val;

            dfs(level + 1, node->left, prevVal, isValid);
            dfs(level + 1, node->right, prevVal, isValid);
        }
    }

public:
    bool isEvenOddTree(TreeNode* root) {
        bool isValid = true;
        vector<int> prevVal;
        dfs(0, root, prevVal, isValid);
        return isValid;
    }
};