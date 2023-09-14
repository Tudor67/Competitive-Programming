class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        const int N = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        // dp[len][s]: number of possible sequences of length len that add up to s
        vector<vector<long long>> dp(target + 1, vector<long long>(target + 1));
        dp[0][0] = 1;
        
        long long res = 0;
        for(int len = 1; len <= target; ++len){
            for(int s = 1; s <= target; ++s){
                for(int num: sortedNums){
                    if(num <= s){
                        dp[len][s] += dp[len - 1][s - num];
                        dp[len][s] = min(dp[len][s], (long long)INT_MAX);
                    }else{
                        break;
                    }
                }
            }
            res += dp[len][target];
        }

        return res;
    }
};