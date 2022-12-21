class DSU{
private:
    vector<int> rank;
    vector<int> parent;

public:
    DSU(const int& N){
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
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> G(N + 1);
        for(const vector<int>& D: dislikes){
            int a = D[0];
            int b = D[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        DSU dsu(N + 1);
        for(int node = 1; node <= N; ++node){
            for(int j = 1; j < (int)G[node].size(); ++j){
                dsu.join(G[node][j - 1], G[node][j]);
            }
        }

        for(int node = 1; node <= N; ++node){
            for(int nextNode: G[node]){
                if(dsu.find(node) == dsu.find(nextNode)){
                    return false;
                }
            }
        }

        return true;
    }
};