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
    void collectLeafValues(TreeNode* root, vector<int>& leafValues){
        stack<TreeNode*> st;
        if(root != nullptr){
            st.push(root);
        }

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if(node->left == nullptr && node->right == nullptr){
                leafValues.push_back(node->val);
            }
            
            if(node->right != nullptr){
                st.push(node->right);
            }
            if(node->left != nullptr){
                st.push(node->left);
            }
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValues1;
        collectLeafValues(root1, leafValues1);

        vector<int> leafValues2;
        collectLeafValues(root2, leafValues2);

        return (leafValues1 == leafValues2);
    }
};