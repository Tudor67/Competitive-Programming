class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        
        // dp[i]: max score we can get when we stop at index i
        vector<int> dp(N);
        deque<int> monoDQ;
        dp[0] = nums[0];
        monoDQ.push_back(0);
        for(int i = 1; i < N; ++i){
            while(!monoDQ.empty() && i - monoDQ.front() > k){
                monoDQ.pop_front();
            }
            dp[i] = nums[i] + dp[monoDQ.front()];
            while(!monoDQ.empty() && dp[monoDQ.back()] <= dp[i]){
                monoDQ.pop_back();
            }
            monoDQ.push_back(i);
        }
        
        return dp[N - 1];
    }
};