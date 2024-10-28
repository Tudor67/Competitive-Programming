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
        queue<TreeNode*> q;
        q.push(root);

        vector<int> sums;
        while(!q.empty()){
            sums.push_back(0);
            for(int i = (int)q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                sums.back() += node->val;

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
        }
        
        q.push(root);
        root->val = 0;
        int level = -1;
        while(!q.empty()){
            level += 1;
            for(int i = (int)q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                int childrenSum = 0;
                if(node->left != nullptr){
                    childrenSum += node->left->val;
                }
                if(node->right != nullptr){
                    childrenSum += node->right->val;
                }

                if(node->left != nullptr){
                    node->left->val = sums[level + 1] - childrenSum;
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    node->right->val = sums[level + 1] - childrenSum;
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};