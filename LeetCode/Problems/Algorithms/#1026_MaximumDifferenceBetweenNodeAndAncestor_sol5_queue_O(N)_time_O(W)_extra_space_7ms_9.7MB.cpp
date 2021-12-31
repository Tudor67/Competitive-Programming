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
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;
        
        queue<tuple<TreeNode*, int, int>> q;
        q.emplace(root, root->val, root->val);
        
        while(!q.empty()){
            TreeNode* node = get<0>(q.front());
            int minVal = get<1>(q.front());
            int maxVal = get<2>(q.front());
            q.pop();
            
            maxDiff = max(maxDiff, maxVal - minVal);
            
            for(TreeNode* child: {node->left, node->right}){
                if(child != NULL){
                    q.emplace(child, min(minVal, child->val), max(maxVal, child->val));
                }
            }
        }
        
        return maxDiff;
    }
};