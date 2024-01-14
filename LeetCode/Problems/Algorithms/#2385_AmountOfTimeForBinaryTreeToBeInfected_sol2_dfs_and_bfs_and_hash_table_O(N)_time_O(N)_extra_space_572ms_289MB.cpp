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
    using Graph = unordered_map<int, vector<int>>;

    void buildGraph(TreeNode* node, Graph& G){
        if(node != nullptr){
            for(TreeNode* nextNode: {node->left, node->right}){
                if(nextNode != nullptr){
                    G[node->val].push_back(nextNode->val);
                    G[nextNode->val].push_back(node->val);
                }
            }
            buildGraph(node->left, G);
            buildGraph(node->right, G);
        }
    }

    int computeMaxDist(Graph& G, int src){
        const int N = G.size();

        int maxDist = 0;
        unordered_map<int, int> dist;
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            maxDist = max(maxDist, dist[node]);

            for(int nextNode: G[node]){
                if(!dist.count(nextNode)){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }

        return maxDist;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        Graph G;
        buildGraph(root, G);

        return computeMaxDist(G, start);
    }
};