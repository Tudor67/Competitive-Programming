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
    void dfs(TreeNode* node, const TreeNode* TARGET_NODE, vector<TreeNode*>& pathFromRootToTarget){
        if(node != NULL){
            for(TreeNode* child: {node->left, node->right}){
                pathFromRootToTarget.push_back(child);
                if(pathFromRootToTarget.back() != TARGET_NODE){
                    dfs(child, TARGET_NODE, pathFromRootToTarget);
                }
                if(pathFromRootToTarget.back() != TARGET_NODE){
                    pathFromRootToTarget.pop_back();
                }
            }
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathFromRootToP = {root};
        vector<TreeNode*> pathFromRootToQ = {root};
        
        dfs(root, p, pathFromRootToP);
        dfs(root, q, pathFromRootToQ);
        
        int lcaIdx = -1;
        while(lcaIdx + 1 < (int)min(pathFromRootToP.size(), pathFromRootToQ.size()) &&
              pathFromRootToP[lcaIdx + 1] == pathFromRootToQ[lcaIdx + 1]){
            lcaIdx += 1;
        }
        
        TreeNode* lca = pathFromRootToP[lcaIdx];
        
        return lca;
    }
};