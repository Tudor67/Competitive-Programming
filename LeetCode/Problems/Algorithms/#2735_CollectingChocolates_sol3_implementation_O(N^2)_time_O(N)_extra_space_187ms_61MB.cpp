class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        const int N = nums.size();

        long long res = LLONG_MAX;

        vector<int> minCost = nums;
        for(long long ops = 0; ops < N; ++ops){
            for(int i = 0; i < N; ++i){
                minCost[i] = min(minCost[i], nums[(i + ops) % N]);
            }
            long long minCostSum = accumulate(minCost.begin(), minCost.end(), 0LL);
            res = min(res, ops * x + minCostSum);
        }
        
        return res;
    }
};