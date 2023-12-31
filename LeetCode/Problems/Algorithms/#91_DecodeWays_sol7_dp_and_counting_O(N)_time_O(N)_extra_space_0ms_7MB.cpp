class Solution {
public:
    int numDecodings(string s) {
        const int N = s.length();

        // dp[i]: number of ways to decode s[0 .. i]
        vector<int> dp(N);
        if(s[0] >= '1'){
            dp[0] = 1;
        }

        for(int i = 1; i < N; ++i){
            if(s[i - 1] >= '1'){
                int lastCode = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if(lastCode <= 26){
                    if(i == 1){
                        dp[i] += 1;
                    }else if(dp[i] <= INT_MAX - dp[i - 2]){
                        dp[i] += dp[i - 2];
                    }
                }
            }
            if(s[i] >= '1' && dp[i] <= INT_MAX - dp[i - 1]){
                dp[i] += dp[i - 1];
            }
        }

        return dp[N - 1];
    }
};