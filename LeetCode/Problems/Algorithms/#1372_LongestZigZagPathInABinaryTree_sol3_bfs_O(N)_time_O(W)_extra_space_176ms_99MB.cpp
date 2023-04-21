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
    int longestZigZag(TreeNode* root) {
        int res = 0;

        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while(!q.empty()){
            TreeNode* node = get<0>(q.front());
            int leftLen = get<1>(q.front());
            int rightLen = get<2>(q.front());
            q.pop();

            res = max(res, max(leftLen, rightLen));

            if(node->left != nullptr){
                q.push({node->left, rightLen + 1, 0});
            }
            if(node->right != nullptr){
                q.push({node->right, 0, leftLen + 1});
            }
        }

        return res;
    }
};