class Solution {
private:
    int f(int i, int sum, int subsetSize, vector<int>& nums, const int MODULO, vector<vector<vector<int>>>& memo){
        if(i >= (int)nums.size()){
            return (sum == 0 && subsetSize == 0);
        }

        if(sum <= 0 || subsetSize <= 0){
            return (sum == 0 && subsetSize == 0);
        }

        if(memo[i][sum][subsetSize] == -1){
            int opt0 = f(i + 1, sum, subsetSize, nums, MODULO, memo);
            int opt1 = f(i + 1, sum - nums[i], subsetSize - 1, nums, MODULO, memo);
            memo[i][sum][subsetSize] = (opt0 + opt1) % MODULO;
        }

        return memo[i][sum][subsetSize];
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
        vector<vector<vector<int>>> memo(N, vector<vector<int>>(k + 1, vector<int>(min(k, N) + 1, -1)));
        for(int subsetSize = 1; subsetSize <= min(k, N); ++subsetSize){
            res += f(0, k, subsetSize, nums, MODULO, memo) * (long long)pow2[N - subsetSize] % MODULO;
            res %= MODULO;
        }

        return res;
    }
};