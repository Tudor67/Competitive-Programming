class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        const int INF = 1e9;
        vector<int> distance(n, INF);
        distance[src] = 0;
        
        for(int i = 0; i <= K; ++i){
            vector<int> better_distance = distance;
            for(const vector<int>& arc: flights){
                int x = arc[0];
                int y = arc[1];
                int cost = arc[2];
                better_distance[y] = min(better_distance[y], distance[x] + cost);
            }
            distance = better_distance;
        }
        
        int answer = distance[dst];
        if(answer == INF){
            answer = -1;
        }
        
        return answer;
    }
};