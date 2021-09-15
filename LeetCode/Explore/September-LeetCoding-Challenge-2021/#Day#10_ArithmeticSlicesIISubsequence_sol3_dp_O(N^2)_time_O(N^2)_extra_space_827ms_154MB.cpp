class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        int answer = 0;
        
        // dp[i][diff]: number of arithmetic subsequences (with at least 2 elements)
        //              with common difference == diff and last element equal to nums[i]
        unordered_map<long long, int> dp[N];
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < i; ++j){
                long long diff = (long long)nums[i] - nums[j];
                dp[i][diff] += 1;
                if(dp[j].count(diff)){
                    dp[i][diff] += dp[j][diff];
                    answer += dp[j][diff];
                }
            }
        }
        
        return answer;
    }
};