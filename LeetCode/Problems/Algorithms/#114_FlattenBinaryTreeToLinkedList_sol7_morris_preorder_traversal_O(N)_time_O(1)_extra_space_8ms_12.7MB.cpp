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
    void flatten(TreeNode* root) {
        TreeNode* currentNode = root;
        while(currentNode != NULL){
            if(currentNode->left == NULL){
                currentNode = currentNode->right;
            }else{
                TreeNode* predNode = currentNode->left;
                while(predNode->right != NULL){
                    predNode = predNode->right;
                }
                predNode->right = currentNode->right;
                currentNode->right = currentNode->left;
                currentNode->left = NULL;
            }
        }
    }
};