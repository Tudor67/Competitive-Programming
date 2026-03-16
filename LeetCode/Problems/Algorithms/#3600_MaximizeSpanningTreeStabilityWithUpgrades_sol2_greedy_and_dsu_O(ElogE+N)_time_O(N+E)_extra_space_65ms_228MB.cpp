class DSU{
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(const int N){
        parent.resize(N);
        size.resize(N);
        for(int i = 0; i < N; ++i){
            parent[i] = i;
            size[i] = 1;
        }
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
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        vector<array<int, 4>> sortedEdges;
        sortedEdges.reserve(edges.size());
        for(vector<int>& edge: edges){
            sortedEdges.push_back({edge[0], edge[1], edge[2], edge[3]});
        }

        sort(sortedEdges.begin(), sortedEdges.end(),
             [](const array<int, 4>& LHS, const array<int, 4>& RHS){
                int lhsStrength = LHS[2];
                int rhsStrength = RHS[2];
                return (lhsStrength > rhsStrength);
             });

        DSU dsu(n);
        int usedEdges = 0;
        int maxStability = INT_MAX;
        for(const auto& [a, b, strength, must]: sortedEdges){
            if(must == 1){
                if(dsu.find(a) == dsu.find(b)){
                    return -1;
                }
                dsu.join(a, b);
                usedEdges += 1;
                maxStability = min(maxStability, strength);
            }
        }

        for(const auto& [a, b, strength, must]: sortedEdges){
            if(must == 0){
                if(dsu.find(a) == dsu.find(b)){
                    continue;
                }
                dsu.join(a, b);
                usedEdges += 1;
                if(usedEdges + k > n - 1){
                    maxStability = min(maxStability, 2 * strength);
                }else{
                    maxStability = min(maxStability, strength);
                }
            }
        }

        if(dsu.getSize(0) == n){
            return maxStability;
        }

        return -1;
    }
};