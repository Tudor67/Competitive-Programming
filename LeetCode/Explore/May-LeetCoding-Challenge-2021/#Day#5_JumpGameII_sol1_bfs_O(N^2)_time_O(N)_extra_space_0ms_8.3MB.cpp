class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e8;
        
        vector<int> dist(N, INF);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        
        while(!q.empty() && dist[N - 1] == INF){
            int node = q.front();
            q.pop();
            
            for(int nextNode = node + 1; nextNode <= min(N - 1, node + nums[node]); ++nextNode){
                if(1 + dist[node] < dist[nextNode]){
                    dist[nextNode] = 1 + dist[node];
                    q.push(nextNode);
                }
            }
        }
        
        return dist[N - 1];
    }
};