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
    string binary_representation(int num){
        string s;
        if(num == 0){
            s = "0";
        }else{
            while(num > 0){
                s.push_back(char('0' + num % 2));
                num /= 2;
            }
            reverse(s.begin(), s.end());
        }
        return s;
    }
    
    int max_depth(TreeNode* node){
        if(node == NULL || node->left == NULL){
            return 0;
        }
        return 1 + max_depth(node->left);
    }
    
    bool is_valid(TreeNode* node, int level, const string& DIRECTION){
        if(level == (int)DIRECTION.length() - 1){
            return true;
        }
        if(node != NULL){
            TreeNode* next_node = (DIRECTION[level + 1] == '0' ? node->left : node->right);
            if(next_node != NULL){
                return is_valid(next_node, level + 1, DIRECTION);
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
            string direction = binary_representation(mid);
            if(is_valid(root, 0, direction)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};