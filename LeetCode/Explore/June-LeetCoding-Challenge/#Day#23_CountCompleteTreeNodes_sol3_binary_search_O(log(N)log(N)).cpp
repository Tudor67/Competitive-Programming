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
    int max_depth(TreeNode* node){
        if(node == NULL || node->left == NULL){
            return 0;
        }
        return 1 + max_depth(node->left);
    }
    
    bool is_valid(TreeNode* node, const int& REMAINING_LEVELS, const int& PATH){
        if(REMAINING_LEVELS == -1){
            return true;
        }
        if(node != NULL){
            TreeNode* next_node = ((PATH & (1LL << REMAINING_LEVELS)) ? node->right : node->left);
            if(next_node != NULL){
                return is_valid(next_node, REMAINING_LEVELS - 1, PATH);
            }
        }
        return false;
    }
    
public:
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        // O(log(N) * log(N))
        const int MAX_DEPTH = max_depth(root);
        int l = (1LL << MAX_DEPTH);
        int r = (1LL << (MAX_DEPTH + 1)) - 1;
        while(l != r){
            int mid = l + (r - l + 1) / 2;
            if(is_valid(root, MAX_DEPTH - 1, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};