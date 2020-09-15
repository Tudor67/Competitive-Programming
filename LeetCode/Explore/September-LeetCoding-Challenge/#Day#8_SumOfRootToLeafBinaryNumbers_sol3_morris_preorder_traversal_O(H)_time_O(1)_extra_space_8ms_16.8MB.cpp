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
    int sumRootToLeaf(TreeNode* root) {
        // Morris Preorder Traversal with O(1) extra-space
        TreeNode* node = root;
        TreeNode* predecessor = NULL;
        int sum = 0;
        int num = 0;
        int steps = 0;
        
        while(node != NULL){
            if(node->left == NULL){
                num = 2 * num + node->val;
                if(node->right == NULL){
                    sum += num;
                }
                node = node->right;
            }else{
                steps = 1;
                predecessor = node->left;
                while(predecessor->right != NULL && predecessor->right != node){
                    predecessor = predecessor->right;
                    steps += 1;
                }
                
                if(predecessor->right == NULL){
                    // add a temporary link from the rightmost node of the left subtree to the current node
                    num = 2 * num + node->val;
                    predecessor->right = node;
                    node = node->left;
                }else if(predecessor->right == node){
                    // remove the temporary link to avoid cycles and to keep the initial/original tree
                    predecessor->right = NULL;
                    if(predecessor->left == NULL){
                        sum += num;
                    }
                    num = (num >> steps);
                    node = node->right;
                }
            }
        }
        
        return sum;
    }
};