class DSU{
private:
    vector<int> rank;
    vector<int> parent;
    
public:
    DSU(const int& N){
        rank.resize(N + 1);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
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
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int N = points.size();
        using Edge = tuple<int, int, int>;
        
        vector<Edge> edges;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.emplace_back(dist, i, j);
            }
        }
        
        sort(edges.begin(), edges.end());
        
        DSU dsu(N);
        int minCost = 0;
        int edgesInMST = 0;
        for(const Edge& E: edges){
            int dist = get<0>(E);
            int i = get<1>(E);
            int j = get<2>(E);
            if(dsu.find(i) != dsu.find(j)){
                dsu.join(i, j);
                minCost += dist;
                edgesInMST += 1;
            }
            if(edgesInMST == N - 1){
                break;
            }
        }
        
        return minCost;
    }
};