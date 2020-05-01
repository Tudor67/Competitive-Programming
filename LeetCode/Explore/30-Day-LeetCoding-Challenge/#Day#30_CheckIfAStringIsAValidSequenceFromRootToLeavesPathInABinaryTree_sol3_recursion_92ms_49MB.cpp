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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(!arr.empty() && root && root->val == arr[0]){
            if(arr.size() == 1){
                return (!root->left && !root->right);
            }
            
            vector<int> arr2{arr.begin() + 1, arr.end()};
            return (root->left && isValidSequence(root->left, arr2)) ||
                   (root->right && isValidSequence(root->right, arr2));
        }
        
        return false;
    }
};