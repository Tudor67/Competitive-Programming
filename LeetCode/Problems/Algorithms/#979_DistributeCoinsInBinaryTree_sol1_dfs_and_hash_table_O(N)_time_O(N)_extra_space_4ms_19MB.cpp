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
    void postorder(TreeNode* root, unordered_map<TreeNode*, int>& have, unordered_map<TreeNode*, int>& need, int& moves){
        if(root == NULL){
            have[NULL] = 0;
            need[NULL] = 0;
            return;
        }
        
        postorder(root->left, have, need, moves);
        postorder(root->right, have, need, moves);
        
        have[root] = have[root->left] + have[root->right] + root->val;
        need[root] = need[root->left] + need[root->right] + 1;
        
        for(TreeNode* child: {root->left, root->right}){
            if(child != NULL && have[child] > need[child]){
                moves += have[child] - need[child];
                root->val += have[child] - need[child];
            }
        }
    }
    
    void preorder(TreeNode* root, unordered_map<TreeNode*, int>& have, unordered_map<TreeNode*, int>& need, int& moves){
        if(root == NULL){
            return;
        }
        
        for(TreeNode* child: {root->left, root->right}){
            if(child != NULL && have[child] < need[child]){
                moves += need[child] - have[child];
                root->val += need[child] - have[child];
            }
        }
        
        preorder(root->left, have, need, moves);
        preorder(root->right, have, need, moves);
    }
    
public:
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        unordered_map<TreeNode*, int> have;
        unordered_map<TreeNode*, int> need;
        postorder(root, have, need, moves);
        preorder(root, have, need, moves);
        return moves;
    }
};