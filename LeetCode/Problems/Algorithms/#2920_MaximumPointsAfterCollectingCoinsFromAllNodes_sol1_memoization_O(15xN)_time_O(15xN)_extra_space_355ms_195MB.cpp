class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9 + 21;
    const int MAX_OPS2 = 14;

    int computeMaxPoints(int parent, int node, int ops2, const Graph& G,
                         vector<int>& coins, int k, vector<vector<int>>& memo){
        if(memo[ops2][node] != INF){
            return memo[ops2][node];
        }

        int maxPoints1 = (coins[node] >> ops2) - k;
        int maxPoints2 = (coins[node] >> (ops2 + 1));
        for(int nextNode: G[node]){
            if(nextNode != parent){
                maxPoints1 += computeMaxPoints(node, nextNode, ops2, G, coins, k, memo);
                maxPoints2 += computeMaxPoints(node, nextNode, min(ops2 + 1, MAX_OPS2), G, coins, k, memo);
            }
        }

        memo[ops2][node] = max(maxPoints1, maxPoints2);
        return memo[ops2][node];
    }

public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        const int N = edges.size() + 1;

        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<vector<int>> memo(MAX_OPS2 + 1, vector<int>(N, INF));
        return computeMaxPoints(-1, 0, 0, G, coins, k, memo);
    }
};