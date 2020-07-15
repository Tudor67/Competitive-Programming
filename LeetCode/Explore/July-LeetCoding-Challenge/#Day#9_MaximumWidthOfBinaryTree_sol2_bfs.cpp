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
    int widthOfBinaryTree(TreeNode* root) {
        int max_width = 0;
        
        queue<pair<TreeNode*, int>> q;
        if(root != NULL){
            q.push({root, 1});
        }
        
        while(!q.empty()){
            if(q.size() == 1){
                // use this trick to avoid overflow
                q.front().second = 1;
            }
            
            // min and max pos of the current level
            int min_pos = q.front().second;
            int max_pos = q.front().second;
            
            // check only the nodes from the current level
            for(int nodes_cnt = q.size(); nodes_cnt > 0; --nodes_cnt){
                TreeNode* node = q.front().first;
                int pos = q.front().second;
                q.pop();
                
                // update min and max pos of the current level
                min_pos = min(pos, min_pos);
                max_pos = max(pos, max_pos);
                
                // add nodes for the next level
                if(node->left != NULL){
                    q.push({node->left, 2 * pos});
                }
                if(node->right != NULL){
                    q.push({node->right, 2 * pos + 1});
                }
            }
            
            max_width = max(max_pos - min_pos + 1, max_width);
        }
        
        return max_width;
    }
};