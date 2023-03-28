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
    int makeConnected(int N, vector<vector<int>>& connections) {
        const int E = connections.size();

        if(N - 1 > E){
            return -1;
        }

        DSU dsu(N);
        for(const vector<int>& CONNECTION: connections){
            int a = CONNECTION[0];
            int b = CONNECTION[1];
            dsu.join(a, b);
        }

        vector<bool> visRoot(N, false);
        for(int node = 0; node < N; ++node){
            visRoot[dsu.find(node)] = true;
        }

        int connectedComponents = count(visRoot.begin(), visRoot.end(), true);
        return connectedComponents - 1;
    }
};