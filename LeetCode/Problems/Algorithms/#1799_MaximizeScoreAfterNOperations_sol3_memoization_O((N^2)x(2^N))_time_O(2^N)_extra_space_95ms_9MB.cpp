class Solution {
private:
    int solve(int step, int mask, vector<int>& nums, vector<vector<int>>& gcdOf, vector<int>& memo){
        const int N = nums.size();

        if(step == 0){
            return 0;
        }

        if(memo[mask] != -1){
            return memo[mask];
        }

        int res = 0;
        for(int bit1 = 0; bit1 < N; ++bit1){
            for(int bit2 = bit1 + 1; bit2 < N; ++bit2){
                if(((mask >> bit1) & 1) && ((mask >> bit2) & 1)){
                    int score = step * gcdOf[bit1][bit2] +
                                solve(step - 1, mask ^ (1 << bit1) ^ (1 << bit2), nums, gcdOf, memo);
                    res = max(res, score);
                }
            }
        }

        memo[mask] = res;
        return res;
    }

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

        vector<int> memo(FULL_MASK + 1, -1);
        return solve(N / 2, FULL_MASK, nums, gcdOf, memo);
    }
};