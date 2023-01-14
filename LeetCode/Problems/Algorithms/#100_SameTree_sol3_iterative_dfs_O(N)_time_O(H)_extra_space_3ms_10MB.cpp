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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while(!st.empty()){
            TreeNode* a = st.top().first;
            TreeNode* b = st.top().second;
            st.pop();

            if((a == nullptr && b != nullptr) ||
               (a != nullptr && b == nullptr) ||
               (a != nullptr && b != nullptr && a->val != b->val)){
                return false;
            }

            if(a != nullptr && b != nullptr){
                st.push({a->right, b->right});
                st.push({a->left, b->left});
            }
        }

        return true;
    }
};