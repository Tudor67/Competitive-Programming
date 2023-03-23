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
    int countNodes(TreeNode* root){
        int totalNodes = 0;
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left == nullptr){
                totalNodes += 1;
                curr = curr->right;
            }else{
                TreeNode* pred = curr->left;
                while(pred->right != nullptr && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == nullptr){
                    totalNodes += 1;
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return totalNodes;
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