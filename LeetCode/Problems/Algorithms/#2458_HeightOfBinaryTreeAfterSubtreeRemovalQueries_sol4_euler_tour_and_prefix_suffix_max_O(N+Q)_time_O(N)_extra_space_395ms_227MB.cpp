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
    void eulerTour(int level, TreeNode* node, vector<pair<int, int>>& eulerNodeLevel){
        eulerNodeLevel.push_back({node->val, level});
        for(TreeNode* child: {node->left, node->right}){
            if(child != nullptr){
                eulerTour(level + 1, child, eulerNodeLevel);
                eulerNodeLevel.push_back({node->val, level});
            }
        }
    }

public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<pair<int, int>> eulerNodeLevel;
        eulerTour(0, root, eulerNodeLevel);

        const int N = (eulerNodeLevel.size() + 1) / 2;
        const int INF = 1e9;
        vector<int> firstPos(N + 1, INF);
        vector<int> lastPos(N + 1, INF);
        for(int i = 0; i < (int)eulerNodeLevel.size(); ++i){
            int nodeVal = eulerNodeLevel[i].first;
            if(firstPos[nodeVal] == INF){
                firstPos[nodeVal] = i;
            }
            lastPos[nodeVal] = i;
        }

        vector<int> prefMaxLevel(eulerNodeLevel.size());
        prefMaxLevel[0] = eulerNodeLevel[0].second;
        for(int i = 1; i < (int)eulerNodeLevel.size(); ++i){
            prefMaxLevel[i] = max(prefMaxLevel[i - 1], eulerNodeLevel[i].second);
        }

        vector<int> suffMaxLevel(eulerNodeLevel.size());
        suffMaxLevel[(int)eulerNodeLevel.size() - 1] = eulerNodeLevel[(int)eulerNodeLevel.size() - 1].second;
        for(int i = (int)eulerNodeLevel.size() - 2; i >= 0; --i){
            suffMaxLevel[i] = max(eulerNodeLevel[i].second, suffMaxLevel[i + 1]);
        }

        const int Q = queries.size();
        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int nodeVal = queries[i];
            int l = firstPos[nodeVal];
            int r = lastPos[nodeVal];
            if(l - 1 >= 0){
                res[i] = max(res[i], prefMaxLevel[l - 1]);
            }
            if(r + 1 < (int)suffMaxLevel.size()){
                res[i] = max(res[i], suffMaxLevel[r + 1]);
            }
        }

        return res;
    }
};