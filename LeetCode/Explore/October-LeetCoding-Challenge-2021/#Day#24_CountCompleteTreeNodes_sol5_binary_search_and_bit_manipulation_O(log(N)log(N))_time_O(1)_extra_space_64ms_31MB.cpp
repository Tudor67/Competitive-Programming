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
    bool isValid(TreeNode* node, int bit, int path){
        while(node != NULL && bit >= 0){
            if((path >> bit) & 1){
                node = node->right;
            }else{
                node = node->left;
            }
            bit -= 1;
        }
        if(node == NULL){
            return false;
        }
        return true;
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