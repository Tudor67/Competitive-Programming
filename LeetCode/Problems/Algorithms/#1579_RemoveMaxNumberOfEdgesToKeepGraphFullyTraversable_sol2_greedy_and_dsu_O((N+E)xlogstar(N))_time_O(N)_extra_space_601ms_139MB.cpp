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
public:
    int maxNumEdgesToRemove(int N, vector<vector<int>>& edges) {
        const int E = edges.size();

        int removedEdges = 0;

        DSU dsu1(N + 1);
        DSU dsu2(N + 1);
        for(const vector<int>& EDGE: edges){
            int type = EDGE[0];
            int a = EDGE[1];
            int b = EDGE[2];
            if(type == 3){
                if(dsu1.find(a) == dsu1.find(b)){
                    removedEdges += 1;
                }else{
                    dsu1.join(a, b);
                    dsu2.join(a, b);
                }
            }
        }

        for(const vector<int>& EDGE: edges){
            int type = EDGE[0];
            int a = EDGE[1];
            int b = EDGE[2];
            if(type == 1){
                if(dsu1.find(a) == dsu1.find(b)){
                    removedEdges += 1;
                }else{
                    dsu1.join(a, b);
                }
            }else if(type == 2){
                if(dsu2.find(a) == dsu2.find(b)){
                    removedEdges += 1;
                }else{
                    dsu2.join(a, b);
                }
            }
        }

        bool isTraversable = true;
        for(int node = 1; node <= N; ++node){
            if((dsu1.find(node) != dsu1.find(1)) ||
               (dsu2.find(node) != dsu2.find(1))){
                isTraversable = false;
            }
        }

        if(isTraversable){
            return removedEdges;
        }

        return -1;
    }
};