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
        const int N = nums.size();
        
        if(N == 0){
            return nullptr;
        }
        
        int mid = N / 2;
        vector<int> leftSortedNums(vector<int>(nums.begin(), nums.begin() + mid));
        vector<int> rightSortedNums(vector<int>(nums.begin() + mid + 1, nums.end()));
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(leftSortedNums);
        root->right = sortedArrayToBST(rightSortedNums);
        
        return root;
    }
};