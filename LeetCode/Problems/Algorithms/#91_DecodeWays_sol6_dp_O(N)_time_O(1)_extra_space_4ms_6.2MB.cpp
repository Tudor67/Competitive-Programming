class Solution {
public:
    int numDecodings(string s) {
        const int N = s.length();
        
        // At ith iteration:
        //    dp[i % 3]: number of ways to decode s[0 .. i]
        vector<int> dp(3);
        if(s[0] != '0'){
            dp[0] = 1;
        }
        
        for(int i = 1; i < N; ++i){
            dp[i % 3] = 0;
            if(s[i] != '0'){
                dp[i % 3] += dp[(i - 1) % 3];
            }
            if(s[i - 1] != '0' && s.substr(i - 1, 2) <= "26"){
                if(i - 2 >= 0){
                    dp[i % 3] += dp[(i - 2) % 3];
                }else{
                    dp[i % 3] += 1;
                }
            }
        }
        
        return dp[(N - 1) % 3];
    }
};