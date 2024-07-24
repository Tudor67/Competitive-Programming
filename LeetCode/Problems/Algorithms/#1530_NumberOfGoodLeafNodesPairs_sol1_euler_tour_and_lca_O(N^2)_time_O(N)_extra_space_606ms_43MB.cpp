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
    void eulerTour(int level, TreeNode* node, vector<pair<int, TreeNode*>>& eulerLevelNodes){
        eulerLevelNodes.push_back({level, node});
        for(TreeNode* child: {node->left, node->right}){
            if(child != nullptr){
                eulerTour(level + 1, child, eulerLevelNodes);
                eulerLevelNodes.push_back({level, node});
            }
        }
    }

public:
    int countPairs(TreeNode* root, int distance) {
        vector<pair<int, TreeNode*>> eulerLevelNodes;
        eulerTour(0, root, eulerLevelNodes);

        const int E = eulerLevelNodes.size();
        unordered_map<TreeNode*, int> firstIndex;
        unordered_map<TreeNode*, int> lastIndex;
        for(int i = 0; i < E; ++i){
            TreeNode* node = eulerLevelNodes[i].second;
            if(!firstIndex.count(node)){
                firstIndex[node] = i;
            }
            lastIndex[node] = i;
        }

        int goodPairs = 0;
        for(int i = 0; i < E; ++i){
            int aLevel = eulerLevelNodes[i].first;
            TreeNode* a = eulerLevelNodes[i].second;

            if(firstIndex[a] == lastIndex[a]){
                pair<int, TreeNode*> levelLCA = eulerLevelNodes[i];
                for(int j = i + 1; j < E; ++j){
                    int bLevel = eulerLevelNodes[j].first;
                    TreeNode* b = eulerLevelNodes[j].second;

                    levelLCA = min(levelLCA, eulerLevelNodes[j]);

                    if(firstIndex[b] == lastIndex[b]){
                        int currentDistance = aLevel + bLevel - 2 * levelLCA.first;
                        goodPairs += (int)(currentDistance <= distance);
                    }
                }
            }
        }

        return goodPairs;
    }
};