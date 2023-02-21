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
    void inorder(TreeNode*& prevNode, TreeNode* currentNode, int& minDiff){
        if(currentNode != nullptr){
            inorder(prevNode, currentNode->left, minDiff);
            if(prevNode != nullptr){
                minDiff = min(minDiff, currentNode->val - prevNode->val);
            }
            prevNode = currentNode;
            inorder(prevNode, currentNode->right, minDiff);
        }
    }

public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prevNode = nullptr;
        inorder(prevNode, root, minDiff);
        return minDiff;
    }
};