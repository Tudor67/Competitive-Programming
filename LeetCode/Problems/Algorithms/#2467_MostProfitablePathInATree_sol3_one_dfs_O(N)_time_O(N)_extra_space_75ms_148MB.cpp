class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 2e9;

    pair<int, int> dfs(int level, int parent, int node, vector<int>& amount, int bob, const Graph& G){
        int aliceSubtreeMaxScore = -INF;
        int bobLevel = (node == bob ? level : -INF);

        for(int nextNode: G[node]){
            if(nextNode != parent){
                auto [aliceSubtreeScore, bobSubtreeLevel] = dfs(level + 1, node, nextNode, amount, bob, G);
                if(bobSubtreeLevel != -INF){
                    bobLevel = bobSubtreeLevel;
                }
                aliceSubtreeMaxScore = max(aliceSubtreeMaxScore, aliceSubtreeScore);
            }
        }

        if(aliceSubtreeMaxScore == -INF){
            aliceSubtreeMaxScore = 0;
        }

        int nodeScore = amount[node];
        if(bobLevel != -INF){
            if(bobLevel % 2 == 1 && level == bobLevel / 2 + 1){
                nodeScore = amount[node] / 2;
            }else if(level > bobLevel / 2){
                nodeScore = 0;
            }
        }

        return {nodeScore + aliceSubtreeMaxScore, bobLevel};
    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        const int E = edges.size();
        const int N = E + 1;

        Graph G(N);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        return dfs(1, -1, 0, amount, bob, G).first;
    }
};