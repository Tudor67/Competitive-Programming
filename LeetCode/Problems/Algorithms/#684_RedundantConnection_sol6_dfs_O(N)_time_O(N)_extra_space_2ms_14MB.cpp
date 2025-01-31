class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;

    int dfs(int level, int parent, int node, vector<int>& levelOf, vector<int>& edgeIdsStack, const Graph& G){
        levelOf[node] = level;

        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            int edgeIndex = P.second;

            if(nextNode != parent){
                edgeIdsStack.push_back(edgeIndex);
                if(levelOf[nextNode] >= 0){
                    return *max_element(edgeIdsStack.begin() + levelOf[nextNode], edgeIdsStack.end());
                }else{
                    int res = dfs(level + 1, node, nextNode, levelOf, edgeIdsStack, G);
                    if(res >= 0){
                        return res;
                    }
                }
                edgeIdsStack.pop_back();
            }
        }

        return -1;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int E = edges.size();
        const int N = E;

        Graph G(N + 1);
        for(int edgeIndex = 0; edgeIndex < E; ++edgeIndex){
            int a = edges[edgeIndex][0];
            int b = edges[edgeIndex][1];
            G[a].push_back({b, edgeIndex});
            G[b].push_back({a, edgeIndex});
        }

        vector<int> levelOf(N + 1, -1);
        vector<int> edgeIdsStack;
        int indexOfRedundantEdge = dfs(0, -1, 1, levelOf, edgeIdsStack, G);

        return edges[indexOfRedundantEdge];
    }
};