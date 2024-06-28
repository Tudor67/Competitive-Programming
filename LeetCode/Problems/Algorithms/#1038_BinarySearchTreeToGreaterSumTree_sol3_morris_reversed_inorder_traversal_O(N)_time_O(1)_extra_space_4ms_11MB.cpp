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
    void update(TreeNode* node, int& sum){
        sum += node->val;
        node->val = sum;
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;

        TreeNode* node = root;
        while(node != nullptr){
            if(node->right == nullptr){
                update(node, sum);
                node = node->left;
            }else{
                TreeNode* succ = node->right;
                while(succ->left != nullptr && succ->left != node){
                    succ = succ->left;
                }

                if(succ->left == nullptr){
                    succ->left = node;
                    node = node->right;
                }else{
                    succ->left = nullptr;
                    update(node, sum);
                    node = node->left;
                }
            }
        }

        return root;
    }
};