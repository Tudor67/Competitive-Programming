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
    void dfs(TreeNode* root, const vector<int>& arr, int idx, bool& is_valid){
        if(!is_valid && idx < arr.size() && root && root->val == arr[idx]){
            if(idx == (int)arr.size() - 1){
                is_valid |= (!root->left && !root->right);
            }else{
                dfs(root->left, arr, idx + 1, is_valid);
                dfs(root->right, arr, idx + 1, is_valid);
            }
        }
    }
    
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        bool is_valid = false;
        dfs(root, arr, 0, is_valid);
        return is_valid;
    }
};