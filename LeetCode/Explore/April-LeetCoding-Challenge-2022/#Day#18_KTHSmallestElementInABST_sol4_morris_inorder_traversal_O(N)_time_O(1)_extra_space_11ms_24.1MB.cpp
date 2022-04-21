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
private:
    void update(TreeNode* curr, int& k, int& res){
        if(k == 1){
            res = curr->val;
        }
        k -= 1;
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        TreeNode* curr = root;
        TreeNode* pred = NULL;
        while(curr != NULL){
            if(curr->left == NULL){
                update(curr, k, res);
                curr = curr->right;
            }else{
                pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    update(curr, k, res);
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};