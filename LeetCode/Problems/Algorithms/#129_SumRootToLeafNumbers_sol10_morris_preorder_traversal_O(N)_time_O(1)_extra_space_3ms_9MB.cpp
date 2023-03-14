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
    void updateSum(TreeNode* node, int& num, int& sum){
        if(node->left == nullptr && node->right == nullptr){
            sum += num;
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int num = 0;
        TreeNode* currNode = root;

        while(currNode != nullptr){
            if(currNode->left == nullptr){
                num = num * 10 + currNode->val;
                updateSum(currNode, num, sum);
                currNode = currNode->right;
            }else{
                int p10 = 10;
                TreeNode* predNode = currNode->left;
                while(predNode->right != nullptr && predNode->right != currNode){
                    p10 *= 10;
                    predNode = predNode->right;
                }
                
                if(predNode->right == nullptr){
                    predNode->right = currNode;
                    num = num * 10 + currNode->val;
                    currNode = currNode->left;
                }else{
                    predNode->right = nullptr;
                    updateSum(predNode, num, sum);
                    num /= p10;
                    currNode = currNode->right;
                }
            }
        }

        return sum;
    }
};