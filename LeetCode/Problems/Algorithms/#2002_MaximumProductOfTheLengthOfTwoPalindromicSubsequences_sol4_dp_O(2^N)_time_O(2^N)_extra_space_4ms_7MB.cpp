class Solution {
public:
    int maxProduct(string s) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;
        
        // dp[mask]: max length of a palindromic subsequence with indices from a subset of mask
        vector<int> dp(FULL_MASK + 1, 0);
        for(int mask = 1; mask < FULL_MASK; ++mask){
            int msb1 = 31 - __builtin_clz((unsigned int)mask);
            int lsb1 = __builtin_ctz((unsigned int)mask);
            if(msb1 == lsb1){
                dp[mask] = 1;
            }else if(s[msb1] == s[lsb1]){
                dp[mask] = 2 + dp[mask ^ (1 << msb1) ^ (1 << lsb1)];
            }else{
                dp[mask] = max(dp[mask ^ (1 << msb1)], dp[mask ^ (1 << lsb1)]);
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