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
    int countNodes(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    bool isValidPath(TreeNode* node, int pathMask){
        int currentBit = log2(pathMask) - 1;
        while(currentBit >= 0 && node != nullptr){
            int currentBitVal = (pathMask >> currentBit) & 1;
            if(currentBitVal == 0){
                node = node->left;
            }else{
                node = node->right;
            }
            currentBit -= 1;
        }
        return (currentBit < 0 && node != nullptr);
    }

public:
    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        for(int pathMask = 1; pathMask <= totalNodes; ++pathMask){
            if(!isValidPath(root, pathMask)){
                return false;
            }
        }
        return true;
    }
};