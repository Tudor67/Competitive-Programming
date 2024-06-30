class DSU{
private:
    vector<int> size;
    vector<int> parent;

public:
    DSU(const int N){
        size.assign(N, 1);
        parent.assign(N, 0);
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
        if(xRoot == yRoot){
            return;
        }
        if(size[xRoot] > size[yRoot]){
            swap(xRoot, yRoot);
        }
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
    }

    int getSize(int x){
        return size[find(x)];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int N, vector<vector<int>>& edges) {
        const int E = edges.size();

        int removedEdges = 0;
        DSU aliceDSU(N + 1);
        DSU bobDSU(N + 1);

        for(const vector<int>& EDGE: edges){
            int edgeType = EDGE[0];
            int u = EDGE[1];
            int v = EDGE[2];
            if(edgeType == 3){
                if(aliceDSU.find(u) == aliceDSU.find(v) && bobDSU.find(u) == bobDSU.find(v)){
                    removedEdges += 1;
                }else{
                    aliceDSU.join(u, v);
                    bobDSU.join(u, v);
                }
            }
        }

        for(const vector<int>& EDGE: edges){
            int edgeType = EDGE[0];
            int u = EDGE[1];
            int v = EDGE[2];
            if(edgeType == 1){
                if(aliceDSU.find(u) == aliceDSU.find(v)){
                    removedEdges += 1;
                }else{
                    aliceDSU.join(u, v);
                }
            }else if(edgeType == 2){
                if(bobDSU.find(u) == bobDSU.find(v)){
                    removedEdges += 1;
                }else{
                    bobDSU.join(u, v);
                }
            }
        }

        if(aliceDSU.getSize(1) == N && bobDSU.getSize(1) == N){
            return removedEdges;
        }

        return -1;
    }
};