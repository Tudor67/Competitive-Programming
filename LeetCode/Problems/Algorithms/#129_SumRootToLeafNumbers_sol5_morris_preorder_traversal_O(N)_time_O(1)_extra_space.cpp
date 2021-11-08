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
        long long num = 0;
        TreeNode* currentNode = root;
        while(currentNode != NULL){
            num = 10 * num + currentNode->val;
            if(currentNode->left == NULL){
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
                    currentNode = currentNode->left;
                }else{
                    predecessorNode->right = NULL;
                    num /= 10;
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