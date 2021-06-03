class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        
        if(N == 0){
            answer = 0;
        }else if(1 <= N && N <= 3){
            answer = *max_element(nums.begin(), nums.end());
        }else{
            const int WITHOUT_FIRST_HOUSE = 0;
            const int WITH_FIRST_HOUSE = 1;
            vector<vector<int>> dp(N, vector<int>(2));
            
            // dp[i][WITHOUT_FIRST_HOUSE] = max amount of money at step i (if we do not rob the first house)
            // dp[i][WITH_FIRST_HOUSE]    = max amount of money at step i (if we rob the first house)
            dp[0][WITHOUT_FIRST_HOUSE] = 0;
            dp[0][WITH_FIRST_HOUSE] = nums[0];
            dp[1][WITHOUT_FIRST_HOUSE] = nums[1];
            dp[1][WITH_FIRST_HOUSE] = nums[0];
            dp[2][WITHOUT_FIRST_HOUSE] = max(nums[1], nums[2]);
            dp[2][WITH_FIRST_HOUSE] = nums[0] + nums[2];
            
            for(int i = 3; i < N; ++i){
                dp[i][WITHOUT_FIRST_HOUSE] = max(dp[i - 2][WITHOUT_FIRST_HOUSE] + nums[i], dp[i - 1][WITHOUT_FIRST_HOUSE]);
                if(i < N - 1){
                    dp[i][WITH_FIRST_HOUSE] = max(dp[i - 2][WITH_FIRST_HOUSE] + nums[i], dp[i - 1][WITH_FIRST_HOUSE]);
                }
            }
            
            answer = max(dp[N - 1][WITHOUT_FIRST_HOUSE], dp[N - 2][WITH_FIRST_HOUSE]);
        }
        
        return answer;
    }
};