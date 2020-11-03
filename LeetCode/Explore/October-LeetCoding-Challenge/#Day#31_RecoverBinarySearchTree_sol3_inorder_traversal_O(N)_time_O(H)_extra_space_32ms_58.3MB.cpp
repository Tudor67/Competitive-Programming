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
    void inorderTraversal(TreeNode* root, TreeNode*& prevRoot, TreeNode*& node1, TreeNode*& node2){
        if(root != NULL){
            inorderTraversal(root->left, prevRoot, node1, node2);
            if(prevRoot != NULL && prevRoot->val > root->val){
                if(node1 == NULL){
                    node1 = prevRoot;
                }
                node2 = root;
            }
            prevRoot = root;
            inorderTraversal(root->right, prevRoot, node1, node2);
        }
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prevRoot = NULL;
        TreeNode* node1 = NULL;
        TreeNode* node2 = NULL;
        
        inorderTraversal(root, prevRoot, node1, node2);
        
        swap(node1->val, node2->val);
    }
};