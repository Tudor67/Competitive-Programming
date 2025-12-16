class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        // dp[i]: number of valid partitions for nums[i .. N - 1]
        vector<int> dp(N + 1);
        dp[N] = 1;

        for(int i = N - 1; i >= 0; --i){
            int minNum = nums[i];
            int maxNum = nums[i];
            for(int j = i; j < N; ++j){
                minNum = min(minNum, nums[j]);
                maxNum = max(maxNum, nums[j]);
                if(maxNum - minNum <= k){
                    dp[i] = (dp[i] + dp[j + 1]) % MODULO;
                }else{
                    break;
                }
            }
        }

        return dp[0];
    }
};