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
    void checkAndUpdate(TreeNode*& previousNode, TreeNode*& currentNode, bool& isValid){
        if(previousNode != nullptr && previousNode->val >= currentNode->val){
            isValid = false;
        }
        previousNode = currentNode;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        bool isValid = true;
        
        TreeNode* previousNode = nullptr;
        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                checkAndUpdate(previousNode, currentNode, isValid);
                currentNode = currentNode->right;
            }else{
                TreeNode* predNode = currentNode->left;
                while(predNode->right != nullptr && predNode->right != currentNode){
                    predNode = predNode->right;
                }
                if(predNode->right == nullptr){
                    predNode->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    checkAndUpdate(previousNode, currentNode, isValid);
                    predNode->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }
        
        return isValid;
    }
};