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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderValues;

        TreeNode* currNode = root;
        while(currNode != nullptr){
            if(currNode->left == nullptr){
                inorderValues.push_back(currNode->val);
                currNode = currNode->right;
            }else{
                TreeNode* predNode = currNode->left;
                while(predNode->right != nullptr && predNode->right != currNode){
                    predNode = predNode->right;
                }

                if(predNode->right == nullptr){
                    predNode->right = currNode;
                    currNode = currNode->left;
                }else{
                    predNode->right = nullptr;
                    inorderValues.push_back(currNode->val);
                    currNode = currNode->right;
                }
            }
        }

        return inorderValues;
    }
};