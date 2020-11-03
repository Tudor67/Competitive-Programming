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
    void updateNode1Node2(TreeNode* prev, TreeNode* root, TreeNode*& node1, TreeNode*& node2){
        if(prev != NULL && prev->val > root->val){
            if(node1 == NULL){
                node1 = prev;
            }
            node2 = root;
        }
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* node1 = NULL;
        TreeNode* node2 = NULL;
        
        // Morris Inorder Traversal
        // Complexity: O(N) time and O(1) extra space
        TreeNode* pred;
        while(root != NULL){
            if(root->left == NULL){
                updateNode1Node2(prev, root, node1, node2);
                prev = root;
                root = root->right;
            }else{
                // find the predecessor of the current root (the rightmost node of its left subtree)
                pred = root->left;
                while(pred->right != NULL && pred->right != root){
                    pred = pred->right;
                }
                
                if(pred->right == NULL){
                    // update the right link of pred (set it to the root)
                    pred->right = root;
                    root = root->left;
                }else{
                    updateNode1Node2(prev, root, node1, node2);
                    prev = root;
                    // update the right link of pred (set it to NULL)
                    pred->right = NULL;
                    root = root->right;
                }
            }
        }
        
        swap(node1->val, node2->val);
    }
};