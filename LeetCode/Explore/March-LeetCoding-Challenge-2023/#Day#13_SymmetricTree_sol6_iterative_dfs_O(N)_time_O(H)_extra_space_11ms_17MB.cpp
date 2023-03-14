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
    bool isSymmetric(TreeNode* root) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({root, root});

        while(!st.empty()){
            TreeNode* root1 = st.top().first;
            TreeNode* root2 = st.top().second;
            st.pop();

            if(root1 == nullptr && root2 == nullptr){
                // ok
            }else if(root1 == nullptr || root2 == nullptr || root1->val != root2->val){
                return false;
            }else{
                st.push({root1->left, root2->right});
                st.push({root1->right, root2->left});
            }
        }

        return true;
    }
};