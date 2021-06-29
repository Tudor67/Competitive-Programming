class Solution {
private:
    using Graph = vector<vector<pair<int, int>>>;
    
    void dfs(int node, const Graph& G, vector<bool>& vis, vector<pair<int, int>>& st, int& redundantEdgeIdx){
        if(redundantEdgeIdx >= 0){
            return;
        }
        vis[node] = true;
        int prevNode = st[(int)st.size() - 2].first;
        for(const pair<int, int>& P: G[node]){
            int nextNode = P.first;
            int edgeIdx = P.second;
            if(vis[nextNode]){
                if(nextNode != prevNode && redundantEdgeIdx < 0){
                    redundantEdgeIdx = edgeIdx;
                    for(int i = (int)st.size() - 1; i >= 1 && st[i].first != nextNode; --i){
                        redundantEdgeIdx = max(st[i].second, redundantEdgeIdx);
                    }
                }
            }else{
                st.emplace_back(nextNode, edgeIdx);
                dfs(nextNode, G, vis, st, redundantEdgeIdx);
                st.pop_back();
            }
        }
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        const int N = edges.size();
        
        Graph g(N + 1);
        for(int i = 0; i < N; ++i){
            int x = edges[i][0];
            int y = edges[i][1];
            g[x].emplace_back(y, i);
            g[y].emplace_back(x, i);
        }
        
        vector<bool> vis(N + 1, false);
        vector<pair<int, int>> st = {{-1, -1}, {1, -1}};
        int redundantEdgeIdx = -1;
        dfs(1, g, vis, st, redundantEdgeIdx);
        
        return edges[redundantEdgeIdx];
    }
};