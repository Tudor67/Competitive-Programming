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
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r){
        const int N = r - l + 1;
        
        if(N == 0){
            return nullptr;
        }
        
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, l, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, r);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int N = nums.size();
        return sortedArrayToBST(nums, 0, N - 1);
    }
};