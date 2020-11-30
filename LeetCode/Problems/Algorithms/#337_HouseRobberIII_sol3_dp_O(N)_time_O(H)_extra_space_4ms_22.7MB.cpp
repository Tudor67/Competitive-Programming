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
    pair<int, int> maxMoney(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        
        if(root->left == NULL && root->right == NULL){
            return {root->val, 0};
        }
        
        pair<int, int> leftP = maxMoney(root->left);
        pair<int, int> rightP = maxMoney(root->right);
        
        int leftMaxWithRoot = leftP.first;
        int leftMaxWithoutRoot = leftP.second;
        int rightMaxWithRoot = rightP.first;
        int rightMaxWithoutRoot = rightP.second;
        
        int maxWithRoot = root->val + leftMaxWithoutRoot + rightMaxWithoutRoot;
        int maxWithoutRoot = max(leftMaxWithRoot, leftMaxWithoutRoot) + max(rightMaxWithRoot, rightMaxWithoutRoot);
        
        return {maxWithRoot, maxWithoutRoot};
    }
    
public:
    int rob(TreeNode* root) {
        pair<int, int> p = maxMoney(root);
        int maxWithRoot = p.first;
        int maxWithoutRoot = p.second;
        return max(maxWithRoot, maxWithoutRoot);
    }
};