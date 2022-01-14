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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        int num = 0;
        int steps = 0;
        TreeNode* cur = root;
        TreeNode* pred = NULL;
        while(cur != NULL){
            if(cur->left == NULL){
                num = 2 * num + cur->val;
                if(cur->right == NULL){
                    sum += num;
                }
                cur = cur->right;
            }else{
                pred = cur->left;
                steps = 1;
                while(pred->right != NULL && pred->right != cur){
                    pred = pred->right;
                    steps += 1;
                }
                if(pred->right == NULL){
                    num = 2 * num + cur->val;
                    pred->right = cur;
                    cur = cur->left;
                }else{
                    pred->right = NULL;
                    if(pred->left == NULL){
                        sum += num;
                    }
                    num >>= steps;
                    cur = cur->right;
                }
            }
        }
        return sum;
    }
};