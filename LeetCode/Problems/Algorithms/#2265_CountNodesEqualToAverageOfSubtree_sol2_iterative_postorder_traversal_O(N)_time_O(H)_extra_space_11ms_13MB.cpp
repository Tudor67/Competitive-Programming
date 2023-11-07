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
    void addLeftPath(TreeNode* node, stack<tuple<TreeNode*, int, int>>& st){
        while(node != nullptr){
            st.push({node, 0, 0});
            node = node->left;
        }
    }

    void updateResult(TreeNode* node, int& subtreeSum, int& subtreeSize, int& res){
        subtreeSum += node->val;
        subtreeSize += 1;
        if(subtreeSum / subtreeSize == node->val){
            res += 1;
        }
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int res = 0;

        TreeNode* prevPostOrderNode = nullptr;
        stack<tuple<TreeNode*, int, int>> st;
        addLeftPath(root, st);

        while(!st.empty()){
            TreeNode* node = get<0>(st.top());
            int subtreeSum = get<1>(st.top());
            int subtreeSize = get<2>(st.top());

            if(node->right == nullptr || prevPostOrderNode == node->right){
                updateResult(node, subtreeSum, subtreeSize, res);
                prevPostOrderNode = node;
                st.pop();
                if(!st.empty()){
                    get<1>(st.top()) += subtreeSum;
                    get<2>(st.top()) += subtreeSize;
                }
            }else{
                addLeftPath(node->right, st);
            }
        }

        return res;
    }
};