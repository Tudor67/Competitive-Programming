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
    void dfs(TreeNode* node, TreeNode* parent, unordered_set<TreeNode*>& covered, int& res){
        if(node != NULL){
            dfs(node->left, node, covered, res);
            dfs(node->right, node, covered, res);
            if(!covered.count(node->left) || !covered.count(node->right) || (parent == NULL && !covered.count(node))){
                res += 1;
                covered.insert(parent);
                covered.insert(node);
                covered.insert(node->left);
                covered.insert(node->right);
            }
        }
    }
    
public:
    int minCameraCover(TreeNode* root) {
        unordered_set<TreeNode*> covered;
        covered.insert(NULL);
        int res = 0;
        dfs(root, NULL, covered, res);
        return res;
    }
};