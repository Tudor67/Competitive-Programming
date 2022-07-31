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
    void flatten(TreeNode* node, TreeNode*& prevNode){
        if(node != NULL){
            TreeNode* leftChild = node->left;
            TreeNode* rightChild = node->right;
            if(prevNode != NULL){
                prevNode->left = NULL;
                prevNode->right = node;
            }
            prevNode = node;
            flatten(leftChild, prevNode);
            flatten(rightChild, prevNode);
        }
    }
    
public:
    void flatten(TreeNode* root) {
        TreeNode* prevNode = NULL;
        flatten(root, prevNode);
    }
};