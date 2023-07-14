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
    int minDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }

        int res = INT_MAX;
        TreeNode* curNode = root;
        int curDepth = 1;

        while(curNode != nullptr){
            if(curNode->left == nullptr){
                if(curNode->right == nullptr){
                    res = min(res, curDepth);
                }
                curNode = curNode->right;
                curDepth += 1;
            }else{
                TreeNode* predNode = curNode->left;
                int depthDelta = 1;
                while(predNode->right != nullptr && predNode->right != curNode){
                    predNode = predNode->right;
                    depthDelta += 1;
                }
                if(predNode->right == nullptr){
                    predNode->right = curNode;
                    curNode = curNode->left;
                    curDepth += 1;
                }else{
                    predNode->right = nullptr;
                    if(predNode->left == nullptr){
                        res = min(res, curDepth - 1);
                    }
                    curNode = curNode->right;
                    curDepth -= depthDelta;
                }
            }
        }

        return res;
    }
};