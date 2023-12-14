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
    void preorder(TreeNode* root, string& str){
        if(root != nullptr){
            str += to_string(root->val);

            if(root->left != nullptr || root->right != nullptr){
                str += "(";
                preorder(root->left, str);
                str += ")";
            }
            if(root->right != nullptr){
                str += "(";
                preorder(root->right, str);
                str += ")";
            }
        }
    }

public:
    string tree2str(TreeNode* root) {
        string str;
        preorder(root, str);
        return str;
    }
};