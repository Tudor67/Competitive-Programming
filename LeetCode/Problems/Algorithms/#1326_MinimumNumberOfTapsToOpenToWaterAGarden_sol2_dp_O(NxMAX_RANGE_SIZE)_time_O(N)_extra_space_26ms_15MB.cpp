class Solution {
public:
    int minTaps(int N, vector<int>& ranges) {
        const int INF = 1e9;

        vector<int> maxStepAt(N + 1);
        for(int i = 0; i <= N; ++i){
            int l = max(0, i - ranges[i]);
            int r = min(N, i + ranges[i]);
            maxStepAt[l] = max(maxStepAt[l], r - l);
        }

        // dp[i]: min cost to water the range [i .. N]
        vector<int> dp(N + 1, INF);
        for(int i = N; i >= 0; --i){
            if(i + maxStepAt[i] >= N){
                dp[i] = 1;
            }else{
                for(int j = i + 1; j <= i + maxStepAt[i]; ++j){
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }

        if(dp[0] != INF){
            return dp[0];
        }

        return -1;
    }
};