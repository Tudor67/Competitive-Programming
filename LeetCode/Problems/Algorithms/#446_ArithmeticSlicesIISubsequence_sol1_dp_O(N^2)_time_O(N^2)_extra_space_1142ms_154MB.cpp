class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        
        // dp[i][diff].first: number of pairs (nums[j], nums[i]) with j < i and (nums[i] - nums[j] == diff)
        // dp[i][diff].second: number of arithmetic subsequences with common difference == diff
        //                     and last element equal to nums[i]
        unordered_map<long long, pair<int, int>> dp[N];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                long long diff = (long long)nums[i] - nums[j];
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