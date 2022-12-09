class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        const int N = roads.size() + 1;
        
        vector<vector<int>> G(N);
        vector<int> inDegree(N);
        for(const vector<int>& ROAD: roads){
            int a = ROAD[0];
            int b = ROAD[1];
            G[a].push_back(b);
            G[b].push_back(a);
            inDegree[a] += 1;
            inDegree[b] += 1;
        }
        
        long long res = 0;
        vector<int> subtreeSize(N, 1);
        queue<int> q;
        for(int node = 1; node < N; ++node){
            if(inDegree[node] == 1){
                q.push(node);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            res += (subtreeSize[node] + seats - 1) / seats;

            for(int nextNode: G[node]){
                inDegree[nextNode] -= 1;
                subtreeSize[nextNode] += subtreeSize[node];
                if(inDegree[nextNode] == 1 && nextNode != 0){
                    q.push(nextNode);
                }
            }
        }
        
        return res;
    }
};