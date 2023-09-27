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
private:
    int computeDistance(const vector<int>& A, const vector<int>& B){
        return abs(A[0] - B[0]) + abs(A[1] - B[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int N = points.size();

        vector<tuple<int, int, int>> sortedEdges;
        sortedEdges.reserve(N * N);
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                sortedEdges.push_back({computeDistance(points[i], points[j]), i, j});
            }
        }

        sort(sortedEdges.begin(), sortedEdges.end());

        DSU dsu(N);
        int mstCost = 0;
        int mstEdgesCount = 0;
        for(int i = 0; i < (int)sortedEdges.size() && mstEdgesCount < N - 1; ++i){
            int cost = get<0>(sortedEdges[i]);
            int a = get<1>(sortedEdges[i]);
            int b = get<2>(sortedEdges[i]);
            if(dsu.find(a) != dsu.find(b)){
                dsu.join(a, b);
                mstCost += cost;
                mstEdgesCount += 1;
            }
        }

        return mstCost;
    }
};