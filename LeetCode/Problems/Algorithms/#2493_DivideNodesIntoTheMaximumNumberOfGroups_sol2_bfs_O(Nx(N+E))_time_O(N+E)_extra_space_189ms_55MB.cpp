class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;

    void bfs(int srcNode, vector<bool>& vis, vector<int>& ccNodes, const Graph& G){
        queue<int> q;
        q.push(srcNode);
        vis[srcNode] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ccNodes.push_back(node);

            for(int nextNode: G[node]){
                if(!vis[nextNode]){
                    vis[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }
    }

    int computeMaxGroups(int srcNode, const Graph& G){
        const int N = G.size();

        vector<int> minDistance(N, INF);
        queue<int> q;
        minDistance[srcNode] = 0;
        q.push(srcNode);

        int maxGroups = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            maxGroups = minDistance[node] + 1;

            for(int nextNode: G[node]){
                if(minDistance[nextNode] == INF){
                    minDistance[nextNode] = minDistance[node] + 1;
                    q.push(nextNode);
                }else if(abs(minDistance[nextNode] - minDistance[node]) != 1){
                    return -1;
                }
            }
        }

        return maxGroups;
    }

public:
    int magnificentSets(int N, vector<vector<int>>& edges) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0] - 1;
            int b = EDGE[1] - 1;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<vector<int>> cc;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                cc.push_back({});
                bfs(node, vis, cc.back(), G);
            }
        }

        int totalGroups = 0;
        for(int i = 0; i < (int)cc.size(); ++i){
            int ccMaxGroups = 0;
            for(int srcNode: cc[i]){
                int groups = computeMaxGroups(srcNode, G);
                if(groups >= 1){
                    ccMaxGroups = max(ccMaxGroups, groups);
                }else{
                    return -1;
                }
            }
            totalGroups += ccMaxGroups;
        }

        return totalGroups;
    }
};