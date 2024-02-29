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
    bool isEvenOddTree(TreeNode* root) {
        const int INF = 1e9;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while(!q.empty()){
            int prevVal = INF;
            for(int i = (int)q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }

                if((node->val % 2 == level % 2) ||
                   (level % 2 == 0 && prevVal >= node->val && prevVal != INF) ||
                   (level % 2 == 1 && prevVal <= node->val && prevVal != INF)){
                    return false;
                }

                prevVal = node->val;
            }

            level += 1;
        }
        
        return true;
    }
};