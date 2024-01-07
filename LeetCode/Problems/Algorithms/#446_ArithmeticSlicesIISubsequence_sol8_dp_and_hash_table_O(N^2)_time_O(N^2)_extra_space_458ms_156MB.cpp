class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        vector<unordered_map<long long, int>> dp(N);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                long long diff = (long long)nums[i] - (long long)nums[j];
                dp[i][diff] += 1;
                res -= 1;
            }
        }

        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                long long diff = (long long)nums[i] - (long long)nums[j];
                if(dp[j].count(diff)){
                    dp[i][diff] += dp[j][diff];
                }
            }

            for(pair<const long long, int>& P: dp[i]){
                res += P.second;
            }
        }

        return res;
    }
};