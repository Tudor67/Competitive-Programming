class Solution {
public:
    int distinctSequences(int n) {
        const int MODULO = 1e9 + 7;
        
        int gcdCache[7][7];
        for(int num1 = 1; num1 <= 6; ++num1){
            for(int num2 = 1; num2 <= 6; ++num2){
                gcdCache[num1][num2] = gcd(num1, num2);
            }
        }
        
        // At ith iteration:
        //    dp[i % 2][num1][num2]: the total number (% MODULO) of valid sequences of size i
        //                           with the last two elements (num1, num2)
        int dp[2][7][7];
        for(int num1 = 0; num1 <= 6; ++num1){
            for(int num2 = 0; num2 <= 6; ++num2){
                dp[1][num1][num2] = 0;
            }
        }
        
        for(int num2 = 1; num2 <= 6; ++num2){
            dp[1][0][num2] = 1;
        }
        
        for(int i = 2; i <= n; ++i){
            for(int num1 = 0; num1 <= 6; ++num1){
                for(int num2 = 0; num2 <= 6; ++num2){
                    dp[i % 2][num1][num2] = 0;
                }
            }
            for(int num1 = 1; num1 <= 6; ++num1){
                for(int num2 = 1; num2 <= 6; ++num2){
                    if(num1 == num2 || gcdCache[num1][num2] != 1){
                        continue;
                    }
                    for(int num0 = 0; num0 <= 6; ++num0){
                        if(num0 == num2){
                            continue;
                        }
                        dp[i % 2][num1][num2] += dp[(i - 1) % 2][num0][num1];
                        dp[i % 2][num1][num2] %= MODULO;
                    }
                }
            }
        }
        
        int res = 0;
        for(int num1 = 0; num1 <= 6; ++num1){
            for(int num2 = 0; num2 <= 6; ++num2){
                res += dp[n % 2][num1][num2];
                res %= MODULO;
            }
        }
        
        return res;
    }
};