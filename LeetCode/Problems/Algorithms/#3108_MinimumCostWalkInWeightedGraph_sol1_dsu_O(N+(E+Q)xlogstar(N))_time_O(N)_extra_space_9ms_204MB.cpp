class DSU{
private:
    vector<int> mask;
    vector<int> size;
    vector<int> parent;

public:
    DSU(const int N, const int FULL_MASK){
        mask.assign(N, FULL_MASK);
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

    void join(int x, int y, int edgeMask){
        int xRoot = find(x);
        int yRoot = find(y);
        mask[xRoot] &= edgeMask;

        if(xRoot == yRoot){
            return;
        }

        if(size[xRoot] > size[yRoot]){
            swap(xRoot, yRoot);
        }
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
        mask[yRoot] &= mask[xRoot];
    }

    int getMask(int x){
        return mask[find(x)];
    }
};

class Solution {
public:
    vector<int> minimumCost(int N, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        const int E = edges.size();
        const int Q = queries.size();
        const int FULL_MASK = (1 << 30) - 1;

        DSU dsu(N, FULL_MASK);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            int w = edge[2];
            dsu.join(a, b, w);
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];

            if(dsu.find(a) == dsu.find(b)){
                res[i] = dsu.getMask(a);
            }else{
                res[i] = -1;
            }
        }

        return res;
    }
};