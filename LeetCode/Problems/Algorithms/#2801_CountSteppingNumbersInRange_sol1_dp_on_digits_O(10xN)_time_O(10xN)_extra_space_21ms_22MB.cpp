class Solution {
private:
    const long long MODULO = 1e9 + 7;
    
    bool isSteppingNumber(const string& S){
        const int N = S.length();
        for(int i = 1; i < N; ++i){
            if(max(S[i - 1], S[i]) - min(S[i - 1], S[i]) != 1){
                return false;
            }
        }
        return true;
    }
    
    long long solve(const string& S){
        const int N = S.length();

        if(N == 1){
            return stoi(S);
        }
        
        // dp[len][d]: count of stepping numbers with length len and start digit d
        vector<vector<long long>> dp(N + 1, vector<long long>(10));
        for(int d = 0; d <= 9; ++d){
            dp[1][d] = 1;
        }
        
        for(int len = 1; len + 1 <= N; ++len){
            for(int d = 0; d <= 9; ++d){
                for(int nextDigit: {d - 1, d + 1}){
                    if(0 <= nextDigit && nextDigit <= 9){
                        dp[len + 1][nextDigit] += dp[len][d];
                        dp[len + 1][nextDigit] %= MODULO;
                    }
                }
            }
        }
        
        // count all stepping numbers of length 1, 2, 3, ..., N - 1
        long long res = 0;
        for(int len = 1; len <= N - 1; ++len){
            for(int d = 1; d <= 9; ++d){
                res += dp[len][d];
                res %= MODULO;
            }
        }
        
        // count all stepping numbers of length N and start digit < S[0]
        for(int d = 1; d < S[0] - '0'; ++d){
            if(d + 1 <= 9){
                res += dp[N - 1][d + 1];
                res %= MODULO;
            }
            if(0 <= d - 1){
                res += dp[N - 1][d - 1];
                res %= MODULO;
            }
        }
        
        // count all stepping numbers less than S, with length N and with fixed prefix S[0 .. i - 1]
        for(int i = 1; i < N; ++i){
            int remLen = N - i;
            int d = S[i - 1] - '0';

            if(d + 1 <= 9 && d + 1 < S[i] - '0'){
                res += dp[remLen][d + 1];
                res %= MODULO;
            }
            if(0 <= d - 1 && d - 1 < S[i] - '0'){
                res += dp[remLen][d - 1];
                res %= MODULO;
            }

            if(max(S[i - 1], S[i]) - min(S[i - 1], S[i]) != 1){
                return res;
            }
        }
        
        // check if S itself is a stepping number and update the result accordingly
        if(isSteppingNumber(S)){
            res += 1;
            res %= MODULO;
        }
        
        return res;
    }
    
public:
    int countSteppingNumbers(string low, string high) {
        return (solve(high) - solve(low) + isSteppingNumber(low) + MODULO) % MODULO;
    }
};