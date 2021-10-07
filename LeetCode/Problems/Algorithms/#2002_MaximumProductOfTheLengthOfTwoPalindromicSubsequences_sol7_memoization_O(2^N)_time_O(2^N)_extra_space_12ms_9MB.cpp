class Solution {
private:
    int solve(const string& S, int mask, vector<int>& msb1, vector<int>& lsb1, vector<int>& dp){
        if(mask == 0){
            return 0;
        }
        if((mask & (mask - 1)) == 0){
            return 1;
        }
        if(dp[mask] == -1){
            if(S[msb1[mask]] == S[lsb1[mask]]){
                dp[mask] = 2 + solve(S, mask ^ (1 << msb1[mask]) ^ (1 << lsb1[mask]), msb1, lsb1, dp);
            }else{
                dp[mask] = max(solve(S, mask ^ (1 << msb1[mask]), msb1, lsb1, dp),
                               solve(S, mask ^ (1 << lsb1[mask]), msb1, lsb1, dp));
            }
        }
        return dp[mask];
    }
    
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
        vector<int> dp(FULL_MASK + 1, -1);
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            dp[mask] = solve(s, mask, msb1, lsb1, dp);
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