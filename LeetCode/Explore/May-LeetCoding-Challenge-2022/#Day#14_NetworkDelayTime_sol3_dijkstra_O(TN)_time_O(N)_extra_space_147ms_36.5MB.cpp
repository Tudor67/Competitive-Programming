class Solution {
private:
    const int INF = 1e9;
    
    void dijkstra(int startNode, vector<vector<int>>& times, vector<int>& minDist){
        fill(minDist.begin(), minDist.end(), INF);
        minDist[startNode] = 0;
        
        bool updated = true;
        while(updated){
            updated = false;
            for(const vector<int>& V: times){
                int x = V[0] - 1;
                int y = V[1] - 1;
                int w = V[2];
                if(minDist[x] + w < minDist[y]){
                    minDist[y] = minDist[x] + w;
                    updated = true;
                }
            }
        }
    }
    
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> minDist(N);
        dijkstra(K - 1, times, minDist);
        
        int res = *max_element(minDist.begin(), minDist.end());
        if(res == INF){
            res = -1;
        }
        
        return res;
    }
};