class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int N = nums.size();
        const long long TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0LL);
        const long long MODULO = 1e9 + 7;

        if(N <= 1 || TOTAL_SUM < 2 * k){
            return 0;
        }
        
        // dp[s]: number of subsets (%MODULO) of nums with sum s
        vector<long long> dp(k);
        dp[0] = 1;
        for(int num: nums){
            for(int sum = k - 1; sum >= num; --sum){
                dp[sum] = (dp[sum] + dp[sum - num]) % MODULO;
            }
        }
        
        long long badPartitions = 0;
        for(int sum = 0; sum <= k - 1; ++sum){
            badPartitions = (badPartitions + 2 * dp[sum]) % MODULO;
        }
        
        long long totalPartitions = 1;
        for(int i = 1; i <= N; ++i){
            totalPartitions = (totalPartitions * 2) % MODULO;
        }
        
        return (totalPartitions - badPartitions + MODULO) % MODULO;
    }
};