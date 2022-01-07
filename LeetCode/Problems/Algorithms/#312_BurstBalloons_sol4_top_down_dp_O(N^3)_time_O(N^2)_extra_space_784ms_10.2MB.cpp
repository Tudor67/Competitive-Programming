class Solution {
private:
    int computeMaxCoins(int l, int r, vector<int>& nums, vector<vector<int>>& memo){
        const int N = nums.size();
        if(l > r){
            return 0;
        }else if(memo[l][r] == -1){
            int maxCoins = 0;
            for(int i = l; i <= r; ++i){
                int lastCoins = nums[i];
                if(l - 1 >= 0){
                    lastCoins *= nums[l - 1];
                }
                if(r + 1 <= N - 1){
                    lastCoins *= nums[r + 1];
                }
                int leftMaxCoins = computeMaxCoins(l, i - 1, nums, memo);
                int rightMaxCoins = computeMaxCoins(i + 1, r, nums, memo);
                maxCoins = max(maxCoins, leftMaxCoins + rightMaxCoins + lastCoins);
            }
            memo[l][r] = maxCoins;
        }
        return memo[l][r];
    }
    
public:
    int maxCoins(vector<int>& nums) {
        const int N = nums.size();
        // memo[l][r]: max coins we can collect from range [l .. r]
        // memo[l][r] = max(memo[l][r], memo[l][i - 1] + memo[i + 1][r] + nums[l - 1] * nums[i] * nums[r + 1])
        //              with l <= i <= r and nums[-1] == nums[N] == 1
        vector<vector<int>> memo(N, vector<int>(N, -1));
        return computeMaxCoins(0, N - 1, nums, memo);
    }
};