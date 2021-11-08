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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int num = 0;
        TreeNode* currentNode = root;
        while(currentNode != NULL){
            if(currentNode->left == NULL){
                num = 10 * num + currentNode->val;
                if(currentNode->right == NULL){
                    sum += num;
                }
                currentNode = currentNode->right;
            }else{
                TreeNode* predecessorNode = currentNode->left;
                int depth = 1;
                while(predecessorNode->right != NULL && predecessorNode->right != currentNode){
                    predecessorNode = predecessorNode->right;
                    depth += 1;
                }
                if(predecessorNode->right == NULL){
                    predecessorNode->right = currentNode;
                    num = 10 * num + currentNode->val;
                    currentNode = currentNode->left;
                }else{
                    predecessorNode->right = NULL;
                    if(predecessorNode->left == NULL){
                        sum += num;
                    }
                    num /= pow(10, depth);
                    currentNode = currentNode->right;
                }
            }
        }
        return sum;
    }
};