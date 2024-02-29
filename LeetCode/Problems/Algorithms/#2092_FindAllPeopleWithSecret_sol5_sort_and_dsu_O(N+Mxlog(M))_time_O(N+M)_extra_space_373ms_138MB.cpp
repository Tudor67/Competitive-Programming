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

    void reset(int x){
        rank[x] = 0;
        parent[x] = x;
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
    vector<int> findAllPeople(int N, vector<vector<int>>& meetings, int firstPerson) {
        const int M = meetings.size();

        vector<int> p(M);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return (meetings[lhs][2] < meetings[rhs][2]);
             });
        
        DSU dsu(N);
        dsu.join(0, firstPerson);

        int startPos = 0;
        while(startPos < M){
            int endPos = startPos;
            while(endPos < M && meetings[p[startPos]][2] == meetings[p[endPos]][2]){
                endPos += 1;
            }

            for(int i = startPos; i < endPos; ++i){
                int a = meetings[p[i]][0];
                int b = meetings[p[i]][1];
                dsu.join(a, b);
            }

            for(int i = startPos; i < endPos; ++i){
                int a = meetings[p[i]][0];
                int b = meetings[p[i]][1];
                if(dsu.find(0) != dsu.find(a)){
                    dsu.reset(a);
                    dsu.reset(b);
                }
            }

            startPos = endPos;
        }

        vector<int> res;
        for(int person = 0; person < N; ++person){
            if(dsu.find(0) == dsu.find(person)){
                res.push_back(person);
            }
        }

        return res;
    }
};