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
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int rangeSum = 0;

        TreeNode* currNode = root;
        while(currNode != nullptr){
            if(currNode->val < low){
                currNode = currNode->right;
            }else if(high < currNode->val){
                currNode = currNode->left;
            }else if(currNode->left == nullptr){
                rangeSum += currNode->val;
                currNode = currNode->right;
            }else{
                TreeNode* predNode = currNode->left;
                while(predNode->right != nullptr && predNode->right != currNode){
                    predNode = predNode->right;
                }

                if(predNode->right == nullptr){
                    predNode->right = currNode;
                    rangeSum += currNode->val;
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