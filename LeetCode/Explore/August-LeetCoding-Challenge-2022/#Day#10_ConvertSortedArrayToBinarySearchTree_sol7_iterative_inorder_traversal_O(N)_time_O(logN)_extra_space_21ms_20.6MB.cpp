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
    void addLeftPath(stack<tuple<TreeNode*, int, int>>& st){        
        while(true){
            TreeNode* currentRoot;
            int l, r;
            tie(currentRoot, l, r) = st.top();
            
            int mid = (l + r) / 2;
            if(l <= mid - 1){
                currentRoot->left = new TreeNode();
                st.emplace(currentRoot->left, l, mid - 1);
            }else{
                break;
            }
        }
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int N = nums.size();
        
        TreeNode* root = new TreeNode();
        stack<tuple<TreeNode*, int, int>> st;
        st.emplace(root, 0, N - 1);
        addLeftPath(st);
        
        int idx = 0;
        while(!st.empty()){
            TreeNode* currentRoot;
            int l, r;
            tie(currentRoot, l, r) = st.top();
            st.pop();
            
            currentRoot->val = nums[idx];
            idx += 1;
            
            int mid = (l + r) / 2;
            if(mid + 1 <= r){
                currentRoot->right = new TreeNode();
                st.emplace(currentRoot->right, mid + 1, r);
                addLeftPath(st);
            }
        }
        
        return root;
    }
};