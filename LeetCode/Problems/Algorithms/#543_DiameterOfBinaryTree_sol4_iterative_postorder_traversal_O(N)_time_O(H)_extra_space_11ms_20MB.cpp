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
    void addLeftPath(TreeNode* node, stack<pair<TreeNode*, int>>& st){
        while(node != nullptr){
            st.push({node, 0});
            node = node->left;
        }
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;

        stack<pair<TreeNode*, int>> st;
        addLeftPath(root, st);

        TreeNode* prevPostOrderNode = nullptr;
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int height = st.top().second;

            if(node->right != nullptr && node->right != prevPostOrderNode){
                addLeftPath(node->right, st);
            }else{
                st.pop();

                if(!st.empty()){
                    if(st.top().first->left == node || st.top().first->right == node){
                        diameter = max(diameter, st.top().second + height + 1);
                        st.top().second = max(st.top().second, height + 1);
                    }
                }

                prevPostOrderNode = node;
            }
        }

        return diameter;
    }
};