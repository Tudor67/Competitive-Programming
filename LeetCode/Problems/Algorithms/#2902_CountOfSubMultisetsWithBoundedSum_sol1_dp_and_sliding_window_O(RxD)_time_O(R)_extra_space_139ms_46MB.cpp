class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        const int N = nums.size();
        const int MAX_SUM = r + 1;
        const int MODULO = 1e9 + 7;

        vector<int> f(MAX_SUM + 1);
        for(int num: nums){
            if(num <= MAX_SUM){
                f[num] += 1;
            }
        }

        vector<int> dp(MAX_SUM + 1);
        dp[0] = 1 + f[0];

        for(int num = 1; num <= MAX_SUM; ++num){
            if(f[num] == 0){
                continue;
            }
            for(int startSum = MAX_SUM; startSum > MAX_SUM - num; --startSum){
                int w = 0;
                for(int i = 1; i <= f[num] && i * num <= startSum; ++i){
                    w = (w + dp[startSum - i * num]) % MODULO;
                }
                for(int sum = startSum; sum >= num; sum -= num){
                    dp[sum] = (dp[sum] + w) % MODULO;
                    w = (w - dp[sum - num] + MODULO) % MODULO;
                    if(sum - (f[num] + 1) * num >= 0){
                        w = (w + dp[sum - (f[num] + 1) * num]) % MODULO;
                    }
                }
            }
        }

        int res = 0;
        for(int sum = l; sum <= r; ++sum){
            res = (res + dp[sum]) % MODULO;
        }

        return res;
    }
};