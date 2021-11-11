class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        const int N = passingFees.size();
        const int E = edges.size();
        const int T = maxTime;
        const int INF = 1e8;
        
        vector<vector<pair<int, int>>> g(N);
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0];
            int y = EDGE[1];
            int t = EDGE[2];
            g[x].emplace_back(y, t);
            g[y].emplace_back(x, t);
        }
        
        // minCost[node][t]: min cost (= sum of passing fees) to reach node at time t
        int minCost[N][maxTime + 1];
        for(int node = 0; node < N; ++node){
            fill(minCost[node], minCost[node] + maxTime + 1, INF);
        }
        minCost[0][0] = passingFees[0];
        
        // state = (cost, time, node)
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> stateMinHeap;
        stateMinHeap.emplace(minCost[0][0], 0, 0);
        
        // lastTime[node]: last time of a visited node
        //                 remember that we process the nodes in increasing order of {cost, time}
        vector<int> lastTime(N, INF);
        
        while(!stateMinHeap.empty()){
            int cost, xTime, x;
            tie(cost, xTime, x) = stateMinHeap.top();
            stateMinHeap.pop();
            
            if(x == N - 1){
                return cost;
            }
            
            if(minCost[x][xTime] < cost){
                continue;
            }
            
            if(lastTime[x] <= xTime){
                // at this point (lastCost, lastTime) <= (cost, time)
                continue;
            }
            lastTime[x] = xTime;
            
            for(const pair<int, int>& P: g[x]){
                int y = P.first;
                int xyTransitionTime = P.second;
                int yTime = xTime + xyTransitionTime;
                if(yTime <= maxTime){
                    if(minCost[x][xTime] + passingFees[y] < minCost[y][yTime]){
                        minCost[y][yTime] = minCost[x][xTime] + passingFees[y];
                        stateMinHeap.emplace(minCost[y][yTime], yTime, y);
                    }
                }
            }
        }
        
        return -1;
    }
};