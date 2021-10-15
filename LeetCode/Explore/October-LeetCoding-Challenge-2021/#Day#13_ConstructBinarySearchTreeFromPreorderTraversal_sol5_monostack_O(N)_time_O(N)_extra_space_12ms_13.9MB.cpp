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
    TreeNode* bstFromPreorder(int l, int r, vector<int>& preorder, vector<int>& nextGreater){
        if(l > r){
            return NULL;
        }
        
        int rootVal = preorder[l];
        int idx = nextGreater[l];
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = bstFromPreorder(l + 1, idx - 1, preorder, nextGreater);
        root->right = bstFromPreorder(idx, r, preorder, nextGreater);
        
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        const int N = preorder.size();
        
        stack<int> st;
        vector<int> nextGreater(N, N);
        for(int i = N - 1; i >= 0; --i){
            while(!st.empty() && preorder[i] >= preorder[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nextGreater[i] = st.top();
            }
            st.push(i);
        }
        
        return bstFromPreorder(0, N - 1, preorder, nextGreater);
    }
};