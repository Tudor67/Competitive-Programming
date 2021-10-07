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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderNodes;
        TreeNode* predecessorNode = NULL;
        TreeNode* currentNode = root;
        while(currentNode != NULL){
            if(currentNode->left == NULL){
                inorderNodes.push_back(currentNode->val);
                currentNode = currentNode->right;
            }else{
                predecessorNode = currentNode->left;
                while(predecessorNode->right != NULL && predecessorNode->right != currentNode){
                    predecessorNode = predecessorNode->right;
                }
                if(predecessorNode->right == NULL){
                    predecessorNode->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    inorderNodes.push_back(currentNode->val);
                    predecessorNode->right = NULL;
                    currentNode = currentNode->right;
                }
            }
        }
        return inorderNodes;
    }
};