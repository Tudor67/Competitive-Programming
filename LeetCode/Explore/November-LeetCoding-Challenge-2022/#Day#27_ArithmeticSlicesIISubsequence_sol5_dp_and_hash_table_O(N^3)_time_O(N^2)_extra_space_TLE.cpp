class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        
        if(N <= 2){
            return 0;
        }
        
        // At iteration len:
        //    dp[i][d]: number of arithmetic subsequences
        //              of length len, members difference d and with the last element nums[i]
        long long res = 0;
        vector<unordered_map<long long, long long>> prevDp(N);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                long long d = (long long)nums[i] - (long long)nums[j];
                prevDp[i][d] += 1;
            }
        }
        
        vector<unordered_map<long long, long long>> dp(N);
        for(int len = 3; len <= N; ++len){
            for(int i = 0; i < N; ++i){
                dp[i].clear();
            }
            for(int i = len - 1; i < N; ++i){
                for(int j = 0; j < i; ++j){
                    long long d = (long long)nums[i] - (long long)nums[j];
                    dp[i][d] += prevDp[j][d];
                }
            }
            for(int i = len - 1; i < N; ++i){
                for(const pair<long long, long long>& P: dp[i]){
                    res += P.second;
                }
            }
            prevDp = dp;
        }
        
        return res;
    }
};