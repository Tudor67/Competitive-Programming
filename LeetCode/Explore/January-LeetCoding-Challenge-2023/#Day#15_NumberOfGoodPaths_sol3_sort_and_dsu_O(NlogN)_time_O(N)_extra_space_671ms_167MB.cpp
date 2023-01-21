class DSU{
private:
    vector<int> parent;

public:
    DSU(const int& N){
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
        parent[xRoot] = yRoot;
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        const int N = vals.size();

        vector<vector<int>> G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return vals[lhs] < vals[rhs];
            });
        
        int res = N;
        DSU dsu(N);
        unordered_map<int, int> count;

        for(int i = 0; i < N; ++i){
            int node = p[i];
            for(int nextNode: G[node]){
                if(vals[node] >= vals[nextNode]){
                    dsu.join(node, nextNode);
                }
            }

            if(i == N - 1 || vals[p[i]] != vals[p[i + 1]]){
                count.clear();
                for(int j = i; j >= 0 && vals[p[j]] == vals[p[i]]; --j){
                    count[dsu.find(p[j])] += 1;
                }

                for(const pair<int, int>& P: count){
                    int c = P.second;
                    res += c * (c - 1) / 2;
                }
            }
        }

        return res;
    }
};