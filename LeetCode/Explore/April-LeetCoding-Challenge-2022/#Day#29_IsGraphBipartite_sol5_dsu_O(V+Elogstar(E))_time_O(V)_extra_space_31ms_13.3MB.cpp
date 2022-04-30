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
            if(rank[xRoot] < rank[yRoot]){
                parent[xRoot] = yRoot;
            }else if(rank[xRoot] > rank[yRoot]){
                parent[yRoot] = xRoot;
            }else{
                parent[xRoot] = yRoot;
                rank[yRoot] += 1;
            }
        }
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int N = graph.size();
        
        DSU dsu(N);
        for(int node = 0; node < N; ++node){
            for(int j = 1; j < (int)graph[node].size(); ++j){
                dsu.join(graph[node][j - 1], graph[node][j]);
            }
            if(!graph[node].empty()){
                if(dsu.find(node) == dsu.find(graph[node][0])){
                    return false;
                }
            }
        }
        
        return true;
    }
};