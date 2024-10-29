class Solution {
private:
    void add(int& a, int b, const int MODULO){
        a = (a + b) % MODULO;
    }

public:
    int sumOfPower(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;

        vector<int> pow2(N, 1);
        for(int i = 1; i < N; ++i){
            pow2[i] = pow2[i - 1] * 2 % MODULO;
        }
        
        int res = 0;
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(N + 1, 0)));

        for(int i = 0; i <= N; ++i){
            dp[0][0][i] = 1;
        }

        for(int subsetSize = 1; subsetSize <= min(k, N); ++subsetSize){
            for(int sum = 0; sum <= k; ++sum){
                for(int i = 0; i <= N; ++i){
                    dp[subsetSize % 2][sum][i] = 0;
                }
            }
            
            for(int sum = 0; sum <= k; ++sum){
                for(int i = N - 1; i >= 0; --i){
                    add(dp[subsetSize % 2][sum][i], dp[subsetSize % 2][sum][i + 1], MODULO);
                    if(sum - nums[i] >= 0){
                        add(dp[subsetSize % 2][sum][i], dp[(subsetSize - 1) % 2][sum - nums[i]][i + 1], MODULO);
                    }
                }
            }
            add(res, dp[subsetSize % 2][k][0] * (long long)pow2[N - subsetSize] % MODULO, MODULO);
        }

        return res;
    }
};