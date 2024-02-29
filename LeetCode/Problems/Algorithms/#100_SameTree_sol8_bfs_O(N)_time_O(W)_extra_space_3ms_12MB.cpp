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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> bfsQ;
        bfsQ.push({p, q});

        while(!bfsQ.empty()){
            TreeNode* a = bfsQ.front().first;
            TreeNode* b = bfsQ.front().second;
            bfsQ.pop();

            if(a == nullptr && b == nullptr){
                // ok
            }else if(a == nullptr || b == nullptr || a->val != b->val){
                return false;
            }else{
                bfsQ.push({a->left, b->left});
                bfsQ.push({a->right, b->right});
            }
        }

        return true;
    }
};