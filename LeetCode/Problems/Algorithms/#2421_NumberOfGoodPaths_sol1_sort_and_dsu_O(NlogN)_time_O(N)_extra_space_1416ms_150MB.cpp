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
        
        vector<pair<int, int>> sortedEdges(E);
        for(int i = 0; i < E; ++i){
            sortedEdges[i] = {edges[i][0], edges[i][1]};
        }
        
        sort(sortedEdges.begin(), sortedEdges.end(),
             [&](const pair<int, int>& LHS, const pair<int, int>& RHS){
                 int lhsMaxVal = max(vals[LHS.first], vals[LHS.second]);
                 int rhsMaxVal = max(vals[RHS.first], vals[RHS.second]);
                 return (lhsMaxVal < rhsMaxVal);
             });
        
        int res = N;
        int startPos = 0;
        DSU dsu(N);
        unordered_map<int, int> count;
        unordered_set<int> maxValNodes;
        
        for(int endPos = 0; endPos < E; ++endPos){
            if(endPos == E - 1 ||
               max(vals[sortedEdges[startPos].first], vals[sortedEdges[startPos].second]) <
               max(vals[sortedEdges[endPos + 1].first], vals[sortedEdges[endPos + 1].second])){
                // same maxVal in sortedEdges[startPos .. endPos]
                maxValNodes.clear();
                int maxVal = max(vals[sortedEdges[startPos].first], vals[sortedEdges[startPos].second]);
                for(int i = startPos; i <= endPos; ++i){
                    int node1 = sortedEdges[i].first;
                    int node2 = sortedEdges[i].second;
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
                
                startPos = endPos + 1;
            }
        }
        
        return res;
    }
};