class Solution {
private:
    int f(int i, int sum, vector<int>& nums, const int MODULO, vector<vector<int>>& memo){
        if(sum < 0){
            return 0;
        }
        if(i >= (int)nums.size()){
            return (int)(sum == 0);
        }
        if(memo[i][sum] == -1){
            int opt0 = 2 * f(i + 1, sum, nums, MODULO, memo) % MODULO;
            int opt1 = f(i + 1, sum - nums[i], nums, MODULO, memo);
            memo[i][sum] = (opt0 + opt1) % MODULO;
        }
        return memo[i][sum];
    }

public:
    int sumOfPower(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MODULO = 1'000'000'007;
        vector<vector<int>> memo(N, vector<int>(k + 1, -1));
        return f(0, k, nums, MODULO, memo);
    }
};