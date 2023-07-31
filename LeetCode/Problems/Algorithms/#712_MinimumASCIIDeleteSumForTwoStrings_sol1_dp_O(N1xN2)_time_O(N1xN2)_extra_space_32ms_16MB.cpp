class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        const int N1 = s1.length();
        const int N2 = s2.length();

        // dp[i1][i2]: min cost to make s1[i1 .. ] and s2[i2 .. ] equal
        vector<vector<int>> dp(N1 + 1, vector<int>(N2 + 1));
        for(int i1 = N1 - 1; i1 >= 0; --i1){
            dp[i1][N2] = (int)s1[i1] + dp[i1 + 1][N2];
        }

        for(int i2 = N2 - 1; i2 >= 0; --i2){
            dp[N1][i2] = (int)s2[i2] + dp[N1][i2 + 1];
        }

        for(int i1 = N1 - 1; i1 >= 0; --i1){
            for(int i2 = N2 - 1; i2 >= 0; --i2){
                if(s1[i1] == s2[i2]){
                    dp[i1][i2] = dp[i1 + 1][i2 + 1];
                }else{
                    dp[i1][i2] = min((int)s1[i1] + dp[i1 + 1][i2],
                                     (int)s2[i2] + dp[i1][i2 + 1]);
                }
            }
        }

        return dp[0][0];
    }
};