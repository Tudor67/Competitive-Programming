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
    void dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& pathFromRootToTarget){
        if(node != nullptr){
            if(pathFromRootToTarget.empty() || pathFromRootToTarget.back() != target){
                pathFromRootToTarget.push_back(node);
            }
            dfs(node->left, target, pathFromRootToTarget);
            dfs(node->right, target, pathFromRootToTarget);
            if(pathFromRootToTarget.back() != target){
                pathFromRootToTarget.pop_back();
            }
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathFromRootToP;
        dfs(root, p, pathFromRootToP);
        
        vector<TreeNode*> pathFromRootToQ;
        dfs(root, q, pathFromRootToQ);
        
        const int M = min(pathFromRootToP.size(), pathFromRootToQ.size());
        for(int i = 0; i < M; ++i){
            if(pathFromRootToP[i] != pathFromRootToQ[i]){
                return pathFromRootToP[i - 1];
            }
        }
        
        return pathFromRootToP[M - 1];
    }
};