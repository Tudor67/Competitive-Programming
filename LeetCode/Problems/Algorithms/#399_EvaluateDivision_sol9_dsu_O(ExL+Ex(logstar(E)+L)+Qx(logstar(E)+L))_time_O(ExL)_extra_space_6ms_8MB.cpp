class DSU{
private:
    vector<int> rank;
    vector<double> cost;
    vector<int> parent;

public:
    DSU(const int N){
        rank.resize(N, 0);
        cost.resize(N, 1.0);
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
    }

    double getCost(int x){
        find(x); // to update cost[x]
        return cost[x];
    }

    int find(int x){
        if(parent[x] != x){
            int y = parent[x];
            parent[x] = find(parent[x]);
            cost[x] *= cost[y];
        }
        return parent[x];
    }

    void join(int x, int y, double w){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot != yRoot){
            if(rank[xRoot] <= rank[yRoot]){
                parent[xRoot] = yRoot;
                cost[xRoot] = w * (cost[y] / cost[x]);
                rank[yRoot] += (int)(rank[xRoot] == rank[yRoot]);
            }else{
                parent[yRoot] = xRoot;
                cost[yRoot] = (cost[x] / cost[y]) / w;
            }
        }
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        const int E = equations.size();
        const int Q = queries.size();

        unordered_map<string, int> strToNode;
        for(int i = 0; i < E; ++i){
            for(string s: {equations[i][0], equations[i][1]}){
                if(!strToNode.count(s)){
                    int node = 1 + strToNode.size();
                    strToNode[s] = node;
                }
            }
        }

        const int N = strToNode.size();
        DSU dsu(N + 1);
        for(int i = 0; i < E; ++i){
            int a = strToNode[equations[i][0]];
            int b = strToNode[equations[i][1]];
            double w = values[i];
            dsu.join(a, b, w);
        }

        vector<double> res(Q);
        for(int i = 0; i < Q; ++i){
            int c = strToNode[queries[i][0]];
            int d = strToNode[queries[i][1]];
            if(c != 0 && d != 0 && dsu.find(c) == dsu.find(d)){
                res[i] = dsu.getCost(c) / dsu.getCost(d);
            }else{
                res[i] = -1;
            }
        }

        return res;
    }
};