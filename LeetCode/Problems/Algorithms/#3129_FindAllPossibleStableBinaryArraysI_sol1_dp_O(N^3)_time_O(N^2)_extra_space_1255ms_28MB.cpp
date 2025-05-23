class Solution {
public:
    int numberOfStableArrays(int zeros, int ones, int limit) {
        const int N = zeros + ones;
        const int MODULO = 1'000'000'007;

        auto add = [&](int& a, int b) -> void {
            a = (a + b) % MODULO;
        };

        vector<vector<vector<int>>> dp0(2, vector<vector<int>>(min(limit, zeros) + 1, vector<int>(zeros + 1)));
        vector<vector<vector<int>>> dp1(2, vector<vector<int>>(min(limit, ones) + 1, vector<int>(ones + 1)));
        dp0[1][1][1] = 1;
        dp1[1][1][1] = 1;

        for(int len = 1; len + 1 <= N; ++len){
            for(int consZeros = 0; consZeros <= min({len + 1, limit, zeros}); ++consZeros){
                for(int totalZeros = 0; totalZeros <= min(len + 1, zeros); ++totalZeros){
                    dp0[(len + 1) % 2][consZeros][totalZeros] = 0;
                }
            }

            for(int consOnes = 0; consOnes <= min({len + 1, limit, ones}); ++consOnes){
                for(int totalOnes = 0; totalOnes <= min(len + 1, ones); ++totalOnes){
                    dp1[(len + 1) % 2][consOnes][totalOnes] = 0;
                }
            }

            for(int consZeros = 0; consZeros <= min({len, limit, zeros}); ++consZeros){
                for(int totalZeros = consZeros; totalZeros <= min(len, zeros); ++totalZeros){
                    if(consZeros + 1 <= min(limit, zeros) && totalZeros + 1 <= zeros){
                        add(dp0[(len + 1) % 2][consZeros + 1][totalZeros + 1], dp0[len % 2][consZeros][totalZeros]);
                    }
                    if(len + 1 - totalZeros <= ones){
                        add(dp1[(len + 1) % 2][1][len + 1 - totalZeros], dp0[len % 2][consZeros][totalZeros]);
                    }
                }
            }

            for(int consOnes = 0; consOnes <= min({len, limit, ones}); ++consOnes){
                for(int totalOnes = consOnes; totalOnes <= min(len, ones); ++totalOnes){
                    if(consOnes + 1 <= min(limit, ones) && totalOnes + 1 <= ones){
                        add(dp1[(len + 1) % 2][consOnes + 1][totalOnes + 1], dp1[len % 2][consOnes][totalOnes]);
                    }
                    if(len + 1 - totalOnes <= zeros){
                        add(dp0[(len + 1) % 2][1][len + 1 - totalOnes], dp1[len % 2][consOnes][totalOnes]);
                    }
                }
            }
        }

        int res = 0;
        for(int consZeros = 1; consZeros <= min(limit, zeros); ++consZeros){
            add(res, dp0[N % 2][consZeros][zeros]);
        }

        for(int consOnes = 1; consOnes <= min(limit, ones); ++consOnes){
            add(res, dp1[N % 2][consOnes][ones]);
        }

        return res;
    }
};