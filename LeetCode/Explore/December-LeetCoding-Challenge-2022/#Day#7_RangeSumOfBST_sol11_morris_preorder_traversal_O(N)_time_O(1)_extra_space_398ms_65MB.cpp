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
    void updateSum(TreeNode* currentNode, int low, int high, int& sum){
        if(currentNode != nullptr && low <= currentNode->val && currentNode->val <= high){
            sum += currentNode->val;
        }
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;

        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                updateSum(currentNode, low, high, sum);
                currentNode = currentNode->right;
            }else{
                TreeNode* predNode = currentNode->left;
                while(predNode->right != nullptr && predNode->right != currentNode){
                    predNode = predNode->right;
                }
                if(predNode->right == nullptr){
                    updateSum(currentNode, low, high, sum);
                    predNode->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    predNode->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }

        return sum;
    }
};