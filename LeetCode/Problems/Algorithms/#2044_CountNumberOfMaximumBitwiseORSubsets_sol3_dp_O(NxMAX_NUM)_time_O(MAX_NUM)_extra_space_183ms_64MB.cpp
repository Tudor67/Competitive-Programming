class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> dp(2 * MAX_NUM);
        dp[0] = 1;
        for(int num: nums){
            for(int orVal = 2 * MAX_NUM - 1; orVal >= 0; --orVal){
                if((orVal | num) <= 2 * MAX_NUM - 1){
                    dp[orVal | num] += dp[orVal];
                }
            }
        }

        for(int orVal = 2 * MAX_NUM - 1; orVal >= 0; --orVal){
            if(dp[orVal] >= 1){
                return dp[orVal];
            }
        }

        return 0;
    }
};