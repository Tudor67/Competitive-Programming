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
    void addLeftPath(stack<TreeNode*>& st, TreeNode* node){
        while(node != nullptr){
            st.push(node);
            node = node->left;
        }
    }

public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        stack<TreeNode*> st;
        addLeftPath(st, root);

        TreeNode* prevNode = nullptr;
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();

            if(prevNode != nullptr){
                minDiff = min(minDiff, node->val - prevNode->val);
            }
            prevNode = node;

            addLeftPath(st, node->right);
        }

        return minDiff;
    }
};