class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> g(n);
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0];
            int y = EDGE[1];
            int w = EDGE[2];
            g[x].push_back({y, w});
            g[y].push_back({x, w});
        }
        
        const int INF = 1e9;
        vector<int> dist(n, INF);
        set<pair<int, int>> distNodeSet;
        distNodeSet.insert({0, 0});
        dist[0] = 0;
        
        while(!distNodeSet.empty()){
            int node = distNodeSet.begin()->second;
            distNodeSet.erase(distNodeSet.begin());
            
            for(const pair<int, int>& P: g[node]){
                int nextNode = P.first;
                int w = P.second;
                if(dist[node] + w + 1 < dist[nextNode] && dist[node] + w + 1 <= maxMoves){
                    set<pair<int, int>>::iterator it = distNodeSet.find({nextNode, dist[nextNode]});
                    if(it != distNodeSet.end()){
                        distNodeSet.erase(it);
                    }
                    dist[nextNode] = dist[node] + w + 1;
                    distNodeSet.insert({dist[nextNode], nextNode});
                }
            }
        }
        
        int answer = 0;
        for(int node = 0; node < n; ++node){
            if(dist[node] != INF){
                answer += 1;
            }
        }
        
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0];
            int y = EDGE[1];
            int w = EDGE[2];
            int maxCover = max(0, maxMoves - dist[x]) + max(0, maxMoves - dist[y]);
            int maxValidCover = min(w, maxCover);
            answer += maxValidCover;
        }
        
        return answer;
    }
};