class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int N = nums.size();
        
        // dp[i]: max score we can get when we stop at index i
        vector<int> dp(N);
        priority_queue<pair<int, int>> maxHeap;
        dp[0] = nums[0];
        maxHeap.emplace(dp[0], 0);
        for(int i = 1; i < N; ++i){
            while(!maxHeap.empty() && i - maxHeap.top().second > k){
                maxHeap.pop();
            }
            dp[i] = nums[i] + maxHeap.top().first;
            maxHeap.emplace(dp[i], i);
        }
        
        return dp[N - 1];
    }
};