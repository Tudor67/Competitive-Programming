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

        map<int, vector<int>> valueToNodes;
        for(int node = 0; node < N; ++node){
            valueToNodes[vals[node]].push_back(node);
        }

        int res = N;
        DSU dsu(N);
        unordered_map<int, int> count;

        for(const pair<int, vector<int>>& PIV: valueToNodes){
            const vector<int>& NODES = PIV.second;
            for(int node: NODES){
                for(int nextNode: G[node]){
                    if(vals[node] >= vals[nextNode]){
                        dsu.join(node, nextNode);
                    }
                }
            }

            count.clear();
            for(int node: NODES){
                count[dsu.find(node)] += 1;
            }

            for(const pair<int, int>& P: count){
                int c = P.second;
                res += c * (c - 1) / 2;
            }
        }

        return res;
    }
};