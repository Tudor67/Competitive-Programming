class Solution {
public:
    int maxProduct(string s) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;
        
        vector<int> msb1(FULL_MASK + 1, 0);
        vector<int> lsb1(FULL_MASK + 1, 0);
        for(int mask = 2; mask <= FULL_MASK; ++mask){
            msb1[mask] = 1 + msb1[mask >> 1];
            if(mask % 2 == 0){
                lsb1[mask] = 1 + lsb1[mask >> 1];
            }
        }
        
        // dp[mask]: max length of a palindromic subsequence with indices from a subset of mask
        vector<int> dp(FULL_MASK + 1, 0);
        for(int mask = 1; mask < FULL_MASK; ++mask){
            if(msb1[mask] == lsb1[mask]){
                dp[mask] = 1;
            }else if(s[msb1[mask]] == s[lsb1[mask]]){
                dp[mask] = 2 + dp[mask ^ (1 << msb1[mask]) ^ (1 << lsb1[mask])];
            }else{
                dp[mask] = max(dp[mask ^ (1 << msb1[mask])], dp[mask ^ (1 << lsb1[mask])]);
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