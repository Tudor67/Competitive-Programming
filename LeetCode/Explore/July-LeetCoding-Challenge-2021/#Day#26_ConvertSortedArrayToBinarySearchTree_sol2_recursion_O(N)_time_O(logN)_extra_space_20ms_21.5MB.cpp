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
    TreeNode* sortedArrayToBST(vector<int>& nums, const int& L, const int& R){
        if(L > R){
            return NULL;
        }
        
        const int N = R - L + 1;
        const int MID = (L + R) / 2;
        TreeNode* root = new TreeNode(nums[MID]);
        root->left = sortedArrayToBST(nums, L, MID - 1);
        root->right = sortedArrayToBST(nums, MID + 1, R);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int N = nums.size();
        return sortedArrayToBST(nums, 0, N - 1);
    }
};