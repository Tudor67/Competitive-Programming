class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        int limit = 1;
        while(limit <= MAX_NUM){
            limit *= 2;
        }

        vector<vector<bool>> dp(4, vector<bool>(limit, false));
        dp[0][0] = true;

        for(int i = 1; i <= 3; ++i){
            for(int num: nums){
                for(int prevXOR = 0; prevXOR < limit; ++prevXOR){
                    if(dp[i - 1][prevXOR]){
                        dp[i][prevXOR ^ num] = true;
                    }
                }
            }
        }

        return count(dp[3].begin(), dp[3].end(), true);
    }
};