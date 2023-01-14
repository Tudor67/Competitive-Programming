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
    bool isSameTree(TreeNode* pRoot, TreeNode* qRoot) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({pRoot, qRoot});

        while(!q.empty()){
            TreeNode* a = q.front().first;
            TreeNode* b = q.front().second;
            q.pop();

            if((a == nullptr && b != nullptr) ||
               (a != nullptr && b == nullptr) ||
               (a != nullptr && b != nullptr && a->val != b->val)){
                return false;
            }

            if(a != nullptr && b != nullptr){
                q.push({a->left, b->left});
                q.push({a->right, b->right});
            }
        }

        return true;
    }
};