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
    void eulerTour(TreeNode* node, int level, vector<pair<TreeNode*, int>>& eulerNodeLevel){
        if(node != NULL){
            eulerNodeLevel.emplace_back(node, level);
            for(TreeNode* child: {node->left, node->right}){
                eulerTour(child, level + 1, eulerNodeLevel);
                if(eulerNodeLevel.back().first != node){
                    eulerNodeLevel.emplace_back(node, level);
                }
            }
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<pair<TreeNode*, int>> eulerNodeLevel;
        eulerTour(root, 0, eulerNodeLevel);
        
        int pIdx = -1;
        int qIdx = -1;
        for(int i = 0; i < (int)eulerNodeLevel.size(); ++i){
            TreeNode* node = eulerNodeLevel[i].first;
            if(p == node && pIdx == -1){
                pIdx = i;
            }
            if(q == node && qIdx == -1){
                qIdx = i;
            }
        }
        
        TreeNode* lca = NULL;
        int minLevel = INT_MAX;
        for(int i = min(pIdx, qIdx); i <= max(pIdx, qIdx); ++i){
            TreeNode* node = eulerNodeLevel[i].first;
            int level = eulerNodeLevel[i].second;
            if(level < minLevel){
                minLevel = level;
                lca = node;
            }
        }
        
        return lca;
    }
};