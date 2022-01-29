class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;
        
        // dp[i]: max sum of a valid subsequence ending at position i
        vector<int> dp(N);
        deque<int> mono;
        for(int i = 0; i < N; ++i){
            while(!mono.empty() && i - mono.front() > k){
                mono.pop_front();
            }
            if(mono.empty()){
                dp[i] = nums[i];
            }else{
                dp[i] = nums[i] + dp[mono.front()];
            }
            if(dp[i] > 0){
                while(!mono.empty() && dp[mono.back()] <= dp[i]){
                    mono.pop_back();
                }
                mono.push_back(i);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};