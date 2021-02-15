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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode* currNode = root;
        TreeNode* succNode = NULL;
        int sum = 0;
        while(currNode != NULL){
            if(currNode->right == NULL){
                sum += currNode->val;
                currNode->val = sum;
                currNode = currNode->left;
            }else{
                succNode = currNode->right;
                while(succNode->left != NULL && succNode->left != currNode){
                    succNode = succNode->left;
                }
                if(succNode->left == NULL){
                    succNode->left = currNode;
                    currNode = currNode->right;
                }else{
                    succNode->left = NULL;
                    sum += currNode->val;
                    currNode->val = sum;
                    currNode= currNode->left;
                }
            }
        }
        return root;
    }
};