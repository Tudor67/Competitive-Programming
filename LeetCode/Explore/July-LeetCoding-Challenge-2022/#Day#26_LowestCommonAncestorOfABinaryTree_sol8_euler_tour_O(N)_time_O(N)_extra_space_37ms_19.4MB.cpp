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
    void eulerTour(TreeNode* node, int level, vector<pair<TreeNode*, int>>& eulerNodesAndLevels){
        if(node != NULL){
            eulerNodesAndLevels.emplace_back(node, level);
            for(TreeNode* child: {node->left, node->right}){
                eulerTour(child, level + 1, eulerNodesAndLevels);
                if(eulerNodesAndLevels.back().first != node){
                    eulerNodesAndLevels.emplace_back(node, level);
                }
            }
        }
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<pair<TreeNode*, int>> eulerNodesAndLevels;
        eulerTour(root, 0, eulerNodesAndLevels);
        
        int firstPosOfP = -1;
        int firstPosOfQ = -1;
        for(int i = 0; i < (int)eulerNodesAndLevels.size(); ++i){
            TreeNode* node = eulerNodesAndLevels[i].first;
            int level = eulerNodesAndLevels[i].second;
            if(node == p && firstPosOfP == -1){
                firstPosOfP = i;
            }
            if(node == q && firstPosOfQ == -1){
                firstPosOfQ = i;
            }
        }
        
        int idxOfMinLevel = firstPosOfP;
        for(int i = min(firstPosOfP, firstPosOfQ); i <= max(firstPosOfP, firstPosOfQ); ++i){
            if(eulerNodesAndLevels[i].second < eulerNodesAndLevels[idxOfMinLevel].second){
                idxOfMinLevel = i;
            }
        }
        
        return eulerNodesAndLevels[idxOfMinLevel].first;
    }
};