class Solution {
private:
    using Graph = vector<vector<int>>;
    const int INF = 1e9;
    
    void bfs(int src, int dest, const Graph& G, vector<int>& dist){
        fill(dist.begin(), dist.end(), INF);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while(!q.empty() && dist[dest] == INF){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                if(dist[node] + 1 < dist[nextNode]){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }
    }
    
    void dfs(int parent, int node, const Graph& G, vector<int>& price, vector<int>& coef, vector<vector<int>>& dp){
        int childrenTotalMinSum = 0;
        int childrenTotalSum0 = 0;
        
        for(int nextNode: G[node]){
            if(nextNode != parent){
                dfs(node, nextNode, G, price, coef, dp);
                childrenTotalMinSum += min(dp[0][nextNode], dp[1][nextNode]);
                childrenTotalSum0 += dp[0][nextNode];
            }
        }
        
        dp[0][node] = coef[node] * price[node] + childrenTotalMinSum;
        dp[1][node] = coef[node] * (price[node] / 2) + childrenTotalSum0;
    }
    
public:
    int minimumTotalPrice(int N, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        Graph G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }
        
        vector<int> coef(N);
        vector<int> distFromSrc(N);
        vector<int> distFromDest(N);
        for(const vector<int>& TRIP: trips){
            int src = TRIP[0];
            int dest = TRIP[1];
            
            bfs(src, dest, G, distFromSrc);
            bfs(dest, src, G, distFromDest);
            
            int targetDist = distFromSrc[dest];
            for(int node = 0; node < N; ++node){
                if(distFromSrc[node] + distFromDest[node] == targetDist){
                    coef[node] += 1;
                }
            }
        }
        
        // fix the root of the tree to be node = 0 and compute the dp:
        //      dp[0][i]: min cost for subtree with root node = i when we don't halve the price of node i
        //      dp[1][i]: min cost for subtree with root node = i when we halve the price of node i
        vector<vector<int>> dp(2, vector<int>(N, INF));
        dfs(-1, 0, G, price, coef, dp);
        
        return min(dp[0][0], dp[1][0]);
    }
};