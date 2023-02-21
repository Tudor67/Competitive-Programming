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
    int maxDepth(TreeNode* root) {
        int res = 0;

        TreeNode* currentNode = root;
        int currentDepth = 1;
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                res = max(res, currentDepth);
                currentNode = currentNode->right;
                currentDepth += 1;
            }else{
                TreeNode* predNode = currentNode->left;
                int delta = 1;
                while(predNode->right != nullptr && predNode->right != currentNode){
                    predNode = predNode->right;
                    delta += 1;
                }
                if(predNode->right == nullptr){
                    predNode->right = currentNode;
                    currentNode = currentNode->left;
                    currentDepth += 1;
                }else{
                    predNode->right = nullptr;
                    currentNode = currentNode->right;
                    currentDepth -= delta;
                }
            }
        }

        return res;
    }
};