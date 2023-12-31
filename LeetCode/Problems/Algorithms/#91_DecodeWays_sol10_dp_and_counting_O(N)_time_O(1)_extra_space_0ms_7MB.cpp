class Solution {
public:
    int numDecodings(string s) {
        const int N = s.length();

        // At ith iteration:
        //    dp[i % 3]: number of ways to decode s[i .. N - 1]
        vector<int> dp(3);
        dp[N % 3] = 1;
        if(s[N - 1] >= '1'){
            dp[(N - 1) % 3] = 1;
        }

        for(int i = N - 2; i >= 0; --i){
            dp[i % 3] = 0;
            if(s[i] >= '1' && dp[i % 3] <= INT_MAX - dp[(i + 1) % 3]){
                dp[i % 3] += dp[(i + 1) % 3];
            }
            if(s[i] >= '1' && (s[i] - '0') * 10 + (s[i + 1] - '0') <= 26 && dp[i % 3] <= INT_MAX - dp[(i + 2) % 3]){
                dp[i % 3] += dp[(i + 2) % 3];
            }
        }

        return dp[0];
    }
};