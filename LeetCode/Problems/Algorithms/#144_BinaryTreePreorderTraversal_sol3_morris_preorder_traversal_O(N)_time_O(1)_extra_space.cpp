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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorderNodes;
        TreeNode* predecessorNode = NULL;
        TreeNode* currentNode = root;
        while(currentNode != NULL){
            if(currentNode->left == NULL){
                preorderNodes.push_back(currentNode->val);
                currentNode = currentNode->right;
            }else{
                predecessorNode = currentNode->left;
                while(predecessorNode->right != NULL && predecessorNode->right != currentNode){
                    predecessorNode = predecessorNode->right;
                }
                if(predecessorNode->right == NULL){
                    predecessorNode->right = currentNode;
                    preorderNodes.push_back(currentNode->val);
                    currentNode = currentNode->left;
                }else{
                    predecessorNode->right = NULL;
                    currentNode = currentNode->right;
                }
            }
        }
        return preorderNodes;
    }
};