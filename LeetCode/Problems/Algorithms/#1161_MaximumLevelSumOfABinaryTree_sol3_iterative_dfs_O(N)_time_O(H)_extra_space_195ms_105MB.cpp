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
    int maxLevelSum(TreeNode* root) {
        vector<int> sumAt;
        stack<pair<int, TreeNode*>> st;
        st.push({1, root});

        while(!st.empty()){
            int level = st.top().first;
            TreeNode* node = st.top().second;
            st.pop();

            if(level >= (int)sumAt.size()){
                sumAt.resize(level + 1);
            }
            sumAt[level] += node->val;

            if(node->right != nullptr){
                st.push({level + 1, node->right});
            }
            if(node->left != nullptr){
                st.push({level + 1, node->left});
            }
        }

        return max_element(sumAt.begin() + 1, sumAt.end()) - sumAt.begin();
    }
};