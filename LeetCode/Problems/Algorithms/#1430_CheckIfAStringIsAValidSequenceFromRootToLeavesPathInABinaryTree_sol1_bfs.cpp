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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if(root == NULL){
            return arr.empty();
        }
        
        queue<pair<TreeNode*, int>> q;
        if(!arr.empty() && root->val == arr[0]){
            q.push({root, 0});
        }
        
        bool is_valid = false;
        while(!q.empty() && !is_valid){
            TreeNode* node = q.front().first;
            int idx = q.front().second;
            q.pop();
            
            if(idx == (int)arr.size() - 1){
                is_valid |= (!node->left && !node->right);
            }else{
                if(node->left && node->left->val == arr[idx + 1]){
                    q.push({node->left, idx + 1});
                }
                if(node->right && node->right->val == arr[idx + 1]){
                    q.push({node->right, idx + 1});
                }
            }
        }
        
        return is_valid;
    }
};