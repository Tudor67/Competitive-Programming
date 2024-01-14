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
    using Graph = vector<vector<int>>;

    void buildGraph(TreeNode* node, Graph& G){
        if(node != nullptr){
            for(TreeNode* nextNode: {node->left, node->right}){
                if(nextNode != nullptr){
                    int maxVal = max(node->val, nextNode->val);
                    G.resize(max((int)G.size(), maxVal + 1));
                    G[node->val].push_back(nextNode->val);
                    G[nextNode->val].push_back(node->val);
                }
            }
            buildGraph(node->left, G);
            buildGraph(node->right, G);
        }
    }

    int computeMaxDist(const Graph& G, int src){
        const int N = G.size();

        vector<int> dist(N, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                if(dist[nextNode] == -1){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }

        return *max_element(dist.begin(), dist.end());
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        Graph G(start + 1);
        buildGraph(root, G);

        return computeMaxDist(G, start);
    }
};