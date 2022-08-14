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
        
        TreeNode* root = new TreeNode();
        stack<tuple<TreeNode*, int, int>> st;
        st.emplace(root, 0, N - 1);
        
        while(!st.empty()){
            TreeNode* currentRoot;
            int l, r;
            tie(currentRoot, l, r) = st.top();
            st.pop();
            
            int mid = (l + r) / 2;
            currentRoot->val = nums[mid];
            
            if(mid + 1 <= r){
                currentRoot->right = new TreeNode();
                st.emplace(currentRoot->right, mid + 1, r);
            }
            if(l <= mid - 1){
                currentRoot->left = new TreeNode();
                st.emplace(currentRoot->left, l, mid - 1);
            }
        }
        
        return root;
    }
};