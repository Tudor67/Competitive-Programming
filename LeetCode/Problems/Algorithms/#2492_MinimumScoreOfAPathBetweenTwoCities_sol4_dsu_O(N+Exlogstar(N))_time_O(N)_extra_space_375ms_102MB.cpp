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
    int minScore(int N, vector<vector<int>>& roads) {
        DSU dsu(N + 1);
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            dsu.join(a, b);
        }

        int res = INT_MAX;
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            int distance = ROAD[2];
            if(dsu.find(1) == dsu.find(a)){
                res = min(res, distance);
            }
        }

        return res;
    }
};