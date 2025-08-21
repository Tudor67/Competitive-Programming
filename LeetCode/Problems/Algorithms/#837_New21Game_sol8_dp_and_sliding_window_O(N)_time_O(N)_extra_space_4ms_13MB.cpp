class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if(k == 0){
            return 1;
        }

        // dp[i]: probability of getting i points
        vector<double> dp(n + 1);
        for(int i = 1; i <= min(n, maxPts); ++i){
            dp[i] = 1.0 / maxPts;
        }

        double wSum = 0;
        for(int i = 2; i <= n; ++i){
            if(i - 1 < k){
                wSum += dp[i - 1];
            }
            if(i >= maxPts + 1 && i - (maxPts + 1) < k){
                wSum -= dp[i - (maxPts + 1)];
            }
            dp[i] += (1.0 / maxPts) * wSum;
        }

        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};