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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()){
            return NULL;
        }
        
        const int N = nums.size();
        const int MID = N / 2;
        vector<int> leftNums(nums.begin(), nums.begin() + MID);
        vector<int> rightNums(nums.begin() + MID + 1, nums.end());
        
        TreeNode* root = new TreeNode(nums[MID]);
        root->left = sortedArrayToBST(leftNums);
        root->right = sortedArrayToBST(rightNums);
        
        return root;
    }
};