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
    void dfs(TreeNode* root, int sum, const int& TARGET_SUM, vector<int>& st, vector<vector<int>>& paths){
        if(root != NULL){
            if(sum == TARGET_SUM && root->left == NULL && root->right == NULL){
                paths.push_back(st);
            }
            for(TreeNode* child: {root->left, root->right}){
                if(child != NULL){
                    st.push_back(child->val);
                    dfs(child, sum + child->val, TARGET_SUM, st, paths);
                    st.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return {};
        }
        vector<int> st;
        vector<vector<int>> paths;
        st.push_back(root->val);
        dfs(root, root->val, targetSum, st, paths);
        return paths;
    }
};