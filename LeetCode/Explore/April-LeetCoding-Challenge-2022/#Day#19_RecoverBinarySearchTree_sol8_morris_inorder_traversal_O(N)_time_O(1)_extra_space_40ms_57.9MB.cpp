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
    void update(TreeNode*& prev, TreeNode*& curr, TreeNode*& node1, TreeNode*& node2){
        if(prev != NULL && prev->val > curr->val){
            if(node1 == NULL){
                node1 = prev;
            }
            node2 = curr;
        }
        prev = curr;
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode* node1 = NULL;
        TreeNode* node2 = NULL;
        
        TreeNode* prev = NULL; // previous node
        TreeNode* curr = root; // current node
        TreeNode* pred = NULL; // inorder predecessor
        while(curr != NULL){
            if(curr->left == NULL){
                update(prev, curr, node1, node2);
                curr = curr->right;
            }else{
                pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    update(prev, curr, node1, node2);
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
        
        swap(node1->val, node2->val);
    }
};