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
    long long countPairs(int N, vector<vector<int>>& edges) {
        DSU dsu(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            dsu.join(a, b);
        }

        vector<int> ccSize(N);
        for(int node = 0; node < N; ++node){
            int root = dsu.find(node);
            ccSize[root] += 1;
        }

        long long res = 0;
        for(int root = 0; root < N; ++root){
            res += ccSize[root] * 1LL * (N - ccSize[root]);
        }

        return res / 2;
    }
};