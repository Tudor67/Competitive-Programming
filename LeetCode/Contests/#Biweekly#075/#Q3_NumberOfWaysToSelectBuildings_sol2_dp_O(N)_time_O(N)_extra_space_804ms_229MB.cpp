class Solution {
public:
    long long numberOfWays(string s) {
        const int N = s.length();
        const int K = 3;
        
        // At step len:
        //    dp0[len % 2][i]: number of subsequences with alternating values in s[0 .. i]
        //                     such that length(subsequence) == len and the last value is 0
        //    dp1[len % 2][i]: number of subsequences with alternating values in s[0 .. i]
        //                     such that length(subsequence) == len and the last value is 1
        vector<vector<long long>> dp0(2, vector<long long>(N));
        vector<vector<long long>> dp1(2, vector<long long>(N));
        
        dp0[1][0] = (int)(s[0] == '0');
        dp1[1][0] = (int)(s[0] == '1');
        for(int i = 1; i < N; ++i){
            dp0[1][i] = dp0[1][i - 1];
            dp1[1][i] = dp1[1][i - 1];
            if(s[i] == '0'){
                dp0[1][i] += 1;
            }else{
                dp1[1][i] += 1;
            }
        }
        
        for(int len = 2; len <= K; ++len){
            dp0[len % 2][0] = 0;
            dp1[len % 2][0] = 0;
            for(int i = 1; i < N; ++i){
                dp0[len % 2][i] = dp0[len % 2][i - 1];
                dp1[len % 2][i] = dp1[len % 2][i - 1];
                if(s[i] == '0'){
                    dp0[len % 2][i] += dp1[(len - 1) % 2][i - 1];
                }else{
                    dp1[len % 2][i] += dp0[(len - 1) % 2][i - 1];
                }
            }
        }
        
        return (dp0[K % 2][N - 1] + dp1[K % 2][N - 1]);
    }
};