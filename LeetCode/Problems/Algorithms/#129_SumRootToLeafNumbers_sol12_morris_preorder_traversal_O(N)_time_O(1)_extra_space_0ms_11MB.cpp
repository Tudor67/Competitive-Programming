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
    void updateResult(TreeNode* currNode, int currNum, int& sum){
        if(currNode->left == nullptr && currNode->right == nullptr){
            sum += currNum;
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;

        TreeNode* currNode = root;
        int currNum = 0;

        while(currNode != nullptr){
            if(currNode->left == nullptr){
                currNum = currNum * 10 + currNode->val;
                updateResult(currNode, currNum, sum);
                currNode = currNode->right;
            }else{
                TreeNode* predNode = currNode->left;
                int depthPow = 10;
                while(predNode->right != nullptr && predNode->right != currNode){
                    predNode = predNode->right;
                    depthPow *= 10;
                }

                if(predNode->right == nullptr){
                    predNode->right = currNode;
                    currNum = currNum * 10 + currNode->val;
                    currNode = currNode->left;
                }else{
                    predNode->right = nullptr;
                    updateResult(predNode, currNum, sum);
                    currNum /= depthPow;
                    currNode = currNode->right;
                }
            }
        }

        return sum;
    }
};