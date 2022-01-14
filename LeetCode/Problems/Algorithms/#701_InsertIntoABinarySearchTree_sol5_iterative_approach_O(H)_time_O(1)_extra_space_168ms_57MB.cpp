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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode(val);
        }
        
        TreeNode* prevNode = NULL;
        TreeNode* currNode = root;
        while(currNode != NULL){
            prevNode = currNode;
            if(val < currNode->val){
                currNode = currNode->left;
            }else{
                currNode = currNode->right;
            }
        }
        
        if(val < prevNode->val){
            prevNode->left = new TreeNode(val);
        }else{
            prevNode->right = new TreeNode(val);
        }
        
        return root;
    }
};