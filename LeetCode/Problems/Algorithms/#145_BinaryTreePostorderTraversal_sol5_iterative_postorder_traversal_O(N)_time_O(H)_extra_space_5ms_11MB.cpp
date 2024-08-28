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
    void addLeftPath(TreeNode* node, stack<TreeNode*>& st){
        while(node != nullptr){
            st.push(node);
            node = node->left;
        }
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderValues;

        stack<TreeNode*> st;
        TreeNode* postorderPrevNode = nullptr;
        addLeftPath(root, st);

        while(!st.empty()){
            TreeNode* node = st.top();

            if(node->right != nullptr && node->right != postorderPrevNode){
                addLeftPath(node->right, st);
            }else{
                postorderValues.push_back(node->val);
                postorderPrevNode = node;
                st.pop();
            }
        }

        return postorderValues;
    }
};