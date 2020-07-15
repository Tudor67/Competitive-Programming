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
    TreeNode* get_first_node_with_2_children(TreeNode* root){
        TreeNode* start_node = root;
        while(start_node != NULL){
            if(start_node->left != NULL && start_node->right != NULL){
                break;
            }
            if(start_node->left != NULL){
                start_node = start_node->left;
            }else{
                start_node = start_node->right;
            }
        }
        return start_node;
    }

    void dfs(TreeNode* node, int level, long long path_val,
             vector<pair<long long, long long>>& min_max,
             long long& max_width){
        if(node != NULL){
            if(level >= min_max.size()){
                min_max.resize(level + 1);
                min_max[level] = {path_val, path_val};
            }else{
                min_max[level].first = min(path_val, min_max[level].first);
                min_max[level].second = max(path_val, min_max[level].second);
            }
            
            max_width = max(min_max[level].second - min_max[level].first + 1, max_width);
            
            dfs(node->left, level + 1, 2 * path_val, min_max, max_width);
            dfs(node->right, level + 1, 2 * path_val + 1, min_max, max_width);
        }
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        TreeNode* start_node = get_first_node_with_2_children(root);
        
        // path_val: binary representation of the path from the root to the current node
        // path_val = 9 (1001 in binary repr) corresponds to [root->left->left->right]
        long long path_val = 1;
        
        // min_max[level]: min_max of path_val for the current level
        vector<pair<long long, long long>> min_max;
        
        long long max_width = (root != NULL);
        dfs(start_node, 0, path_val, min_max, max_width);
        
        return (int)max_width;
    }
};