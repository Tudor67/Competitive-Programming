class Solution {
public:    
    int countNumbersWithUniqueDigits(int n) {
        n = min(10, n);        // numbers >= 10^10 don't have unique digits => we can ignore them
        vector<int> dp(11, 0); // dp[i] = counter of all numbers with unique digits in the range [10^{i-1}, 10^i)
        dp[0] = 1;
        dp[1] = 9;
        for(int i = 2; i < dp.size(); ++i){
            dp[i] = (10 - (i - 1)) * dp[i - 1];
        }
        
        int ans = 0;
        for(int i = 0; i <= n; ++i){
            ans += dp[i];
        }
        
        return ans;
    }
};