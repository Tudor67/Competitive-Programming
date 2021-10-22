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
    pair<int, int> getParentAndDepth(TreeNode* node, int parent, int depth, int x){
        if(node != NULL){
            if(node->val == x){
                return {parent, depth};
            }else{
                return max(getParentAndDepth(node->left, node->val, depth + 1, x),
                           getParentAndDepth(node->right, node->val, depth + 1, x));
            }
        }
        return {-1, -1};
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> xPD = getParentAndDepth(root, -1, 0, x);
        pair<int, int> yPD = getParentAndDepth(root, -1, 0, y);
        return (xPD.first != yPD.first && xPD.second == yPD.second);
    }
};