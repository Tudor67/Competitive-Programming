class Solution {
public:
    int idealArrays(int n, int maxVal) {
        const long long MODULO = 1'000'000'007;

        // At len'th iteration:
        // dp[len % 2][val]: number of distinct ideal arrays of length len
        //                   and with last value equal to val
        vector<vector<long long>> dp(2, vector<long long>(maxVal + 1));
        for(int val = 1; val <= maxVal; ++val){
            dp[1][val] = 1;
        }

        for(int len = 1; len + 1 <= n; ++len){
            vector<long long>& currDP = dp[len % 2];
            vector<long long>& nextDP = dp[(len + 1) % 2];
            fill(nextDP.begin(), nextDP.end(), 0);
            for(int currVal = 1; currVal <= maxVal; ++currVal){
                for(int nextVal = currVal; nextVal <= maxVal; nextVal += currVal){
                    nextDP[nextVal] = (nextDP[nextVal] + currDP[currVal]) % MODULO;
                }
            }
        }

        long long res = 0;
        for(int val = 1; val <= maxVal; ++val){
            res = (res + dp[n % 2][val]) % MODULO;
        }

        return res;
    }
};