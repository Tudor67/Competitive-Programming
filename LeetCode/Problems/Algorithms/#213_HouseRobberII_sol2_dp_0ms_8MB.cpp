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
            vector<int> dp(N);
            // 1st case: we can rob the first house
            dp[0] = nums[0];
            dp[1] = max(dp[0], nums[1]);
            dp[2] = max(dp[0] + nums[2], dp[1]);
            for(int i = 3; i <= N - 2; ++i){
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }
            answer = max(dp[N - 2], answer);
            
            // 2nd case: we cannot rob the first house
            dp[0] = 0;
            dp[1] = max(dp[0], nums[1]);
            dp[2] = max(dp[0] + nums[2], dp[1]);
            for(int i = 3; i <= N - 1; ++i){
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }    
            answer = max(dp[N - 1], answer);
        }
        
        return answer;
    }
};