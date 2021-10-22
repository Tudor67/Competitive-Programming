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
    bool isCousins(TreeNode* root, int x, int y) {
        int xParent = -1, xDepth = -1;
        int yParent = -1, yDepth = -1;
        
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, -1, 0});
        while(!q.empty() && (xDepth == -1 || yDepth == -1)){
            TreeNode* node;
            int nodeParent;
            int nodeDepth;
            
            tie(node, nodeParent, nodeDepth) = q.front();
            q.pop();
            
            if(node->val == x){
                xParent = nodeParent;
                xDepth = nodeDepth;
            }else if(node->val == y){
                yParent = nodeParent;
                yDepth = nodeDepth;
            }
            
            if(node->left != NULL){
                q.push({node->left, node->val, nodeDepth + 1});
            }
            if(node->right != NULL){
                q.push({node->right, node->val, nodeDepth + 1});
            }
        }
        
        return (xParent != yParent && xDepth == yDepth);
    }
};