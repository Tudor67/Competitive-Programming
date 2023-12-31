class Solution {
public:
    int numDecodings(string s) {
        const int N = s.length();

        // At ith iteration:
        //    dp[i % 3]: number of ways to decode s[0 .. i]
        vector<int> dp(3);
        if(s[0] >= '1'){
            dp[0] = 1;
        }

        for(int i = 1; i < N; ++i){
            dp[i % 3] = 0;
            if(s[i - 1] >= '1'){
                int lastCode = (s[i - 1] - '0') * 10 + (s[i] - '0');
                if(lastCode <= 26){
                    if(i == 1){
                        dp[i % 3] += 1;
                    }else if(dp[i % 3] <= INT_MAX - dp[(i - 2) % 3]){
                        dp[i % 3] += dp[(i - 2) % 3];
                    }
                }
            }
            if(s[i] >= '1' && dp[i % 3] <= INT_MAX - dp[(i - 1) % 3]){
                dp[i % 3] += dp[(i - 1) % 3];
            }
        }

        return dp[(N - 1) % 3];
    }
};