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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        const int N = vals.size();
        const int E = edges.size();
        
        map<int, vector<int>> edgeIndicesFor;
        for(int i = 0; i < E; ++i){
            int maxVal = max(vals[edges[i][0]], vals[edges[i][1]]);
            edgeIndicesFor[maxVal].push_back(i);
        }
        
        int res = N;
        int startPos = 0;
        DSU dsu(N);
        unordered_map<int, int> count;
        unordered_set<int> maxValNodes;
        
        for(const pair<int, vector<int>>& MI: edgeIndicesFor){
            int maxVal = MI.first;
            const vector<int>& EDGE_INDICES = MI.second;
            maxValNodes.clear();
            for(int i: EDGE_INDICES){
                int node1 = edges[i][0];
                int node2 = edges[i][1];
                dsu.join(node1, node2);
                if(vals[node1] == maxVal){
                    maxValNodes.insert(node1);
                }
                if(vals[node2] == maxVal){
                    maxValNodes.insert(node2);
                }
            }

            count.clear();
            for(int node: maxValNodes){
                count[dsu.find(node)] += 1;
            }

            for(const pair<int, int>& P: count){
                int c = P.second;
                res += (c - 1) * c / 2;
            }
        }
        
        return res;
    }
};