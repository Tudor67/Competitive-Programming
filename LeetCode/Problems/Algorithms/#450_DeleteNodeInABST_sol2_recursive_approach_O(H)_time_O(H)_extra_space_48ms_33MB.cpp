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
    void deleteNode(TreeNode* prevNode, TreeNode* node, bool isLeftSubtree, int key){
        if(node == NULL){
            // stop
        }else if(key < node->val){
            deleteNode(node, node->left, true, key);
        }else if(key > node->val){
            deleteNode(node, node->right, false, key);
        }else if(node->val == key){
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
            node->right = NULL;
            node->left = NULL;
            delete node;
        }
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* prevRoot = new TreeNode(INT_MAX);
        prevRoot->left = root;
        
        deleteNode(prevRoot, root, true, key);
        
        root = prevRoot->left;
        prevRoot->left = NULL;
        delete prevRoot;
        
        return root;
    }
};