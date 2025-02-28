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
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> lastNodeAt;
        int val = 0;
        int depth = 0;

        for(int i = 0; i < (int)traversal.length(); ++i){
            if(isdigit(traversal[i])){
                val = val * 10 + (traversal[i] - '0');
            }else{
                depth += 1;
            }

            if(isdigit(traversal[i]) && (i + 1 == (int)traversal.length() || traversal[i + 1] == '-')){
                TreeNode* node = new TreeNode(val);
                if(depth >= 1){
                    if(lastNodeAt[depth - 1]->left == nullptr){
                        lastNodeAt[depth - 1]->left = node;
                    }else{
                        lastNodeAt[depth - 1]->right = node;
                    }
                }
                lastNodeAt.resize(max(depth + 1, (int)lastNodeAt.size()));
                lastNodeAt[depth] = node;
                val = 0;
                depth = 0;
            }
        }

        return lastNodeAt[0];
    }
};