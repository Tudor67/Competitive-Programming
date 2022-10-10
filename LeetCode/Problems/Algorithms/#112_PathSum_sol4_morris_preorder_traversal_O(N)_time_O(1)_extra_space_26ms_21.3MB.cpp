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
    void updateResult(TreeNode* node, int sum, int targetSum, bool& found){
        if(node->left == nullptr && node->right == nullptr && sum == targetSum){
            found = true;
        }
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool found = false;
        int currentSum = 0;
        TreeNode* currentNode = root;
        
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                currentSum += currentNode->val;
                updateResult(currentNode, currentSum, targetSum, found);
                currentNode = currentNode->right;
            }else{
                TreeNode* predNode = currentNode->left;
                int subPathSum = predNode->val;
                while(predNode->right != nullptr && predNode->right != currentNode){
                    subPathSum += predNode->right->val;
                    predNode = predNode->right;
                }
                
                if(predNode->right == nullptr){
                    predNode->right = currentNode;
                    currentSum += currentNode->val;
                    currentNode = currentNode->left;
                }else{
                    predNode->right = nullptr;
                    updateResult(predNode, currentSum, targetSum, found);
                    currentSum -= subPathSum;
                    currentNode = currentNode->right;
                }
            }
        }
        
        return found;
    }
};