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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* prevRoot = new TreeNode(INT_MIN, NULL, root);
        
        stack<pair<TreeNode*, TreeNode*>> firstStack;
        stack<pair<TreeNode*, TreeNode*>> secondStack;
        firstStack.emplace(prevRoot, root);
        while(!firstStack.empty()){
            TreeNode* parent = firstStack.top().first;
            TreeNode* node = firstStack.top().second;
            firstStack.pop();
            
            if(node->left != NULL){
                firstStack.emplace(node, node->left);
            }
            if(node->right != NULL){
                firstStack.emplace(node, node->right);
            }
            
            secondStack.emplace(parent, node);
        }
        
        while(!secondStack.empty()){
            TreeNode* parent = secondStack.top().first;
            TreeNode* node = secondStack.top().second;
            secondStack.pop();
            
            if(node->val < low){
                if(parent->left == node){
                    parent->left = node->right;
                }else{
                    parent->right = node->right;
                }
                node->left = NULL;
                node->right = NULL;
            }else if(high < node->val){
                if(parent->left == node){
                    parent->left = node->left;
                }else{
                    parent->right = node->left;
                }
                node->left = NULL;
                node->right = NULL;
            }
        }
        
        root = prevRoot->right;
        prevRoot->right = NULL;
        delete prevRoot;
        
        return root;
    }
};