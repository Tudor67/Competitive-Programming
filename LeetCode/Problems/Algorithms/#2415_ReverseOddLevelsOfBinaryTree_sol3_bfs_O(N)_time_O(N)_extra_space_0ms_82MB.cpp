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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int level = 0;
        while(!q.empty()){
            vector<TreeNode*> levelNodes;
            levelNodes.reserve(q.size());

            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                levelNodes.push_back(node);

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            if(level % 2 == 1){
                for(int i = 0, j = (int)levelNodes.size() - 1; i < j; ++i, --j){
                    swap(levelNodes[i]->val, levelNodes[j]->val);
                }
            }

            level += 1;
        }

        return root;
    }
};