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
    int maxLevelSum(TreeNode* root) {
        pair<int, int> resLevelSum = {1, root->val};

        int level = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sum = 0;
            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            if(sum > resLevelSum.second){
                resLevelSum = {level, sum};
            }

            level += 1;
        }

        return resLevelSum.first;
    }
};