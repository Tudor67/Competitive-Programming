class Solution {
public:
    int findCheapestPrice(int N, vector<vector<int>>& flights, int src, int dst, int K) {
        const int F = flights.size();
        const int INF = 1e9;

        vector<vector<pair<int, int>>> G(N);
        for(const vector<int>& FLIGHT: flights){
            int a = FLIGHT[0];
            int b = FLIGHT[1];
            int price = FLIGHT[2];
            G[a].push_back({price, b});
        }

        vector<vector<int>> minCost(N, vector<int>(K + 3, INF));
        set<tuple<int, int, int>> statesSet;
        minCost[src][1] = 0;
        statesSet.insert({minCost[src][0], 1, src});

        while(!statesSet.empty()){
            int visNodes = get<1>(*statesSet.begin());
            int node = get<2>(*statesSet.begin());
            statesSet.erase(statesSet.begin());

            if(node == dst){
                break;
            }

            if(visNodes == K + 2){
                continue;
            }

            for(const pair<int, int>& P: G[node]){
                int price = P.first;
                int nextNode = P.second;
                int nextVisNodes = visNodes + 1;
                if(minCost[node][visNodes] + price < minCost[nextNode][nextVisNodes]){
                    statesSet.erase({minCost[nextNode][nextVisNodes], nextVisNodes, nextNode});
                    minCost[nextNode][nextVisNodes] = minCost[node][visNodes] + price;
                    statesSet.insert({minCost[nextNode][nextVisNodes], nextVisNodes, nextNode});
                }
            }
        }

        int res = *min_element(minCost[dst].begin(), minCost[dst].end());
        if(res == INF){
            res = -1;
        }

        return res;
    }
};