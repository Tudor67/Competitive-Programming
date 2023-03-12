class Solution {
public:
    int minOperations(int n) {
        const int BITS = log2(n) + 1;

        string s(BITS, '0');
        for(int bit = 0; bit < BITS; ++bit){
            if((n >> bit) & 1){
                s[bit] = '1';
            }
        }

        // dp[i]: min cost to make bits [0 .. i] of n equal to zero
        vector<int> dp(BITS, BITS + 5);
        for(int i = 0; i < BITS; ++i){
            int zeros = 0;
            int ones = 0;
            for(int j = i; j >= 0; --j){
                zeros += (int)(s[j] == '0');
                ones += (int)(s[j] == '1');

                int currentCost = min(zeros + 2, ones);
                if(j - 1 >= 0){
                    currentCost += dp[j - 1];
                }

                dp[i] = min(dp[i], currentCost);
            }
        }

        return dp[BITS - 1];
    }
};