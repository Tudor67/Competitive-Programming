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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prevRoot = new TreeNode(INT_MAX);
        prevRoot->left = root;
        
        TreeNode* prevNode = prevRoot;
        TreeNode* node = root;
        bool isLeftSubtree = true;
        while(node != NULL && node->val != key){
            prevNode = node;
            if(key < node->val){
                node = node->left;
                isLeftSubtree = true;
            }else if(key > node->val){
                node = node->right;
                isLeftSubtree = false;
            }
        }
        
        if(node != NULL && node->val == key){
            if(node->left == NULL){
                if(isLeftSubtree){
                    prevNode->left = node->right;
                }else{
                    prevNode->right = node->right;
                }
            }else{
                TreeNode* predNode = node->left;
                while(predNode->right != NULL){
                    predNode = predNode->right;
                }
                predNode->right = node->right;
                if(isLeftSubtree){
                    prevNode->left = node->left;
                }else{
                    prevNode->right = node->left;
                }
            }
            node->left = NULL;
            node->right = NULL;
            delete node;
        }
        
        root = prevRoot->left;
        prevRoot->left = NULL;
        delete prevRoot;
        
        return root;
    }
};