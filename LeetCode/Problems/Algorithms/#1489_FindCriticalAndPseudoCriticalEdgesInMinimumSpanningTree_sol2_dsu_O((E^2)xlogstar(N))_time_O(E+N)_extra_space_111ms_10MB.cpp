class DSU{
private:
    vector<int> rank;
    vector<int> parent;

public:
    DSU(const int N){
        rank.resize(N);
        parent.resize(N);
        reset();
    }

    void reset(){
        fill(rank.begin(), rank.end(), 0);
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
    int computeMSTCost(DSU& dsu, vector<vector<int>>& edges, vector<int>& p, int specialEdgeIndex, bool includeSpecialEdge){
        int mstCost = 0;

        dsu.reset();

        if(includeSpecialEdge){
            int a = edges[specialEdgeIndex][0];
            int b = edges[specialEdgeIndex][1];
            int w = edges[specialEdgeIndex][2];
            dsu.join(a, b);
            mstCost += w;
        }

        for(int i: p){
            int a = edges[i][0];
            int b = edges[i][1];
            int w = edges[i][2];
            if(i != specialEdgeIndex){
                if(dsu.find(a) != dsu.find(b)){
                    dsu.join(a, b);
                    mstCost += w;
                }
            }
        }

        return mstCost;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int N, vector<vector<int>>& edges) {
        const int E = edges.size();

        vector<int> p(E);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 int lhsWeight = edges[lhs][2];
                 int rhsWeight = edges[rhs][2];
                 return (lhsWeight < rhsWeight);
             });

        vector<vector<int>> res(2);
        DSU dsu(N);
        int bestMSTCost = computeMSTCost(dsu, edges, p, -1, false);
        for(int edgeIndex = 0; edgeIndex < E; ++edgeIndex){
            if(bestMSTCost != computeMSTCost(dsu, edges, p, edgeIndex, false)){
                res[0].push_back(edgeIndex);
            }else if(bestMSTCost == computeMSTCost(dsu, edges, p, edgeIndex, true)){
                res[1].push_back(edgeIndex);
            }
        }

        return res;
    }
};