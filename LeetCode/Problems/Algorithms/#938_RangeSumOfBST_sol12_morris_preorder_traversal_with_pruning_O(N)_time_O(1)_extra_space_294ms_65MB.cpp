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
        int sum = 0;
        
        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            if(high < currentNode->val){
                currentNode = currentNode->left;
            }else if(currentNode->val < low){
                currentNode = currentNode->right;
            }else if(currentNode->left == nullptr){
                sum += currentNode->val;
                currentNode = currentNode->right;
            }else{
                TreeNode* predNode = currentNode->left;
                while(predNode->right != nullptr && predNode->right != currentNode){
                    predNode = predNode->right;
                }
                if(predNode->right == nullptr){
                    sum += currentNode->val;
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