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
    vector<bool> distanceLimitedPathsExist(int N, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        const int E = edgeList.size();
        const int Q = queries.size();

        vector<int> pE(E);
        iota(pE.begin(), pE.end(), 0);
        sort(pE.begin(), pE.end(), 
             [&](int lhs, int rhs){
                 return edgeList[lhs][2] < edgeList[rhs][2];
             });

        vector<int> pQ(Q);
        iota(pQ.begin(), pQ.end(), 0);
        sort(pQ.begin(), pQ.end(),
             [&](int lhs, int rhs){
                 return queries[lhs][2] < queries[rhs][2];
             });

        vector<bool> answer(Q);
        DSU dsu(N);
        int i = 0;
        for(int queryIndex: pQ){
            int p = queries[queryIndex][0];
            int q = queries[queryIndex][1];
            int limit = queries[queryIndex][2];

            while(i < E && edgeList[pE[i]][2] < limit){
                int a = edgeList[pE[i]][0];
                int b = edgeList[pE[i]][1];
                dsu.join(a, b);
                i += 1;
            }
            
            answer[queryIndex] = (dsu.find(p) == dsu.find(q));
        }

        return answer;
    }
};