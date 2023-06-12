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
    void dfs1(TreeNode* node, int level, vector<int>& sum){
        if(node != nullptr){
            if(level >= (int)sum.size()){
                sum.resize(level + 1);
            }
            sum[level] += node->val;
            dfs1(node->left, level + 1, sum);
            dfs1(node->right, level + 1, sum);
        }
    }
    
    void dfs2(TreeNode* node, int level, vector<int>& sum){
        if(node != nullptr){
            if(node->left != nullptr && node->right != nullptr){
                int x = node->left->val + node->right->val;
                node->left->val = -x;
                node->right->val = -x;
            }else if(node->left != nullptr){
                node->left->val *= -1;
            }else if(node->right != nullptr){
                node->right->val *= -1;
            }
            node->val += sum[level];
            dfs2(node->left, level + 1, sum);
            dfs2(node->right, level + 1, sum);
        }
    }
    
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum;
        dfs1(root, 0, sum);
        dfs2(root, 0, sum);
        root->val = 0;
        return root;
    }
};