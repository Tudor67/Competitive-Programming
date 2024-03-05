class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;

    int dfs1(int parent, int node, const Graph& G){
        int totalCost = 0;
        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            int cost = P.second;
            if(nextNode != parent){
                totalCost += cost + dfs1(node, nextNode, G);
            }
        }
        return totalCost;
    }

    void dfs2(int parent, int node, const Graph& G, vector<int>& answer){
        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            int cost = P.second;
            if(nextNode != parent){
                answer[nextNode] = answer[node] - cost + (1 - cost);
                dfs2(node, nextNode, G, answer);
            }
        }
    }

public:
    vector<int> minEdgeReversals(int N, vector<vector<int>>& edges) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back({b, 0});
            G[b].push_back({a, 1});
        }

        vector<int> answer(N);
        answer[0] = dfs1(-1, 0, G);

        dfs2(-1, 0, G, answer);

        return answer;
    }
};