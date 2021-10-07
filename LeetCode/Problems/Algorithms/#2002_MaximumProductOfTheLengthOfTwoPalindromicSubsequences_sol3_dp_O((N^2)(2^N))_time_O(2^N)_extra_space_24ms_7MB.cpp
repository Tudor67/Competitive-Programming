class Solution {
public:
    int maxProduct(string s) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;
        
        // dp[mask]: max length of a palindromic subsequence with indices from a subset of mask
        vector<int> dp(FULL_MASK + 1);
        for(int bit1 = 0; bit1 < N; ++bit1){
            for(int bit2 = bit1; bit2 < N; ++bit2){
                if(s[bit1] == s[bit2]){
                    dp[(1 << bit1) | (1 << bit2)] = 2 - (int)(bit1 == bit2);
                }
            }
        }
        
        for(int mask = 1; mask < FULL_MASK; ++mask){
            for(int bit = 0; bit < N; ++bit){
                int nextMask = mask | (1 << bit);
                dp[nextMask] = max(dp[nextMask], dp[mask]);
            }
            int msb1 = 31 - __builtin_clz((unsigned int)mask);
            int lsb1 = __builtin_ctz((unsigned int)mask);
            for(int bit1 = N - 1; bit1 > msb1; --bit1){
                for(int bit2 = lsb1 - 1; bit2 >= 0; --bit2){
                    int nextMask = mask | (1 << bit1) | (1 << bit2);
                    dp[nextMask] = max(dp[nextMask], 2 * (int)(s[bit1] == s[bit2]) + dp[mask]);
                }
            }
        }
        
        int maxProduct = 0;
        for(int mask = 1; mask < FULL_MASK; ++mask){
            int maskComplement = mask ^ FULL_MASK;
            int product = dp[mask] * dp[maskComplement];
            maxProduct = max(maxProduct, product);
        }
        
        return maxProduct;
    }
};