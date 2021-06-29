class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
        rank.resize(N + 1, 0);
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
                rank[yRoot] += (rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int N = edges.size();
        DSU dsu(N);
        for(int i = 0; i < N; ++i){
            if(dsu.find(edges[i][0]) == dsu.find(edges[i][1])){
                return edges[i];
            }
            dsu.join(edges[i][0], edges[i][1]);
        }
        return {};
    }
};