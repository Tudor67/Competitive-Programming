class Solution {
private:
    int maxMoney(const vector<int>& NUMS, const int& START_POS, const int& END_POS){
        vector<int> dp(END_POS + 1);
        dp[START_POS] = NUMS[START_POS];
        for(int i = START_POS + 1; i <= END_POS; ++i){
            dp[i] = max(dp[i - 1], NUMS[i] + (i >= 2 ? dp[i - 2] : 0));
        }
        return dp[END_POS];
    }
    
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();
        if(N <= 3){
            return *max_element(nums.begin(), nums.end());
        }
        return max(maxMoney(nums, 0, N - 2), maxMoney(nums, 1, N - 1));
    }
};