class Solution {
private:
    int countBeautifulIntegers(const int LIMIT, const int K){
        const string LIMIT_STR = to_string(LIMIT);
        const int LEN = LIMIT_STR.length();

        if(LIMIT <= 10){
            return 0;
        }

        // dp0[len][rem][bal + LEN]: number of integers (with possible leading zeros) with length len,
        //                           remainder rem, difference between even and odd digits equal to bal
        // dp1[len][rem][bal + LEN]: number of integers (without leading zeros) with length len,
        //                           remainder rem, difference between even and odd digits equal to bal
        vector<vector<vector<int>>> dp0(LEN, vector<vector<int>>(K, vector<int>(2 * LEN)));
        vector<vector<vector<int>>> dp1(LEN, vector<vector<int>>(K, vector<int>(2 * LEN)));
        dp0[0][0][0 + LEN] = 1;
        dp0[1][0][1 + LEN] = 1;
        for(int digit = 1; digit <= 9; ++digit){
            dp0[1][digit % K][(int)(digit % 2 == 0) - (int)(digit % 2 == 1) + LEN] += 1;
            dp1[1][digit % K][(int)(digit % 2 == 0) - (int)(digit % 2 == 1) + LEN] += 1;
        }

        for(int len = 1; len + 1 < LEN; ++len){
            for(int rem = 0; rem < K; ++rem){
                for(int c0 = 0; c0 <= len; ++c0){
                    int c1 = len - c0;
                    for(int newDigit = 0; newDigit <= 9; ++newDigit){
                        int nextLen = len + 1;
                        int nextRem = (rem * 10 + newDigit) % K;
                        int nextC0 = c0 + (int)(newDigit % 2 == 0);
                        int nextC1 = c1 + (int)(newDigit % 2 == 1);
                        dp0[nextLen][nextRem][nextC0 - nextC1 + LEN] += dp0[len][rem][c0 - c1 + LEN];
                        dp1[nextLen][nextRem][nextC0 - nextC1 + LEN] += dp1[len][rem][c0 - c1 + LEN];
                    }
                }
            }
        }

        int res = 0;
        for(int len = 2; len < LEN; len += 2){
            res += dp1[len][0][0 + LEN];
        }
        
        int prefRem = 0;
        int prefC0 = 0;
        int prefC1 = 0;
        int maxPow10 = 1;
        for(int i = 1; i <= LEN - 1; ++i){
            maxPow10 *= 10;
        }

        for(int i = 0; i < LEN; ++i){
            int startDigit = (i == 0 ? 1 : 0);
            for(int newDigit = startDigit; newDigit < LIMIT_STR[i] - '0'; ++newDigit){
                int targetLen = LEN - 1 - i;
                int newRem = (prefRem + newDigit * maxPow10) % K;
                int targetRem = (K - newRem) % K;
                int targetC0 = LEN / 2 - prefC0 - (int)(newDigit % 2 == 0);
                int targetC1 = LEN / 2 - prefC1 - (int)(newDigit % 2 == 1);
                if(targetC0 >= 0 && targetC1 >= 0){
                    res += dp0[targetLen][targetRem][targetC0 - targetC1 + LEN];
                }
            }
            prefRem = (prefRem + (LIMIT_STR[i] - '0') * maxPow10) % K;
            maxPow10 = maxPow10 / 10;
            prefC0 += (int)((LIMIT_STR[i] - '0') % 2 == 0);
            prefC1 += (int)((LIMIT_STR[i] - '0') % 2 == 1);
        }

        return res;
    }

public:
    int numberOfBeautifulIntegers(int low, int high, int k) {
        return countBeautifulIntegers(high + 1, k) -
               countBeautifulIntegers(low, k);
    }
};