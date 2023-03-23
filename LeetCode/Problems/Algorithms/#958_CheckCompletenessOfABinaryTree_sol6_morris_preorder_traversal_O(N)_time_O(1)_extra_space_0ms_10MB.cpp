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
    int computeMaxLevel(TreeNode* root){
        int maxLevel = 0;

        int level = 0;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left == nullptr){
                level += 1;
                curr = curr->right;
            }else{
                int delta = 1;
                TreeNode* pred = curr->left;
                while(pred->right != nullptr && pred->right != curr){
                    delta += 1;
                    pred = pred->right;
                }

                if(pred->right == nullptr){
                    level += 1;
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    level -= delta;
                    pred->right = nullptr;
                    curr = curr->right;
                }

                maxLevel = max(maxLevel, level);
            }
        }
        
        maxLevel = max(maxLevel, level - 1);

        return maxLevel;
    }

    void updateResult(int& prevNullLevel, int level, int maxLevel, bool& isComplete){
        if(prevNullLevel >= level && level >= maxLevel){
            prevNullLevel = level;
        }else{
            isComplete = false;
        }
    }

    void checkCompleteness(TreeNode* root, int maxLevel, bool& isComplete){
        int prevNullLevel = maxLevel + 1;

        int level = 0;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left == nullptr){
                level += 1;
                updateResult(prevNullLevel, level, maxLevel, isComplete);
                curr = curr->right;
            }else{
                int delta = 1;
                TreeNode* pred = curr->left;
                while(pred->right != nullptr && pred->right != curr){
                    delta += 1;
                    pred = pred->right;
                }

                if(pred->right == nullptr){
                    level += 1;
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    updateResult(prevNullLevel, level, maxLevel, isComplete);
                    level -= delta;
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        updateResult(prevNullLevel, level, maxLevel, isComplete);
    }

public:
    bool isCompleteTree(TreeNode* root) {
        int maxLevel = computeMaxLevel(root);

        bool isComplete = true;
        checkCompleteness(root, maxLevel, isComplete);

        return isComplete;
    }
};