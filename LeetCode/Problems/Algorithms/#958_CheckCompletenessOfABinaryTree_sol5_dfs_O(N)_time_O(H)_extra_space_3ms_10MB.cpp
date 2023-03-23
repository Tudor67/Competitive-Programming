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
    int computeMaxLevel(TreeNode* node){
        if(node == nullptr){
            return -1;
        }
        return 1 + max(computeMaxLevel(node->left), computeMaxLevel(node->right));
    }

    void checkCompleteness(TreeNode* node, int level, int& prevNullLevel, int maxLevel, bool& isComplete){
        if(node == nullptr){
            if(prevNullLevel >= level && level >= maxLevel){
                prevNullLevel = level;
            }else{
                isComplete = false;
            }
        }else{
            checkCompleteness(node->left, level + 1, prevNullLevel, maxLevel, isComplete);
            checkCompleteness(node->right, level + 1, prevNullLevel, maxLevel, isComplete);
        }
    }

public:
    bool isCompleteTree(TreeNode* root) {
        int maxLevel = computeMaxLevel(root);

        int prevNullLevel = maxLevel + 1;
        bool isComplete = true;
        checkCompleteness(root, 0, prevNullLevel, maxLevel, isComplete);

        return isComplete;
    }
};