class Solution {
public:
    int maxScore(vector<int>& nums) {
        const int N = nums.size();
        const int FULL_MASK = (1 << N) - 1;

        vector<vector<int>> gcdOf(N, vector<int>(N));
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                gcdOf[i][j] = gcd(nums[i], nums[j]);
            }
        }

        // dp[`mask`]: max score when we optimally pick nums from `mask`
        //             (indices of taken nums are nonZero bits of `mask`)
        vector<int> dp(FULL_MASK + 1);
        for(int mask = 0; mask <= FULL_MASK; ++mask){
            int ones = __builtin_popcount(mask);
            if(ones % 2 == 1){
                continue;
            }

            int step = ones / 2;
            for(int bit1 = 0; bit1 < N; ++bit1){
                for(int bit2 = bit1 + 1; bit2 < N; ++bit2){
                    if(!((mask >> bit1) & 1) && !((mask >> bit2) & 1)){
                        int nextStep = step + 1;
                        int nextMask = mask ^ (1 << bit1) ^ (1 << bit2);
                        dp[nextMask] = max(dp[nextMask], dp[mask] + nextStep * gcdOf[bit1][bit2]);
                    }
                }
            }
        }

        return dp[FULL_MASK];
    }
};