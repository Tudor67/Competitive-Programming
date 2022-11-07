class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        const int N = nums.size();
        const long long TOTAL_COST = accumulate(cost.begin(), cost.end(), 0LL);
        
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        
        sort(p.begin(), p.end(),
             [&](const int& LHS, const int& RHS){
                 return (nums[LHS] < nums[RHS]);
             });
        
        int weightedMedian = nums[p[0]];
        long long prefCost = 0;
        for(int i = 0; i < N; ++i){
            prefCost += cost[p[i]];
            if(2 * prefCost >= TOTAL_COST){
                weightedMedian = nums[p[i]];
                break;
            }
        }
        
        long long res = 0;
        for(int i = 0; i < N; ++i){
            res += abs(nums[i] - weightedMedian) * 1LL * cost[i];
        }
        
        return res;
    }
};