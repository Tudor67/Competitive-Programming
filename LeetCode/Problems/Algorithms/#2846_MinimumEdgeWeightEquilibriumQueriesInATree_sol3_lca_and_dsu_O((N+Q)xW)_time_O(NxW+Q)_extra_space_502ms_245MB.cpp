class DSU{
private:
    vector<int> rank;
    vector<int> parent;

public:
    DSU(const int N){
        rank.resize(N);
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
    const int MAX_WEIGHT = 26;
    
    void dfs(int parent, int node, const Graph& G, vector<vector<int>>& f, vector<bool>& vis,
             DSU& dsu, vector<int>& ancestor, vector<vector<pair<int, int>>>& queriesFor, vector<int>& res){
        vis[node] = true;
        ancestor[node] = node;

        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            int edgeWeight = P.second;

            if(nextNode != parent){
                for(int weight = 0; weight <= MAX_WEIGHT; ++weight){
                    f[weight][nextNode] = f[weight][node];
                }
                f[edgeWeight][nextNode] += 1;
                
                dfs(node, nextNode, G, f, vis, dsu, ancestor, queriesFor, res);

                dsu.join(node, nextNode);
                ancestor[dsu.find(node)] = node;
            }
        }

        int a = node;
        for(const pair<int, int>& P: queriesFor[a]){
            int b = P.first;
            int queryIndex = P.second;

            if(!vis[b]){
                continue;
            }

            int lca = ancestor[dsu.find(b)];

            int edgesCount = 0;
            int maxFreq = 0;
            for(int w = 0; w <= MAX_WEIGHT; ++w){
                int freq = f[w][a] + f[w][b] - 2 * f[w][lca];
                maxFreq = max(maxFreq, freq);
                edgesCount += freq;
            }

            res[queryIndex] = edgesCount - maxFreq;
        }
    }
    
public:
    vector<int> minOperationsQueries(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            int w = EDGE[2];
            G[a].push_back({b, w});
            G[b].push_back({a, w});
        }

        const int Q = queries.size();
        vector<vector<pair<int, int>>> queriesFor(N);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];
            queriesFor[a].push_back({b, i});
            queriesFor[b].push_back({a, i});
        }
        
        vector<vector<int>> f(MAX_WEIGHT + 1, vector<int>(N));
        vector<bool> vis(N, false);
        DSU dsu(N);
        vector<int> ancestor(N);
        vector<int> res(Q);
        dfs(-1, 0, G, f, vis, dsu, ancestor, queriesFor, res);

        return res;
    }
};