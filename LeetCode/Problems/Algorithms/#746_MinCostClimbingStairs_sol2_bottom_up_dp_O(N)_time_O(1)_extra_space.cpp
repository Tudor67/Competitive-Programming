class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = cost.size();
        int minCost0 = 0;
        int minCost1 = 0;
        int minCost2 = 0;
        for(int i = 2; i <= N; ++i){
            minCost2 = min(minCost0 + cost[i - 2], minCost1 + cost[i - 1]);
            minCost0 = minCost1;
            minCost1 = minCost2;
        }
        return minCost2;
    }
};