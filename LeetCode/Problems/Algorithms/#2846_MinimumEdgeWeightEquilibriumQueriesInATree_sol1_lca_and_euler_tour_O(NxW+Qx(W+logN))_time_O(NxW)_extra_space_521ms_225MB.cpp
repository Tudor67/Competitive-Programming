class SegmentTree{
private:
    const int N;
    vector<pair<int, int>> tree;
    
    void build(int node, int l, int r, const vector<pair<int, int>>& V){
        if(l == r){
            tree[node] = V[r];
        }else{
            int mid = (l + r) / 2;
            build(2 * node + 1, l, mid, V);
            build(2 * node + 2, mid + 1, r, V);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    pair<int, int> getMin(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            return {INT_MAX, INT_MAX};
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(getMin(2 * node + 1, l, mid, L, R),
                   getMin(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const vector<pair<int, int>>& V): N(V.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, pair<int, int>{INT_MAX, INT_MAX});
        build(0, 0, N - 1, V);
    }
    
    pair<int, int> getMin(const int L, const int R){
        if(L > R){
            return {INT_MAX, INT_MAX};
        }
        return getMin(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
    const int MAX_WEIGHT = 26;
    
    void dfs(int parent, int node, const Graph& G, vector<vector<int>>& f){
        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            int edgeWeight = P.second;
            if(nextNode != parent){
                for(int weight = 0; weight <= MAX_WEIGHT; ++weight){
                    f[weight][nextNode] = f[weight][node];
                }
                f[edgeWeight][nextNode] += 1;
                dfs(node, nextNode, G, f);
            }
        }
    }
    
    void eulerTour(int level, int parent, int node, const Graph& G, vector<pair<int, int>>& eulerLevelsNodes){
        eulerLevelsNodes.push_back({level, node});
        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            if(nextNode != parent){
                eulerTour(level + 1, node, nextNode, G, eulerLevelsNodes);
                eulerLevelsNodes.push_back({level, node});
            }
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
        
        vector<vector<int>> f(MAX_WEIGHT + 1, vector<int>(N));
        dfs(-1, 0, G, f);

        vector<pair<int, int>> eulerLevelsNodes;
        eulerTour(0, -1, 0, G, eulerLevelsNodes);

        vector<int> firstPos(N, -1);
        for(int i = (int)eulerLevelsNodes.size() - 1; i >= 0; --i){
            int node = eulerLevelsNodes[i].second;
            firstPos[node] = i;
        }
        
        SegmentTree tree(eulerLevelsNodes);
        
        const int Q = queries.size();
        vector<int> res(Q);
        
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];
            
            int firstIndex = min(firstPos[a], firstPos[b]);
            int lastIndex = max(firstPos[a], firstPos[b]);
            int lca = tree.getMin(firstIndex, lastIndex).second;
            
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