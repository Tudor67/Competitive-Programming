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
    pair<TreeNode*, TreeNode*> find(TreeNode* prev_node, TreeNode* node, int key){
        if(node == NULL){
            return {NULL, NULL};
        }
        
        if(node->val < key){
            return find(node, node->right, key);
        }else if(node->val > key){
            return find(node, node->left, key);
        }
        
        return {prev_node, node};
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* virtual_root = new TreeNode(0, NULL, root);
        pair<TreeNode*, TreeNode*> p = find(virtual_root, root, key);
        TreeNode* prev_node = p.first;
        TreeNode* node = p.second;
        
        if(node != NULL){
            TreeNode* next_node = NULL;
            if(node->left != NULL){
                next_node = node->left;
            }else if(node->right != NULL){
                next_node = node->right;
            }
            
            if(prev_node->left == node){
                prev_node->left = next_node;
            }else if(prev_node->right == node){
                prev_node->right = next_node;
            }
            
            if(next_node != NULL && next_node == node->left){
                while(next_node->right != NULL){
                    next_node = next_node->right;
                }
                next_node->right = node->right;
            }
        }
        
        return virtual_root->right;
    }
};