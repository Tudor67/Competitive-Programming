class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int N, vector<vector<int>>& queries) {
        const int Q = queries.size();

        vector<int> dp(N);
        vector<vector<int>> G(N);
        for(int node = N - 2; node >= 0; --node){
            dp[node] = N - 1 - node;
            G[node].push_back(node + 1);
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];
            G[a].push_back(b);
            
            if(dp[a] > dp[b] + 1){
                for(int node = a; node >= 0; --node){
                    for(int nextNode: G[node]){
                        dp[node] = min(dp[node], dp[nextNode] + 1);
                    }
                }
            }

            res[i] = dp[0];
        }

        return res;
    }
};