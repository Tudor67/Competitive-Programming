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
    void updateResult(TreeNode* curr, int level, int& maxLevel, int& leftmostValue){
        if(maxLevel < level){
            maxLevel = level;
            leftmostValue = curr->val;
        }
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int maxLevel = -1;
        int leftmostValue = 0;

        TreeNode* curr = root;
        int level = 0;
        while(curr != nullptr){
            if(curr->left == nullptr){
                updateResult(curr, level, maxLevel, leftmostValue);
                curr = curr->right;
                level += 1;
            }else{
                TreeNode* pred = curr->left;
                int delta = 1;
                while(pred->right != nullptr && pred->right != curr){
                    pred = pred->right;
                    delta += 1;
                }

                if(pred->right == nullptr){
                    pred->right = curr;
                    updateResult(curr, level, maxLevel, leftmostValue);
                    curr = curr->left;
                    level += 1;
                }else{
                    pred->right = nullptr;
                    level -= delta;
                    curr = curr->right;
                }
            }
        }

        return leftmostValue;
    }
};