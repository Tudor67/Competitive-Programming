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
    void eulerTour(TreeNode* node, int depth, vector<pair<TreeNode*, int>>& euler){
        euler.push_back({node, depth});
        for(TreeNode* child: {node->left, node->right}){
            if(child != NULL){
                eulerTour(child, depth + 1, euler);
                euler.push_back({node, depth});
            }
        }
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<pair<TreeNode*, int>> euler;
        eulerTour(root, 0, euler);
        
        int maxDepth = 0;
        for(int i = 0; i < euler.size(); ++i){
            maxDepth = max(euler[i].second, maxDepth);
        }
        
        int firstPos = INT_MAX;
        int lastPos = INT_MIN;
        for(int i = 0; i < euler.size(); ++i){
            if(euler[i].second == maxDepth){
                firstPos = min(i, firstPos);
                lastPos = max(i, lastPos);
            }
        }
        
        TreeNode* lca = euler[firstPos].first;
        int minDepth = euler[firstPos].second;
        for(int i = firstPos; i <= lastPos; ++i){
            if(euler[i].second < minDepth){
                minDepth = euler[i].second;
                lca = euler[i].first;
            }
        }
        
        return lca;
    }
};