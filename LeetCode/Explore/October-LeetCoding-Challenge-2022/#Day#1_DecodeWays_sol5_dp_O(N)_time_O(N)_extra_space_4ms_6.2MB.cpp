class Solution {
public:
    int numDecodings(string s) {
        const int N = s.length();
        
        // dp[i]: number of ways to decode s[0 .. i]
        vector<int> dp(N);
        if(s[0] != '0'){
            dp[0] = 1;
        }
        
        for(int i = 1; i < N; ++i){
            if(s[i] != '0'){
                dp[i] += dp[i - 1];
            }
            if(s[i - 1] != '0' && s.substr(i - 1, 2) <= "26"){
                if(i - 2 >= 0){
                    dp[i] += dp[i - 2];
                }else{
                    dp[i] += 1;
                }
            }
        }
        
        return dp[N - 1];
    }
};