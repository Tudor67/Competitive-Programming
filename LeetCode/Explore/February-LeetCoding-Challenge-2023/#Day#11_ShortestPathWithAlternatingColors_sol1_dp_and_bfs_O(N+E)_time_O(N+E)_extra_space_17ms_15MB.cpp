class Solution {
public:
    vector<int> shortestAlternatingPaths(int N, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        const int INF = 1e9;

        enum Color { RED, BLUE };
        vector<vector<pair<int, int>>> G(N);

        for(const vector<int>& E: redEdges){
            int a = E[0];
            int b = E[1];
            G[a].push_back({Color::RED, b});
        }

        for(const vector<int>& E: blueEdges){
            int a = E[0];
            int b = E[1];
            G[a].push_back({Color::BLUE, b});
        }

        vector<vector<int>> dist(2, vector<int>(N, INF));
        queue<pair<int, int>> q;
        dist[Color::RED][0] = 0;
        dist[Color::BLUE][0] = 0;
        q.push({Color::RED, 0});
        q.push({Color::BLUE, 0});

        while(!q.empty()){
            int color = q.front().first;
            int node = q.front().second;
            q.pop();

            for(const pair<int, int>& P: G[node]){
                int nextColor = P.first;
                int nextNode = P.second;
                if(color != nextColor && dist[color][node] + 1 < dist[nextColor][nextNode]){
                    dist[nextColor][nextNode] = dist[color][node] + 1;
                    q.push({nextColor, nextNode});
                }
            }
        }

        vector<int> answer(N);
        for(int node = 0; node < N; ++node){
            int minDistance = min(dist[Color::RED][node], dist[Color::BLUE][node]);
            if(minDistance == INF){
                answer[node] = -1;
            }else{
                answer[node] = minDistance;
            }
        }

        return answer;
    }
};