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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;

        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                values.push_back(currentNode->val);
                currentNode = currentNode->right;
            }else{
                TreeNode* predNode = currentNode->left;
                while(predNode->right != nullptr && predNode->right != currentNode){
                    predNode = predNode->right;
                }
                if(predNode->right == nullptr){
                    values.push_back(currentNode->val);
                    predNode->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    predNode->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }

        return values;
    }
};