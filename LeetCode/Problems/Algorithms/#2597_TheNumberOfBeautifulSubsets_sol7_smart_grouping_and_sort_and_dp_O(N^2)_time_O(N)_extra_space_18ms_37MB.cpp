class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(),
             [&](int lhs, int rhs){
                return (pair<int, int>{lhs % k, lhs} <
                        pair<int, int>{rhs % k, rhs});
             });

        vector<int> dp(N, 1);
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                if(sortedNums[i] - sortedNums[j] != k){
                    dp[i] += dp[j];
                }
            }
        }

        return accumulate(dp.begin(), dp.end(), 0);
    }
};