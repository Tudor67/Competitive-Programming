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
    void inorder(TreeNode* node, TreeNode*& prevNode, int& minDiff){
        if(node != nullptr){
            inorder(node->left, prevNode, minDiff);
            if(prevNode != nullptr){
                minDiff = min(minDiff, node->val - prevNode->val);
            }
            prevNode = node;
            inorder(node->right, prevNode, minDiff);
        }
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode* prevNode = nullptr;
        int minDiff = INT_MAX;
        inorder(root, prevNode, minDiff);
        return minDiff;
    }
};