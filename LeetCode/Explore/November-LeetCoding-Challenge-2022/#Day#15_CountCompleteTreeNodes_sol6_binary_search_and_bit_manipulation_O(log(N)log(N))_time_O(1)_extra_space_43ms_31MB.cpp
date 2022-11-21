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
    int getMaxLevel(TreeNode* root){
        int level = -1;
        while(root != nullptr){
            level += 1;
            root = root->left;
        }
        return level;
    }
    
    bool isPossible(TreeNode* root, int startBit, int pathMask){
        int bit = startBit;
        while(bit >= 0 && root != nullptr){
            if((pathMask >> bit) & 1){
                root = root->right;
            }else{
                root = root->left;
            }
            bit -= 1;
        }
        return (bit == -1 && root != nullptr);
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int maxLevel = getMaxLevel(root);
        int l = (1 << maxLevel);
        int r = (1 << (maxLevel + 1)) - 1;
        
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(root, maxLevel - 1, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};