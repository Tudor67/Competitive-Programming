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
    void dfs(TreeNode* root, vector<int>& voyage, int& idx, vector<int>& flippedNodes, bool& isPossible){
        if(root != NULL && isPossible){
            idx += 1;
            if(root->val == voyage[idx]){
                if(root->left != NULL && root->left->val != voyage[idx + 1]){
                    flippedNodes.push_back(root->val);
                    dfs(root->right, voyage, idx, flippedNodes, isPossible);
                    dfs(root->left, voyage, idx, flippedNodes, isPossible);
                }else{
                    dfs(root->left, voyage, idx, flippedNodes, isPossible);
                    dfs(root->right, voyage, idx, flippedNodes, isPossible);
                }
            }else{
                isPossible = false;
            }
        }
    }
    
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int idx = -1;
        vector<int> flippedNodes;
        bool isPossible = true;
        
        dfs(root, voyage, idx, flippedNodes, isPossible);
        
        if(!isPossible){
            flippedNodes.clear();
            flippedNodes.push_back(-1);
        }
        
        return flippedNodes;
    }
};