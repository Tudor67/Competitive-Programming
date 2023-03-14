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
    bool isSymmetric(TreeNode* root) {
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, root});

        while(!q.empty()){
            TreeNode* root1 = q.front().first;
            TreeNode* root2 = q.front().second;
            q.pop();

            if(root1 == nullptr && root2 == nullptr){
                // ok
            }else if(root1 == nullptr || root2 == nullptr || root1->val != root2->val){
                return false;
            }else{
                q.push({root1->left, root2->right});
                q.push({root1->right, root2->left});
            }
        }

        return true;
    }
};