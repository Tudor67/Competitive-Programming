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
                int brothersSum = q.front().second;
                q.pop();

                node->val = levelSum - brothersSum;

                int childrenSum = (node->left == nullptr ? 0 : node->left->val) +
                                  (node->right == nullptr ? 0 : node->right->val);
                if(node->left != nullptr){
                    q.push({node->left, childrenSum});
                }
                if(node->right != nullptr){
                    q.push({node->right, childrenSum});
                }
            }
        }

        return root;
    }
};