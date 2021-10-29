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
    bool isValid(TreeNode* root, int bit, int path){
        if(root == NULL){
            return false;
        }
        if(bit == -1){
            return true;
        }
        if((path >> bit) & 1){
            return isValid(root->right, bit - 1, path);
        }else{
            return isValid(root->left, bit - 1, path);
        }
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int maxBit = 0;
        for(TreeNode* node = root; node->left != NULL; node = node->left){
            maxBit += 1;
        }
        
        int l = (1 << maxBit);
        int r = (1 << (maxBit + 1)) - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(root, maxBit - 1, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};