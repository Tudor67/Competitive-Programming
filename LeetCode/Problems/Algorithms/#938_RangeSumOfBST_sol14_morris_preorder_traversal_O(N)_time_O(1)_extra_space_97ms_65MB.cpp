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
    void updateRangeSum(TreeNode* currNode, int low, int high, int& rangeSum){
        if(currNode != nullptr && low <= currNode->val && currNode->val <= high){
            rangeSum += currNode->val;
        }
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int rangeSum = 0;

        TreeNode* currNode = root;
        while(currNode != nullptr){
            if(currNode->left == nullptr){
                updateRangeSum(currNode, low, high, rangeSum);
                currNode = currNode->right;
            }else{
                TreeNode* predNode = currNode->left;
                while(predNode->right != nullptr && predNode->right != currNode){
                    predNode = predNode->right;
                }

                if(predNode->right == nullptr){
                    predNode->right = currNode;
                    updateRangeSum(currNode, low, high, rangeSum);
                    currNode = currNode->left;
                }else{
                    predNode->right = nullptr;
                    currNode = currNode->right;
                }
            }
        }

        return rangeSum;
    }
};