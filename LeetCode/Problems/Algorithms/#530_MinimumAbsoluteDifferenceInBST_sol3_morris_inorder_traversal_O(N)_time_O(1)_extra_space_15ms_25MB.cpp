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
    void updateResult(TreeNode*& prevVisitedNode, TreeNode*& currentNode, int& minDiff){
        if(prevVisitedNode != nullptr){
            minDiff = min(minDiff, currentNode->val - prevVisitedNode->val);
        }
        prevVisitedNode = currentNode;
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prevVisitedNode = nullptr;

        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                updateResult(prevVisitedNode, currentNode, minDiff);
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
                    updateResult(prevVisitedNode, currentNode, minDiff);
                    predNode->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }

        return minDiff;
    }
};