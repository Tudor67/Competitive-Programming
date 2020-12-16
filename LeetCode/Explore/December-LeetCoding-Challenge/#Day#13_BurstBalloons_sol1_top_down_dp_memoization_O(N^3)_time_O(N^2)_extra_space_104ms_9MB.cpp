class Solution {
private:
    int maxCoins(vector<int>& nums, const int& L, const int& R, vector<vector<int>>& memo){
        if(L + 1 >= R){
            return 0;
        }
        if(memo[L][R] == -1){
            for(int k = L + 1; k < R; ++k){
                int leftMaxCoins = maxCoins(nums, L, k, memo);
                int rightMaxCoins = maxCoins(nums, k, R, memo);
                memo[L][R] = max(nums[L] * nums[k] * nums[R] + leftMaxCoins + rightMaxCoins, memo[L][R]);
            }
        }
        return memo[L][R];
    }
    
public:
    int maxCoins(vector<int>& initialNums) {
        const int N = initialNums.size();
        vector<int> nums(N + 2, 1);
        copy(initialNums.begin(), initialNums.end(), nums.begin() + 1);
        vector<vector<int>> memo(N + 2, vector<int>(N + 2, -1));
        return maxCoins(nums, 0, N + 1, memo);
    }
};