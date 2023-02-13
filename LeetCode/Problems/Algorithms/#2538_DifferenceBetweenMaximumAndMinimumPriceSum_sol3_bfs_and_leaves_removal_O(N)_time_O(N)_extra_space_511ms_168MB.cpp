class Solution {
public:
    long long maxOutput(int N, vector<vector<int>>& edges, vector<int>& price) {        
        vector<vector<int>> G(N);
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        // s0[node]: max path sum so far to reach node from starting leaf (starting leaf is not included)
        // s1[node]: max path sum so far to reach node from starting leaf (starting leaf is included)
        vector<long long> s0(N);
        vector<long long> s1(N);

        queue<int> q;
        vector<int> degree(N);
        for(int node = 0; node < N; ++node){
            if((int)G[node].size() == 1){
                q.push(node);
                s0[node] = 0;
                s1[node] = price[node];
            }
            degree[node] = G[node].size();
        }

        long long res = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            degree[node] -= 1;

            for(int nextNode: G[node]){
                if(degree[nextNode] >= 1){
                    res = max(res, max(s0[node] + s1[nextNode], s1[node] + s0[nextNode]));
                    s0[nextNode] = max(s0[nextNode], s0[node] + price[nextNode]);
                    s1[nextNode] = max(s1[nextNode], s1[node] + price[nextNode]);

                    degree[nextNode] -= 1;
                    if(degree[nextNode] == 1){
                        q.push(nextNode);
                    }
                }
            }
        }
        
        return res;
    }
};