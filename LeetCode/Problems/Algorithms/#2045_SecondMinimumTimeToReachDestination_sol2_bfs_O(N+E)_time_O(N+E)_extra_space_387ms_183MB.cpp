class Solution {
public:
    int secondMinimum(int N, vector<vector<int>>& edges, int travelTime, int changeTime) {
        const int E = edges.size();
        const int INF = 1e9;

        // Step 1: create graph G
        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0] - 1;
            int b = EDGE[1] - 1;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        // Step 2: run BFS from node = 0
        vector<int> dist(N, INF);
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int nextNode: G[node]){
                if(dist[nextNode] == INF){
                    dist[nextNode] = 1 + dist[node];
                    q.push(nextNode);
                }
            }
        }

        // Step 3: run BFS from node = (N - 1)
        //         to mark all nodes of shortest paths from 0 to (N - 1)
        vector<bool> inShortestPaths(N, false);
        q.push(N - 1);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            inShortestPaths[node] = true;

            for(int nextNode: G[node]){
                if(dist[nextNode] == dist[node] - 1){
                    q.push(nextNode);
                }
            }
        }

        // Step 4: check if there is a path of length targetLength = (minLength + 1)
        //         otherwise use a path of length targetLength = (minLength + 2)
        int minLength = dist[N - 1];
        int targetLength = minLength + 2;
        for(int node = 0; node < N; ++node){
            if(inShortestPaths[node]){
                for(int nextNode: G[node]){
                    if(dist[node] == dist[nextNode]){
                        targetLength = minLength + 1;
                        break;
                    }
                }
            }
        }

        // Step 5: compute the total time for a valid path of length targetLength
        int currentTime = 0;
        for(int i = 1; i <= targetLength; ++i){
            int x = currentTime / changeTime;
            if(x % 2 == 1){
                x += 1;
            }
            currentTime = max(currentTime, x * changeTime) + travelTime;
        }

        return currentTime;
    }
};