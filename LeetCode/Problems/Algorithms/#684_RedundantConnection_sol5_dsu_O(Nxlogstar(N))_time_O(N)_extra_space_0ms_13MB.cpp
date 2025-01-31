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

    bool join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot == yRoot){
            return false;
        }
        if(size[xRoot] > size[yRoot]){
            swap(xRoot, yRoot);
        }
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int E = edges.size();
        const int N = E;

        DSU dsu(N + 1);
        for(const vector<int>& EDGE: edges){
            if(!dsu.join(EDGE[0], EDGE[1])){
                return EDGE;
            }
        }

        return {};
    }
};