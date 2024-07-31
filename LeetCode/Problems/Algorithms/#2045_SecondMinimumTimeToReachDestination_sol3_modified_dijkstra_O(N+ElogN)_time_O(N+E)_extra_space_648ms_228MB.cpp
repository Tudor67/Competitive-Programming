class Solution {
public:
    int secondMinimum(int N, vector<vector<int>>& edges, int travelTime, int changeTime) {
        const int E = edges.size();
        const int INF = 1e9;

        vector<vector<int>> G(N);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0] - 1;
            int b = EDGE[1] - 1;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        // t[0][i]: min time from 0 to i
        // t[1][i]: second min time (strictly larger than min time) from 0 to i
        vector<vector<int>> t(2, vector<int>(N, INF));
        using State = tuple<int, int, int>;
        set<State> statesSet;
        t[0][0] = 0;
        statesSet.insert({t[0][0], 0, 0});

        while(!statesSet.empty()){
            int tType = get<1>(*statesSet.begin());
            int node = get<2>(*statesSet.begin());
            statesSet.erase(statesSet.begin());

            int x = t[tType][node] / changeTime;
            int startTime = max(t[tType][node], (x + (x % 2)) * changeTime);

            for(int nextNode: G[node]){
                int nextTime = startTime + travelTime;
                if(nextTime < t[0][nextNode]){
                    statesSet.erase({t[0][nextNode], 0, nextNode});
                    statesSet.erase({t[1][nextNode], 1, nextNode});
                    t[1][nextNode] = t[0][nextNode];
                    t[0][nextNode] = nextTime;
                    statesSet.insert({t[0][nextNode], 0, nextNode});
                    statesSet.insert({t[1][nextNode], 1, nextNode});
                }else if(t[0][nextNode] < nextTime && nextTime < t[1][nextNode]){
                    statesSet.erase({t[1][nextNode], 1, nextNode});
                    t[1][nextNode] = nextTime;
                    statesSet.insert({t[1][nextNode], 1, nextNode});
                }
            }
        }

        return t[1][N - 1];
    }
};