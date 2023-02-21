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
    void updateResult(TreeNode* prevNode, TreeNode* currentNode, int& minDiff){
        if(prevNode != nullptr){
            minDiff = min(minDiff, currentNode->val - prevNode->val);
        }
    }

public:
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;

        TreeNode* prevNode = nullptr;
        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                updateResult(prevNode, currentNode, minDiff);
                prevNode = currentNode;
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
                    updateResult(prevNode, currentNode, minDiff);
                    prevNode = currentNode;
                    predNode->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }

        return minDiff;
    }
};