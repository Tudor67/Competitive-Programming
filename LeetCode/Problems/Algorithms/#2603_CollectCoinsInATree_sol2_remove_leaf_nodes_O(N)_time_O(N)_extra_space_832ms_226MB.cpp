class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        const int N = coins.size();
        const int INF = 1e9;
        const int MAX_COVERED_DISTANCE = 2;

        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        queue<int> q;
        vector<int> degree(N);
        vector<int> maxSteps(N, INF);
        for(int node = 0; node < N; ++node){
            degree[node] = G[node].size();
            if(degree[node] == 1){
                q.push(node);
            }
            if(coins[node] == 1){
                maxSteps[node] = MAX_COVERED_DISTANCE;
            }
        }

        int remainingNodes = N;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            remainingNodes -= 1;

            for(int nextNode: G[node]){
                maxSteps[nextNode] = min(maxSteps[nextNode], maxSteps[node] - 1);
                degree[nextNode] -= 1;
                if(degree[nextNode] == 1 && maxSteps[nextNode] >= 1){
                    q.push(nextNode);
                }
            }
        }

        return max(0, 2 * (remainingNodes - 1));
    }
};