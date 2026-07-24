class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

public:
    int subsequencePairCount(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MODULO = 1'000'000'007;

        vector<vector<vector<int>>> dp(N, vector<vector<int>>(MAX_NUM + 1, vector<int>(MAX_NUM + 1)));
        dp[0][0][0] = 1;
        dp[0][0][nums[0]] = 1;
        dp[0][nums[0]][0] = 1;

        for(int i = 1; i < N; ++i){
            for(int g1 = 0; g1 <= MAX_NUM; ++g1){
                for(int g2 = 0; g2 <= MAX_NUM; ++g2){
                    add(dp[i][g1][g2], dp[i - 1][g1][g2], MODULO);
                    add(dp[i][gcd(nums[i], g1)][g2], dp[i - 1][g1][g2], MODULO);
                    add(dp[i][g1][gcd(nums[i], g2)], dp[i - 1][g1][g2], MODULO);
                }
            }
        }

        int res = 0;
        for(int g = 1; g <= MAX_NUM; ++g){
            add(res, dp[N - 1][g][g], MODULO);
        }

        return res;
    }
};