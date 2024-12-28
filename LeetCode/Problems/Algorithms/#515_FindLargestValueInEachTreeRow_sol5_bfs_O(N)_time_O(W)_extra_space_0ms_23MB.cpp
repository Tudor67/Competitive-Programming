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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != nullptr){
            q.push(root);
        }

        vector<int> levelMax;
        while(!q.empty()){
            int maximum = q.front()->val;
            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                maximum = max(maximum, node->val);

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            levelMax.push_back(maximum);
        }

        return levelMax;
    }
};