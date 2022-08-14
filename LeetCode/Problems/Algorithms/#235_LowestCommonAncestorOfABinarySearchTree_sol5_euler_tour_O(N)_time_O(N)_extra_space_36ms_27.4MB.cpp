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
    void eulerTour(int level, TreeNode* node, vector<pair<TreeNode*, int>>& eulerNodesAndLevels){
        if(node != nullptr){
            eulerNodesAndLevels.emplace_back(node, level);
            for(TreeNode* child: {node->left, node->right}){
                eulerTour(level + 1, child, eulerNodesAndLevels);
                if(eulerNodesAndLevels.back().first != node){
                    eulerNodesAndLevels.emplace_back(node, level);
                }
            }
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<pair<TreeNode*, int>> eulerNodesAndLevels;
        eulerTour(0, root, eulerNodesAndLevels);
        
        int pFirstPos = -1;
        int qFirstPos = -1;
        for(int i = 0; i < (int)eulerNodesAndLevels.size(); ++i){
            if(pFirstPos == -1 && p == eulerNodesAndLevels[i].first){
                pFirstPos = i;
            }
            if(qFirstPos == -1 && q == eulerNodesAndLevels[i].first){
                qFirstPos = i;
            }
        }
        
        int idxOfMinLevel = min(pFirstPos, qFirstPos);
        for(int i = min(pFirstPos, qFirstPos); i <= max(pFirstPos, qFirstPos); ++i){
            if(eulerNodesAndLevels[i].second < eulerNodesAndLevels[idxOfMinLevel].second){
                idxOfMinLevel = i;
            }
        }
        
        return eulerNodesAndLevels[idxOfMinLevel].first;
    }
};