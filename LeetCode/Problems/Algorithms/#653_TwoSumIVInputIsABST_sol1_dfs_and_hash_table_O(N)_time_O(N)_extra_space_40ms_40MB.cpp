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
    void dfs(TreeNode* root, int k, unordered_set<int>& seen, bool& found){
        if(root != NULL && !found){
            dfs(root->left, k, seen, found);
            dfs(root->right, k, seen, found);
            if(seen.count(k - root->val)){
                found = true;
            }
            seen.insert(root->val);
        }
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        bool found = false;
        dfs(root, k, seen, found);
        return found;
    }
};