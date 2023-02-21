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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        queue<TreeNode*> q;
        if(root != nullptr){
            q.push(root);
        }

        while(!q.empty()){
            res.push_back({});
            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                res.back().push_back(node->val);

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
        }

        for(int level = 1; level < (int)res.size(); level += 2){
            reverse(res[level].begin(), res[level].end());
        }

        return res;
    }
};