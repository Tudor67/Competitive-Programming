class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a += b;
        a %= MODULO;
    }

public:
    int checkRecord(int N) {
        const int MODULO = 1e9 + 7;

        // dp[a][l][n]: number of possible attendance records of length n
        //              containing a chars equal to 'A' (Absent) and
        //              ending in l consecutive chars equal to 'L' (Late)
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(3, vector<int>(N + 1)));
        dp[1][0][1] = 1; // "A"
        dp[0][1][1] = 1; // "L"
        dp[0][0][1] = 1; // "P"

        for(int len = 1; len + 1 <= N; ++len){
            for(int a = 0; a <= 1; ++a){
                for(int l = 0; l <= 2; ++l){
                    if(a + 1 <= 1){
                        add(dp[a + 1][0][len + 1], dp[a][l][len], MODULO);
                    }
                    if(l + 1 <= 2){
                        add(dp[a][l + 1][len + 1], dp[a][l][len], MODULO);
                    }
                    add(dp[a][0][len + 1], dp[a][l][len], MODULO);
                }
            }
        }

        int res = 0;
        for(int a = 0; a <= 1; ++a){
            for(int l = 0; l <= 2; ++l){
                res += dp[a][l][N];
                res %= MODULO;
            }
        }

        return res;
    }
};