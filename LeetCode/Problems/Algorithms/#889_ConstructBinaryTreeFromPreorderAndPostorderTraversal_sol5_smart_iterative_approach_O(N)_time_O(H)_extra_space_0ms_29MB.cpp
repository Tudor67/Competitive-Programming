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
    void addLeftPath(stack<TreeNode*>& st, vector<int>& preorder, int& preIndex, int postVal){
        do{
            if(st.empty()){
                st.push(new TreeNode(preorder[preIndex]));
            }else if(st.top()->left == nullptr){
                st.top()->left = new TreeNode(preorder[preIndex]);
                st.push(st.top()->left);
            }else{
                st.top()->right = new TreeNode(preorder[preIndex]);
                st.push(st.top()->right);
            }
            preIndex += 1;
        }while(st.top()->val != postVal);
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        stack<TreeNode*> st;
        int preIndex = 0;

        addLeftPath(st, preorder, preIndex, postorder[0]);

        for(int postIndex = 1; postIndex < (int)postorder.size(); ++postIndex){
            st.pop();
            if(st.top()->val != postorder[postIndex]){
                addLeftPath(st, preorder, preIndex, postorder[postIndex]);
            }
        }

        return st.top();
    }
};