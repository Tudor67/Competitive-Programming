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
    void countNodesAtEachLevel(TreeNode* node, int level, vector<int>& countAt){
        if(node != nullptr){
            if(level >= (int)countAt.size()){
                countAt.resize(level + 1);
            }
            countAt[level] += 1;
            countNodesAtEachLevel(node->left, level + 1, countAt);
            countNodesAtEachLevel(node->right, level + 1, countAt);
        }
    }

    void checkLastLevel(TreeNode* node, int level, int lastLevel, TreeNode*& prevNodeOfLastLevel, bool& isValidLastLevel){
        if(level == lastLevel && prevNodeOfLastLevel == nullptr && node != nullptr){
            isValidLastLevel = false;
        }
        if(level == lastLevel){
            prevNodeOfLastLevel = node;
        }
        if(node != nullptr){
            checkLastLevel(node->left, level + 1, lastLevel, prevNodeOfLastLevel, isValidLastLevel);
            checkLastLevel(node->right, level + 1, lastLevel, prevNodeOfLastLevel, isValidLastLevel);
        }
    }

public:
    bool isCompleteTree(TreeNode* root) {
        // Step 1: check if every level (except the last/max one) is completely filled
        vector<int> countAt;
        countNodesAtEachLevel(root, 0, countAt);

        for(int level = 0; level < (int)countAt.size() - 1; ++level){
            if(countAt[level] != (1 << level)){
                return false;
            }
        }

        // Step 2: check if the nodes of the last/max level are as far left as possible
        int lastLevel = (int)countAt.size() - 1;
        TreeNode* prevNodeOfLastLevel = root;
        bool isValidLastLevel = true;
        checkLastLevel(root, 0, lastLevel, prevNodeOfLastLevel, isValidLastLevel);

        return isValidLastLevel;
    }
};