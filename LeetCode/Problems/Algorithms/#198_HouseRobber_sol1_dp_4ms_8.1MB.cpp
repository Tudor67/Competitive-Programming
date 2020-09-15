class Solution {
public:
    int rob(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        if(N == 0){
            answer = 0;
        }else if(1 <= N && N <= 2){
            answer = *max_element(nums.begin(), nums.end());
        }else{
            vector<int> dp(N);
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            for(int i = 2; i < N; ++i){
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
            }
            answer = dp[N - 1];
        }
        return answer;
    }
};