class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int parent, int node, const Graph& G, vector<int>& cost,
             vector<vector<int>>& min2, vector<vector<int>>& max3, vector<long long>& coins){
        min2[node].push_back(cost[node]);
        max3[node].push_back(cost[node]);

        for(int nextNode: G[node]){
            if(nextNode != parent){
                dfs(node, nextNode, G, cost, min2, max3, coins);

                copy(min2[nextNode].begin(), min2[nextNode].end(), back_inserter(min2[node]));
                copy(max3[nextNode].begin(), max3[nextNode].end(), back_inserter(max3[node]));
                sort(min2[node].begin(), min2[node].end());
                sort(max3[node].begin(), max3[node].end());
                min2[node].resize(min((int)min2[node].size(), 2));
                if((int)max3[node].size() > 3){
                    max3[node].erase(max3[node].begin(), max3[node].end() - 3);
                }
            }
        }

        if((int)max3[node].size() < 3){
            coins[node] = 1;
        }else{
            coins[node] = max({(long long)max3[node][0] * (long long)max3[node][1] * (long long)max3[node][2],
                               (long long)min2[node][0] * (long long)min2[node][1] * (long long)max3[node][2],
                               (long long)0});
        }
    }

public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        const int E = edges.size();
        const int N = E + 1;

        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<vector<int>> min2(N);
        vector<vector<int>> max3(N);
        vector<long long> coins(N);
        dfs(-1, 0, G, cost, min2, max3, coins);

        return coins;
    }
};