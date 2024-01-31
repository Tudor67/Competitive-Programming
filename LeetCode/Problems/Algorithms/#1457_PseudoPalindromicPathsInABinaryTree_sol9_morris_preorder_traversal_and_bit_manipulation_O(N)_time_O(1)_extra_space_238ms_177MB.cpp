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
    void updateResult(TreeNode* node, int nodeParityMask, int& res){
        if(node != nullptr && node->left == nullptr && node->right == nullptr){
            if(!(nodeParityMask & (nodeParityMask - 1))){
                res += 1;
            }
        }
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;

        TreeNode* curr = root;
        int currParityMask = 0;
        while(curr != nullptr){
            if(curr->left == nullptr){
                currParityMask ^= (1 << curr->val);
                updateResult(curr, currParityMask, res);
                curr = curr->right;
            }else{
                TreeNode* pred = curr->left;
                int deltaParityMask = (1 << pred->val);
                while(pred->right != nullptr && pred->right != curr){
                    deltaParityMask ^= (1 << pred->right->val);
                    pred = pred->right;
                }

                if(pred->right == nullptr){
                    pred->right = curr;
                    currParityMask ^= (1 << curr->val);
                    curr = curr->left;
                }else{
                    pred->right = nullptr;
                    updateResult(pred, currParityMask, res);
                    currParityMask ^= deltaParityMask;
                    curr = curr->right;
                }
            }
        }

        return res;
    }
};