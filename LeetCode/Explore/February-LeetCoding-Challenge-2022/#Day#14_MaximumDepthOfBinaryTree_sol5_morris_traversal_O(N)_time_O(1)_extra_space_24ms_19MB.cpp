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
    int maxDepth(TreeNode* root) {
        int maxDist = 0;
        int curDist = 0;
        TreeNode* cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                cur = cur->right;
            }else{
                TreeNode* pred = cur->left;
                int predDist = 1;
                while(pred->right != NULL && pred->right != cur){
                    pred = pred->right;
                    predDist += 1;
                }
                if(pred->right == NULL){
                    pred->right = cur;
                    cur = cur->left;
                }else{
                    pred->right = NULL;
                    cur = cur->right;
                    curDist -= 1;
                    curDist -= predDist;
                }
            }
            curDist += 1;
            maxDist = max(maxDist, curDist);
        }
        return maxDist;
    }
};