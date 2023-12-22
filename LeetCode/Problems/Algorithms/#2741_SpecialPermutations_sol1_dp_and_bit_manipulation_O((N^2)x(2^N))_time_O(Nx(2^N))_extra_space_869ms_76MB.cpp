class Solution {
public:
    int specialPerm(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;
        const int MODULO = 1e9 + 7;
        
        // dp[i][mask]: number of special permutations with the last element nums[i]
        //              when we use all nums corresponding to bitmask mask
        vector<vector<int>> dp(N, vector<int>(FULL_MASK + 1));
        for(int bit = 0; bit < N; ++bit){
            dp[bit][(1 << bit)] = 1;
        }
        
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            for(int bit = 0; bit < N; ++bit){
                if((mask >> bit) & 1){
                    for(int prevBit = 0; prevBit < N; ++prevBit){
                        if((mask >> prevBit) & 1){
                            if(nums[bit] % nums[prevBit] == 0 || nums[prevBit] % nums[bit] == 0){
                                dp[bit][mask] += dp[prevBit][mask - (1 << bit)];
                                dp[bit][mask] %= MODULO;
                            }
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            res += dp[i][FULL_MASK];
            res %= MODULO;
        }
        
        return res;
    }
};