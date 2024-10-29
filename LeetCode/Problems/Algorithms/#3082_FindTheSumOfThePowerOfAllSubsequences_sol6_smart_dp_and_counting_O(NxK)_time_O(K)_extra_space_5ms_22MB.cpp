class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

public:
    int sumOfPower(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        vector<vector<int>> dp(2, vector<int>(k + 1));
        dp[N % 2][0] = 1;
        for(int i = N - 1; i >= 0; --i){
            fill(dp[i % 2].begin(), dp[i % 2].end(), 0);
            for(int sum = 0; sum <= k; ++sum){
                add(dp[i % 2][sum], 2 * dp[(i + 1) % 2][sum] % MODULO, MODULO);
                if(sum - nums[i] >= 0){
                    add(dp[i % 2][sum], dp[(i + 1) % 2][sum - nums[i]], MODULO);
                }
            }
        }

        return dp[0][k];
    }
};