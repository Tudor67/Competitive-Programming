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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const int N = preorder.size();

        stack<TreeNode*> st;
        st.push(new TreeNode(preorder[0]));

        for(int preIndex = 1, postIndex = 0; preIndex < N; ++preIndex){
            while(postIndex < N && st.top()->val == postorder[postIndex]){
                st.pop();
                postIndex += 1;
            }
            
            TreeNode* node = new TreeNode(preorder[preIndex]);
            if(st.top()->left == nullptr){
                st.top()->left = node;
            }else{
                st.top()->right = node;
            }
            st.push(node);
        }

        while((int)st.size() >= 2){
            st.pop();
        }

        return st.top();
    }
};