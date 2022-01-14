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
        queue<pair<TreeNode*, int>> q;
        if(root != NULL){
            q.emplace(root, root->val);
        }
        
        int sum = 0;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int num = q.front().second;
            q.pop();
            
            if(node->left == NULL && node->right == NULL){
                sum += num;
            }
            
            for(TreeNode* child: {node->left, node->right}){
                if(child != NULL){
                    q.emplace(child, 2 * num + child->val);
                }
            }
        }
        
        return sum;
    }
};