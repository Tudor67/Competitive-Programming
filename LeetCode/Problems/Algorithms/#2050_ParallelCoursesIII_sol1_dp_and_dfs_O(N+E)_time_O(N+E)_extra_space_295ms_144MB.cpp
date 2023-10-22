class Solution {
private:
    const int INF = 1e9 + 5;

    void dfs(int node, vector<vector<int>>& G, vector<int>& time, vector<int>& minValidTime){
        if(minValidTime[node] != INF){
            return;
        }
        int maxChildTime = 0;
        for(int nextNode: G[node]){
            dfs(nextNode, G, time, minValidTime);
            maxChildTime = max(maxChildTime, minValidTime[nextNode]);
        }
        minValidTime[node] = time[node] + maxChildTime;
    }

public:
    int minimumTime(int N, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> G(N);
        for(const vector<int>& R: relations){
            int a = R[0] - 1;
            int b = R[1] - 1;
            G[b].push_back(a);
        }

        vector<int> minValidTime(N, INF);
        for(int node = 0; node < N; ++node){
            dfs(node, G, time, minValidTime);
        }

        return *max_element(minValidTime.begin(), minValidTime.end());
    }
};