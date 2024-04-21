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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            return new TreeNode(val, root, nullptr);
        }

        queue<TreeNode*> q;
        q.push(root);

        for(int level = 1; level <= depth - 2; ++level){
            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
        }

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }

        return root;
    }
};