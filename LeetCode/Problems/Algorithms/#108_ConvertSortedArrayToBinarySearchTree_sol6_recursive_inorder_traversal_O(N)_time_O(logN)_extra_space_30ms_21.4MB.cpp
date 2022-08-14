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
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r, int& idx){
        TreeNode* root = nullptr;
        if(l <= r){
            int mid = (l + r) / 2;
            root = new TreeNode();
            root->left = sortedArrayToBST(nums, l, mid - 1, idx);
            root->val = nums[idx];
            idx += 1;
            root->right = sortedArrayToBST(nums, mid + 1, r, idx);
        }
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int N = nums.size();
        int idx = 0;
        return sortedArrayToBST(nums, 0, N - 1, idx);
    }
};