class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int N = arr.size();
        const int INF = 1e9;
        
        unordered_map<int, vector<int>> posOf;
        for(int i = 0; i < N; ++i){
            posOf[arr[i]].push_back(i);
        }
        
        vector<int> dist(N, INF);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        
        while(!q.empty() && dist[N - 1] == INF){
            int i = q.front();
            q.pop();
            
            if(i - 1 >= 0 && dist[i - 1] == INF){
                q.push(i - 1);
                dist[i - 1] = dist[i] + 1;
            }
            
            if(i + 1 < N && dist[i + 1] == INF){
                q.push(i + 1);
                dist[i + 1] = dist[i] + 1;
            }
            
            while(!posOf[arr[i]].empty()){
                int j = posOf[arr[i]].back();
                if(dist[j] == INF){
                    q.push(j);
                    dist[j] = dist[i] + 1;
                }
                posOf[arr[i]].pop_back();
            }
        }
        
        return dist[N - 1];
    }
};