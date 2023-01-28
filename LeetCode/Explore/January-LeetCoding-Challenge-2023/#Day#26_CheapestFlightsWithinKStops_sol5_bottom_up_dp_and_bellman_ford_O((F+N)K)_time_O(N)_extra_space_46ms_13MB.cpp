class Solution {
public:
    int findCheapestPrice(int N, vector<vector<int>>& flights, int src, int dst, int K) {
        const int F = flights.size();
        const int INF = 1e9;

        vector<int> minCost(N, INF);
        vector<int> prevMinCost(N, INF);
        minCost[src] = 0;
        prevMinCost[src] = 0;

        for(int visNodes = 2; visNodes <= K + 2; ++visNodes){
            for(const vector<int>& FLIGHT: flights){
                int a = FLIGHT[0];
                int b = FLIGHT[1];
                int price = FLIGHT[2];
                minCost[b] = min(minCost[b], prevMinCost[a] + price);
            }
            prevMinCost = minCost;
        }

        if(minCost[dst] == INF){
            minCost[dst] = -1;
        }

        return minCost[dst];
    }
};