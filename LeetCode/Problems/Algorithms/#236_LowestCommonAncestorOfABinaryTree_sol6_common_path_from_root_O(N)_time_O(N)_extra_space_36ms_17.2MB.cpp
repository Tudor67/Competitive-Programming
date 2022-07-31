/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& st, vector<TreeNode*>& pathToTarget){
        if(node != NULL){
            st.push_back(node);
            if(node == target){
                pathToTarget = st;
            }
            dfs(node->left, target, st, pathToTarget);
            dfs(node->right, target, st, pathToTarget);
            st.pop_back();
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> st;
        
        vector<TreeNode*> pathToP;
        dfs(root, p, st, pathToP);
        
        vector<TreeNode*> pathToQ;
        dfs(root, q, st, pathToQ);
        
        const int M = min(pathToP.size(), pathToQ.size());
        for(int i = 0; i < M; ++i){
            if(i == M - 1 || pathToP[i + 1] != pathToQ[i + 1]){
                return pathToP[i];
            }
        }
        
        return NULL;
    }
};