class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int N = arr.size();
        const int INF = 1e9;

        unordered_map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[arr[i]].push_back(i);
        }

        vector<int> dist(N, INF);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while(!q.empty() && dist[N - 1] == INF){
            int i = q.front();
            q.pop();

            if(i - 1 >= 0 && dist[i - 1] == INF){
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            if(i + 1 < N && dist[i + 1] == INF){
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            for(int j: numToIndices[arr[i]]){
                if(dist[j] == INF){
                    dist[j] = dist[i] + 1;
                    q.push(j);
                }
            }
            numToIndices[arr[i]].clear();
        }

        return dist[N - 1];
    }
};