class Solution {
private:
    int solve(const string& S, int mask, vector<int>& dp){
        if(mask == 0){
            return 0;
        }
        if((mask & (mask - 1)) == 0){
            return 1;
        }
        if(dp[mask] == -1){
            int msb1 = 31 - __builtin_clz((unsigned int)mask);
            int lsb1 = __builtin_ctz((unsigned int)mask);
            if(S[msb1] == S[lsb1]){
                dp[mask] = 2 + solve(S, mask ^ (1 << msb1) ^ (1 << lsb1), dp);
            }else{
                dp[mask] = max(solve(S, mask ^ (1 << msb1), dp),
                               solve(S, mask ^ (1 << lsb1), dp));
            }
        }
        return dp[mask];
    }
    
public:
    int maxProduct(string s) {
        const int N = s.length();
        const int FULL_MASK = (1 << N) - 1;
        
        // dp[mask]: max length of a palindromic subsequence with indices from a subset of mask
        vector<int> dp(FULL_MASK + 1, -1);
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            dp[mask] = solve(s, mask, dp);
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