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
        
        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                inorderValues.push_back(currentNode->val);
                currentNode = currentNode->right;
            }else{
                TreeNode* pred = currentNode->left;
                while(pred->right != nullptr && pred->right != currentNode){
                    pred = pred->right;
                }
                if(pred->right == nullptr){
                    pred->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    inorderValues.push_back(currentNode->val);
                    pred->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }
        
        return inorderValues;
    }
};