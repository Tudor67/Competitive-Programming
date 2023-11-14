class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        const int N = routes.size();
        const int INF = 1e9;

        // Step 1: special case (source == target)
        if(source == target){
            return 0;
        }

        // Step 2: create graph G
        //         run multi-source BFS on graph G
        //         to compute min distance from source to target
        unordered_map<int, vector<int>> stationToBuses;
        for(int i = 0; i < N; ++i){
            for(int station: routes[i]){
                stationToBuses[station].push_back(i);
            }
        }

        vector<int> targetBuses = stationToBuses[target];

        queue<int> q;
        vector<int> dist(N, INF);
        for(int i: stationToBuses[source]){
            q.push(i);
            dist[i] = 1;
        }

        while(!q.empty()){
            int i = q.front();
            q.pop();

            for(int nextStation: routes[i]){
                for(int j: stationToBuses[nextStation]){
                    if(dist[i] + 1 < dist[j]){
                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }
                stationToBuses[nextStation].clear();
            }
        }
        
        int res = INF;
        for(int i: targetBuses){
            res = min(res, dist[i]);
        }

        if(res == INF){
            res = -1;
        }
        return res;
    }
};