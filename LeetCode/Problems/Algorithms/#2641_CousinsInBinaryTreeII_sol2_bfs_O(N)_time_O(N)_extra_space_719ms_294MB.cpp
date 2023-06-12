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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while(!q.empty()){
            int levelSum = 0;
            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front().first;
                q.push(q.front());
                q.pop();

                levelSum += node->val;
            }

            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front().first;
                int extraSum = q.front().second;
                q.pop();

                node->val = levelSum - extraSum;

                if(node->left != nullptr && node->right != nullptr){
                    int x = node->left->val + node->right->val;
                    q.push({node->left, x});
                    q.push({node->right, x});
                }else if(node->left != nullptr){
                    q.push({node->left, node->left->val});
                }else if(node->right != nullptr){
                    q.push({node->right, node->right->val});
                }
            }
        }

        return root;
    }
};