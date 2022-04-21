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
    void inorder(TreeNode* node, TreeNode*& pred, TreeNode*& node1, TreeNode*& node2){
        if(node != NULL){
            inorder(node->left, pred, node1, node2);
            if(pred != NULL && pred->val > node->val){
                if(node1 == NULL){
                    node1 = pred;
                }
                node2 = node;
            }
            pred = node;
            inorder(node->right, pred, node1, node2);
        }
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pred = NULL;
        TreeNode* node1 = NULL;
        TreeNode* node2 = NULL;
        
        inorder(root, pred, node1, node2);
        
        swap(node1->val, node2->val);
    }
};