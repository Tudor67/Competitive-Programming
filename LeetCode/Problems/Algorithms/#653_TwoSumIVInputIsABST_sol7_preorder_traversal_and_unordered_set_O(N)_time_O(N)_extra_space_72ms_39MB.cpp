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
    void preorder(TreeNode* root, int k, unordered_set<int>& vis, bool& found){
        if(root != nullptr && !found){
            if(vis.count(k - root->val)){
                found = true;
            }else{
                vis.insert(root->val);
                preorder(root->left, k, vis, found);
                preorder(root->right, k, vis, found);
            }
        }
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> vis;
        bool found = false;
        preorder(root, k, vis, found);
        return found;
    }
};