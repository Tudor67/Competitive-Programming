class Solution {
public:
    vector<int> minEdgeReversals(int N, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back({b, 0});
            G[b].push_back({a, 1});
        }

        int totalCost = 0;
        vector<int> nodeBalance(N);
        queue<pair<int, int>> q;
        q.push({-1, 0});

        while(!q.empty()){
            int parent = q.front().first;
            int node = q.front().second;
            q.pop();

            for(const pair<int, int>& P: G[node]){
                int nextNode = P.first;
                int cost = P.second;
                int revCost = 1 - cost;
                if(nextNode != parent){
                    totalCost += cost;
                    nodeBalance[nextNode] = nodeBalance[node] - cost + revCost;
                    q.push({node, nextNode});
                }
            }
        }

        vector<int> answer(N);
        answer[0] = totalCost;
        for(int node = 1; node < N; ++node){
            answer[node] = totalCost + nodeBalance[node];
        }

        return answer;
    }
};