class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = cost.size();
        const int INF = 1e9;
        vector<int> minCost(N + 1, INF);
        minCost[0] = 0;
        minCost[1] = 0;
        for(int i = 2; i <= N; ++i){
            minCost[i] = min(minCost[i - 2] + cost[i - 2], minCost[i - 1] + cost[i - 1]);
        }
        return minCost[N];
    }
};