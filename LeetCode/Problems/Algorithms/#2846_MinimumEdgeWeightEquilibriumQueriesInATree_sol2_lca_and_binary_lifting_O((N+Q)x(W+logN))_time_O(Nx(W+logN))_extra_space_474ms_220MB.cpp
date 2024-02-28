class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
    const int MAX_WEIGHT = 26;
    
    void dfs(int level, int parent, int node, const Graph& G,
             vector<int>& levelOf, vector<vector<int>>& f, vector<vector<int>>& p){
        levelOf[node] = level;
        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            int edgeWeight = P.second;
            if(nextNode != parent){
                for(int weight = 0; weight <= MAX_WEIGHT; ++weight){
                    f[weight][nextNode] = f[weight][node];
                }
                f[edgeWeight][nextNode] += 1;
                p[0][nextNode] = node;
                dfs(level + 1, node, nextNode, G, levelOf, f, p);
            }
        }
    }

    int getLCA(int a, int b, vector<vector<int>>& p, vector<int>& levelOf){
        if(levelOf[a] > levelOf[b]){
            swap(a, b);
        }

        for(int k = (int)p.size() - 1; k >= 0; --k){
            if(levelOf[a] <= levelOf[b] - (1 << k)){
                b = p[k][b];
            }
        }

        for(int k = (int)p.size() - 1; k >= 0; --k){
            if(p[k][a] != p[k][b]){
                a = p[k][a];
                b = p[k][b];
            }
        }

        if(a != b){
            a = p[0][a];
        }

        return a;
    }
    
public:
    vector<int> minOperationsQueries(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        const int LOG_N = log2(N) + 1;
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            G[a].push_back({b, w});
            G[b].push_back({a, w});
        }
        
        vector<int> levelOf(N);
        vector<vector<int>> f(MAX_WEIGHT + 1, vector<int>(N));
        vector<vector<int>> p(LOG_N + 1, vector<int>(N));
        dfs(1, -1, 0, G, levelOf, f, p);

        for(int k = 1; k <= LOG_N; ++k){
            for(int node = 0; node < N; ++node){
                p[k][node] = p[k - 1][p[k - 1][node]];
            }
        }
        
        const int Q = queries.size();
        vector<int> res(Q);
        
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];
            int lca = getLCA(a, b, p, levelOf);
            
            int maxFreq = 0;
            int edgesCount = 0;
            for(int w = 0; w <= MAX_WEIGHT; ++w){
                int freq = f[w][a] + f[w][b] - 2 * f[w][lca];
                maxFreq = max(maxFreq, freq);
                edgesCount += freq;
            }

            res[i] = edgesCount - maxFreq;
        }
        
        return res;
    }
};