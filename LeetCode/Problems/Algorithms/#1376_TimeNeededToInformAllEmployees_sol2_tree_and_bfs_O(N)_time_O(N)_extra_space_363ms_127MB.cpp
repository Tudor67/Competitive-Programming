class Solution {
public:
    int numOfMinutes(int N, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> childrenOf(N);
        for(int node = 0; node < N; ++node){
            if(manager[node] != -1){
                childrenOf[manager[node]].push_back(node);
            }
        }

        int maxTime = 0;
        queue<pair<int, int>> q;
        q.push({headID, 0});

        while(!q.empty()){
            int node = q.front().first;
            int nodeTime = q.front().second;
            q.pop();

            maxTime = max(maxTime, nodeTime);

            for(int child: childrenOf[node]){
                q.push({child, nodeTime + informTime[node]});
            }
        }

        return maxTime;
    }
};