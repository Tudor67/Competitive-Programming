class Solution {
public:
    int numSquares(int n) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        q.push(0);
        dist[0] = 0;
        
        while(!q.empty() && dist[n] == -1){
            int i = q.front();
            q.pop();
            
            for(int j = 1; i + j * j <= n; ++j){
                int next_i = i + j * j;
                if(dist[next_i] == -1){
                    dist[next_i] = 1 + dist[i];
                    q.push(next_i);
                }
            }
        }
        
        return dist[n];
    }
};