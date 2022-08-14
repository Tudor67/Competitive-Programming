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
    void inorderTraversal(TreeNode*& prevNode, TreeNode* node, bool& isValid){
        if(node != nullptr && isValid){
            inorderTraversal(prevNode, node->left, isValid);
            if(prevNode != nullptr && prevNode->val >= node->val){
                isValid = false;
            }
            prevNode = node;
            inorderTraversal(prevNode, node->right, isValid);
        }
    }
    
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prevNode = nullptr;
        bool isValid = true;
        inorderTraversal(prevNode, root, isValid);
        return isValid;
    }
};