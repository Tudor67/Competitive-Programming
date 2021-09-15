class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        
        unordered_map<long long, pair<int, int>> dp[N];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                long long diff = (long long)nums[i] - nums[j];
                if(diff < INT_MIN || INT_MAX < diff){
                    continue;
                }
                dp[i][diff].first += 1;
                if(dp[j].count(diff)){
                    dp[i][diff].second += dp[j][diff].first;
                    dp[i][diff].second += dp[j][diff].second;
                    answer += dp[j][diff].first;
                    answer += dp[j][diff].second;
                }
            }
        }
        
        return answer;
    }
};