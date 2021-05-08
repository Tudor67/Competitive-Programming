class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e8;
        
        vector<int> dist(N, INF);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        
        set<int> candidateNodes;
        for(int node = 1; node <= N - 1; ++node){
            candidateNodes.insert(node);
        }
        
        while(!q.empty() && dist[N - 1] == INF){
            int node = q.front();
            q.pop();
            
            set<int>::iterator it1 = candidateNodes.upper_bound(node);
            set<int>::iterator it2 = candidateNodes.upper_bound(min(N - 1, node + nums[node]));
            while(it1 != it2){
                int nextNode = *it1;
                dist[nextNode] = 1 + dist[node];
                q.push(nextNode);
                it1 = candidateNodes.erase(it1);
            }
        }
        
        return dist[N - 1];
    }
};