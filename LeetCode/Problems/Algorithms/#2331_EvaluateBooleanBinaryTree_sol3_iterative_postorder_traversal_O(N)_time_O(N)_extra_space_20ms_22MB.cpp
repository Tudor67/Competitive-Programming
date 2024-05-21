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
    bool evaluateTree(TreeNode* root) {
        unordered_map<TreeNode*, bool> nodeToVal;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node = st.top();

            if(node->left == nullptr && node->right == nullptr){
                st.pop();
                nodeToVal[node] = node->val;
            }else if(nodeToVal.count(node->left) && nodeToVal.count(node->right)){
                st.pop();
                if(node->val == 2){
                    nodeToVal[node] = nodeToVal[node->left] || nodeToVal[node->right];
                }else{
                    nodeToVal[node] = nodeToVal[node->left] && nodeToVal[node->right];
                }
            }else{
                st.push(node->right);
                st.push(node->left);
            }
        }

        return nodeToVal[root];
    }
};