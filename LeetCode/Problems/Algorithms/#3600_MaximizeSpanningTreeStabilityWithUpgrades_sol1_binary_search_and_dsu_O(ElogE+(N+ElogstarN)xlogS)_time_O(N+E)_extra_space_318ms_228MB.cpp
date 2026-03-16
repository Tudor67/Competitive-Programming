class DSU{
private:
    vector<int> parent;
    vector<int> size;

public:
    DSU(const int N){
        parent.resize(N);
        size.resize(N);
        reset();
    }

    void reset(){
        const int N = parent.size();
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
private:
    bool isPossible(const int N, const vector<array<int, 4>>& SORTED_EDGES, int k, const int THRESHOLD, DSU& dsu){
        dsu.reset();

        for(auto& [a, b, strength, must]: SORTED_EDGES){
            if(must == 1){
                if(dsu.find(a) == dsu.find(b) || strength < THRESHOLD){
                    return false;
                }
                dsu.join(a, b);
            }
        }

        for(auto& [a, b, strength, must]: SORTED_EDGES){
            if(must == 0){
                if(dsu.find(a) == dsu.find(b)){
                    continue;
                }

                if(2 * strength < THRESHOLD){
                    return false;
                }else if(strength < THRESHOLD){
                    k -= 1;
                }
                dsu.join(a, b);
            }
        }

        return (k >= 0 && dsu.getSize(0) == N);
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int maxStrength = 0;
        vector<array<int, 4>> sortedEdges;
        sortedEdges.reserve(edges.size());
        for(vector<int>& edge: edges){
            sortedEdges.push_back({edge[0], edge[1], edge[2], edge[3]});
            maxStrength = max(maxStrength, edge[2]);
        }

        sort(sortedEdges.begin(), sortedEdges.end(),
             [](const array<int, 4>& LHS, const array<int, 4>& RHS){
                int lhsStrength = LHS[2];
                int rhsStrength = RHS[2];
                return (lhsStrength > rhsStrength);
             });

        int l = 0;
        int r = 2 * maxStrength;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isPossible(n, sortedEdges, k, mid, dsu)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        if(isPossible(n, sortedEdges, k, r, dsu)){
            return r;
        }
        
        return -1;
    }
};